#import "Tweak.h"
#import "App-Headers/B2World.h"

// Show the game's custom alert view
void showAlert(NSString *message, NSString *buttonText) {
	HSAlertView *delegate = [[%c(HSAlertView) alloc] init]; 
	HSAlertView *alertView = [[%c(HSAlertView) alloc] initWithTitle:@"ReBoom" message:message delegate:delegate cancelButtonTitle:buttonText otherButtonTitles:nil];
	[alertView show];
}

// Get pref value
inline BOOL GetPrefBool(NSString *key) {
	NSString *path = [NSString stringWithFormat:@"%@/!prefs.plist", [[[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject] path]];

	// Create file if it doesn't exist
	if (![[NSFileManager defaultManager] fileExistsAtPath:path]) {
		[[NSFileManager defaultManager] createFileAtPath:path contents:nil attributes:nil];
	}

	// Load prefs from file
	NSMutableDictionary *prefsDict = [NSMutableDictionary dictionary];
	[prefsDict addEntriesFromDictionary:[NSDictionary dictionaryWithContentsOfFile:path]];
	//we should set icloudItem to true by default
	// If key doesn't exist, set it to false ("disabled")
	if (![[prefsDict allKeys] containsObject:key]) {
		[prefsDict setValue:@(NO) forKey:key];
		[prefsDict writeToFile:path atomically:YES];
		return GetPrefBool(key);
	}

	// Get the value for the key
	NSString *value = [prefsDict valueForKey:key];

	// If there is no value, set it to false ("disabled")
	if (!value) {
		[prefsDict setValue:@(NO) forKey:key];
		[prefsDict writeToFile:path atomically:YES];
		return GetPrefBool(key);
	}

	return [value boolValue];
}

// Set pref value
inline void SetPrefBool(NSString *key, BOOL value) {
	NSString *path = [NSString stringWithFormat:@"%@/!prefs.plist", [[[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject] path]];
	NSMutableDictionary *prefsDict = [NSMutableDictionary dictionary];
	[prefsDict addEntriesFromDictionary:[NSDictionary dictionaryWithContentsOfFile:path]];
	[prefsDict setObject:(value ? @"YES" : @"NO") forKey:key];
	[prefsDict writeToFile:path atomically:YES];
}

// Load TAS recording
void loadMovie(NSString *name) {
	if (LOGS_ENABLED) NSLog(@"[ReBoom] Loading TAS recording with name: %@", name);
	tas.length = 0;
	tas.commands = [[NSMutableArray alloc] init];

	NSString *path = [NSString stringWithFormat:@"%@/%@%@", [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject].path, name, TAS_EXT];
	if (![[NSFileManager defaultManager] fileExistsAtPath:path]) {
		if (LOGS_ENABLED) NSLog(@"TAS recording file not found at path: %@", path);
		return;
	}
	if (LOGS_ENABLED) NSLog(@"TAS recording file found at path: %@", path);

	NSString *fileContent = [[NSString alloc] initWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
	NSArray *lines = [fileContent componentsSeparatedByString:@"\n"];

	static NSString *strEmpty = [NSString string];
	NSMutableString *strBuffer = [NSMutableString string];

	for (int i = 0; i < [lines count]; i++) {
		if (![lines[i] isEqual:@""] && ![[lines[i] substringWithRange:NSMakeRange(0, 1)] isEqual:@"#"]) {
			NSArray *sides = [lines[i] componentsSeparatedByString:@":"];
			int frame = [sides[0] intValue];

			[strBuffer setString:@""];
			NSArray *commands = [sides[1] componentsSeparatedByString:@" "];
			for (int ii = 0; ii < [commands count]; ii++) {
				if ([commands[ii] length] > 1) {
					if ([commands[ii] isEqual:@"rd"]) [strBuffer appendString:@"r"];
					else if ([commands[ii] isEqual:@"ru"]) [strBuffer appendString:@"R"];
					else if ([commands[ii] isEqual:@"ld"]) [strBuffer appendString:@"l"];
					else if ([commands[ii] isEqual:@"lu"]) [strBuffer appendString:@"L"];
					else if ([commands[ii] isEqual:@"***"]) [strBuffer appendString:@"*"];
					else if ([commands[ii] isEqual:@"log"]) [strBuffer appendString:@"p"];
				}
			}

			for (int ii = tas.length; ii < frame - 1; ii++) [tas.commands addObject:strEmpty];

			[tas.commands addObject:[NSString stringWithString:strBuffer]];
			tas.length = frame;
		}
	}

	[fileContent release];
}

// Save TAS recording
void saveRecording(NSString *name) {
	NSURL *path = [NSURL URLWithString: [NSString stringWithFormat:@"%@%@%@", [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject], name, TAS_EXT]];
	[recording writeToURL:path atomically:NO encoding:NSASCIIStringEncoding error:NULL];

	if (LOGS_ENABLED) NSLog(@"Saved to %@!", path);

	showAlert(@"TAS recording has been saved!", @"Dismiss");
}

// Pause Bug
%hook TrialSession
-(void)pauseSchedulerAndActionsRecursive:(id)a {
	if (!GetPrefBool(@"PauseBug")) %orig; 
}
-(void)resumeSchedulerAndActionsRecursive:(id)a {
	if (!GetPrefBool(@"PauseBug")) %orig; 
}
%end

//Zero Gravity
%hook LevelHelperLoader
//-(void)createGravity:(b2World*)gravity;
-(void)createGravity:(b2World*)gravity{
	if(!GetPrefBool(@"ZeroGrav")) %orig; 
}
%end

// Fixed Delta & TAS
%hook CCScheduler
-(void)update:(float)a {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook CCDirector
-(BOOL)useFixedTimestep {
	return GetPrefBool(@"FixedDelta") ? YES : %orig;
}
%end
%hook Object156
-(void)postUpdate:(float)a {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook Bomb
-(void)postUpdate:(float)a {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook TrialGameController
-(void)update:(float)a {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook TrialLayer
-(void)update:(float)a {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end

// TAS & Unlocks
%hook TrialSession
-(void)restartLevel {
	%orig;
	if (LOGS_ENABLED) NSLog(@"[ReBoom] Restarting level...");
	[self start_reboom];
}

-(void)onEnter {
	%orig;
	if (LOGS_ENABLED) NSLog(@"[ReBoom] Starting level...");
	[self start_reboom];
}

%new
-(void)start_reboom {
	if (LOGS_ENABLED) NSLog(@"[ReBoom] [TrialSession start_reboom] called");

	// unlock next level
	if (GetPrefBool(@"EverythingUnlocked")) [[%c(LevelHandler) sharedInstance] unLockNextLevel];

	// replay mode
	if (GetPrefBool(@"TASMode") && ![self isChallenge] && ![self isTournament]) {
		if (LOGS_ENABLED) NSLog(@"[ReBoom] [TrialSession restartLevel] loading TAS recording...");
		loadMovie([self levelId]);
	}

	// record mode
	if (GetPrefBool(@"RecordMode")) {
		if (recording == NULL) recording = [[NSMutableString alloc] init];
		else [recording setString:@""];
	}

	frameID = 0;
	lastFrameID = 0;
	autoLeft = false;
	autoRight = false;
	autoRelease = false;
}

-(void)update:(float)a {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;

	// Spam taps in the direction of the last button you pressed
	if (GetPrefBool(@"AutoTAS") && ![self isChallenge] && ![self isTournament]){
// 		if([LevelHelperLoader isPaused]){
// 			autoLeft, autoRight, autoRelease = false;
// 		}
// 		else {
			if(autoRight){

				if(autoRelease) {
					[self stopLeft];
					[self stopRight];
					//NSLog(@"[self stopRight] stopRight called");
				}
				else {
					[self right];
					//NSLog(@"[self right] right called");
				}
			}
			else if(autoLeft){

				if(autoRelease){
					[self stopRight];
					[self stopLeft];
					//NSLog(@"[self stopLeft] stopLeft called");
				}
				else{
					[self left];
					//NSLog(@"[self left] left called");
				}
			}
			autoRelease = !autoRelease;
// 		}
	}

	if (GetPrefBool(@"TASMode") && ![self isChallenge] && ![self isTournament]) {
		if (tas.length > 0 && frameID < tas.length && [tas.commands[frameID] length] > 0) {
			const NSString *list = tas.commands[frameID];
			
			for (int i = 0; i < [list length]; i++) {
				switch([list characterAtIndex:i]) {
					case 'r':
						[self right];
						break;
					case 'R':
						[self stopRight];
						break;
					case 'l':
						[self left];
						break;
					case 'L':
						[self stopLeft];
						break;
					case '*':
						[self pause];
						break;
					case 'p':
						const CGPoint pos = [((CALayer *)[self wheely]) position];
						CGPoint vel;
						MSG0S(CGPoint*, &vel, [self wheely], Object88);

						if (LOGS_ENABLED) NSLog(@"\n[%04lu]\nPosition\n\tX: %f\n\tY: %f\nVelocity\n\tM: %f\n\tX: %f\n\tY: %f", frameID + 1, pos.x, pos.y, sqrtf(powf(vel.x, 2) + powf(vel.y, 2)), vel.x, vel.y);
						break;
				}
			}
		}
	}

	frameID++;
}

// on win
-(void)goal:(float)a {
	if (LOGS_ENABLED) NSLog(@"[TrialSession goal] called");
	if (GetPrefBool(@"RecordMode") && recording != NULL && ![recording isEqual:@""]) {
		if (LOGS_ENABLED) NSLog(@"[TrialSession goal] saving...");
		
		HSAlertView *delegate = [[%c(HSAlertView) alloc] init]; 
		HSAlertView *alertView = [[%c(HSAlertView) alloc] initWithTitle:@"ReBoom" message:@"Would you like to save the TAS recording?" delegate:delegate cancelButtonTitle:@"No" otherButtonTitles:@"Yes", nil];
		[alertView show];
	}

	%orig;
}

// when player taps right
-(void)right {
	autoLeft = false;
	%orig;
	if (GetPrefBool(@"RecordMode") && recording != NULL) {
		if (LOGS_ENABLED) NSLog(@"[TrialSession right] called with record mode on");
		if (lastFrameID < frameID + 1) {
			if (LOGS_ENABLED) NSLog(@"[TrialSession right] appending");
			[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
			lastFrameID = frameID + 1;
		}

		[recording appendString:@" rd"];
	}
}

// when player taps left
-(void)left {
	autoRight = false;
	%orig;
	if (GetPrefBool(@"RecordMode") && recording != NULL) {
		if (LOGS_ENABLED) NSLog(@"[TrialSession left] called with record mode on");
		if (lastFrameID < frameID + 1) {
			if (LOGS_ENABLED) NSLog(@"[TrialSession left] appending");
			[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
			lastFrameID = frameID + 1;
		}

		[recording appendString:@" ld"];
	}
}

// when player releases right
-(void)stopRight {
	autoRight = true;
	autoLeft = false;
// 	autoRelease = false;
	%orig;
	if (GetPrefBool(@"RecordMode") && recording != NULL) {
		if (LOGS_ENABLED) NSLog(@"[TrialSession stopRight] called with record mode on");
			if (lastFrameID < frameID + 1) {
				if (LOGS_ENABLED) NSLog(@"[TrialSession stopRight] appending");
				[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
				lastFrameID = frameID + 1;
			}

			[recording appendString:@" ru"];
	}
}

// when player releases left
-(void)stopLeft {
	autoLeft = true;
	autoRight = false;
// 	autoRelease = false;
	%orig;
	if (GetPrefBool(@"RecordMode") && recording != NULL) {
		if (LOGS_ENABLED) NSLog(@"[TrialSession stopLeft] called with record mode on");
			if (lastFrameID < frameID + 1) {
				if (LOGS_ENABLED) NSLog(@"[TrialSession stopLeft] appending");
				[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
				lastFrameID = frameID + 1;
			}

			[recording appendString:@" lu"];
	}
}
%end

// Encryption
%hook HSAppSecurity
+(id)AES256Encrypt:(id)toEncrypt withKey:(id)key salt:(id)salt {
	if (GetPrefBool(@"LogRequest")) NSLog(@"%@", [[NSString alloc] initWithData:toEncrypt encoding:NSUTF8StringEncoding]);
	return GetPrefBool(@"DisableEncryption") ? toEncrypt : %orig;
}
+(id)AES256Decrypt:(id)toDecrypt withKey:(id)key salt:(id)salt {
	id result = %orig;
	if (GetPrefBool(@"LogResponse")) NSLog(@"Decrypted with key %@ and salt %@:\n%@", key, salt, [[NSString alloc] initWithData:result encoding:NSUTF8StringEncoding]);
	return result;
}
%end

%hook HSRequestSecurity
+(id)request:(id)a path:(id)path parameters:(id)params secureString:(id)d post:(BOOL)e secretKey:(id)f result:(id)g progress:(id)h timeout:(id)i packetSize:(id)j packetDelay:(double)k {
	if (GetPrefBool(@"LogRequest")) NSLog(@"Sent request to %@...", path);
	return %orig;
}
%end

// Disable checksums
%hook Checksums
+(BOOL)verify_file:(id)file {
	return GetPrefBool(@"DisableChecksums") ? YES : %orig;
}
%end

// Unlock Everything
%hook Player
-(BOOL)hasItem:(id)item id:(id)anId {
	return GetPrefBool(@"EverythingUnlocked") ? YES : %orig;
}
%end

// Disable iCloud
%hook Player
-(BOOL)switchToICloudPlayer:(id)icloudPlayer {
	return GetPrefBool(@"DisableICloud") ? NO : %orig;
}
%end



/*  IN-GAME PREFS */

SettingsItem *replayItem;
SettingsItem *recordItem;

%hook Settings
-(NSInteger) numberOfSectionsInTableView:(UITableView*)tableView {
	// Tell the game how many sections we'll have
	return 4;
}

-(int)tableView:(id)view numberOfRowsInSection:(int)section {
	// Tell the game how many rows we have in our custom sections
	int ret = %orig;
	if (section == 1) ret = 4;
	else if (section == 2) ret = 4;
	else if (section == 3) ret = 4;
	return ret;
}

-(id)tableView:(id)view cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	// Loop through each section (0 is the game's regular settings)
	switch (indexPath.section) {
		case 1:
			switch (indexPath.row) {
				case 0:
					SettingsItem *pauseItem;
					pauseItem = [%c(SettingsItem) itemWithTitle:@"Pause Bug" value:(GetPrefBool(@"PauseBug") ? @"Enabled" : @"Disabled") type:1];
					pauseItem.ReBoom_PrefValue = @"PauseBug";
					return pauseItem;
				case 1:
					SettingsItem *gravityItem;
					gravityItem = [%c(SettingsItem) itemWithTitle:@"Zero Gravity" value:(GetPrefBool(@"ZeroGrav") ? @"Enabled" : @"Disabled") type:1];
					gravityItem.ReBoom_PrefValue = @"ZeroGrav";
					return gravityItem;
				case 2:
					SettingsItem *unlockItem;
					unlockItem = [%c(SettingsItem) itemWithTitle:@"Everything Unlocked" value:(GetPrefBool(@"EverythingUnlocked") ? @"Enabled" : @"Disabled") type:1];
					unlockItem.ReBoom_PrefValue = @"EverythingUnlocked";
					return unlockItem;
				case 3:
					SettingsItem *icloudItem;
					icloudItem = [%c(SettingsItem) itemWithTitle:@"Disable iCloud" value:(GetPrefBool(@"DisableICloud") ? @"Enabled" : @"Disabled") type:1];
					icloudItem.ReBoom_PrefValue = @"DisableICloud";
					return icloudItem;
				default:
					return [%c(SettingsItem) itemWithTitle:@"ReBoom" value:@"Error" type:1];
			}
		case 2:
			switch (indexPath.row) {
				case 0:
					replayItem = [%c(SettingsItem) itemWithTitle:@"Replay Mode" value:(GetPrefBool(@"TASMode") ? @"Enabled" : @"Disabled") type:1];
					replayItem.ReBoom_PrefValue = @"TASMode";
					return replayItem;
				case 1:
					SettingsItem *autoItem;
					autoItem = [%c(SettingsItem) itemWithTitle:@"Auto Tas" value:(GetPrefBool(@"AutoTAS") ? @"Enabled" : @"Disabled") type:1];
					autoItem.ReBoom_PrefValue = @"AutoTAS";
					return autoItem;
				case 2:
					recordItem = [%c(SettingsItem) itemWithTitle:@"Record Mode" value:(GetPrefBool(@"RecordMode") ? @"Enabled" : @"Disabled") type:1];
					recordItem.ReBoom_PrefValue = @"RecordMode";
					return recordItem;
				case 3:
					SettingsItem *deltaItem;
					deltaItem = [%c(SettingsItem) itemWithTitle:@"Fixed Delta Time" value:(GetPrefBool(@"FixedDelta") ? @"Enabled" : @"Disabled") type:1];
					deltaItem.ReBoom_PrefValue = @"FixedDelta";
					return deltaItem;
				default:
					return [%c(SettingsItem) itemWithTitle:@"ReBoom" value:@"Error" type:1];
			}
		case 3:
			switch (indexPath.row) {
				case 0:
					SettingsItem *checksumItem;
					checksumItem = [%c(SettingsItem) itemWithTitle:@"Disable Checksums" value:(GetPrefBool(@"DisableChecksum") ? @"Enabled" : @"Disabled") type:1];
					checksumItem.ReBoom_PrefValue = @"DisableChecksum";
					return checksumItem;
				case 1:
					SettingsItem *requestItem;
					requestItem = [%c(SettingsItem) itemWithTitle:@"Log Requests" value:(GetPrefBool(@"LogRequest") ? @"Enabled" : @"Disabled") type:1];
					requestItem.ReBoom_PrefValue = @"LogRequest";
					return requestItem;
				case 2:
					SettingsItem *responseItem;
					responseItem = [%c(SettingsItem) itemWithTitle:@"Log Responses" value:(GetPrefBool(@"LogResponse") ? @"Enabled" : @"Disabled") type:1];
					responseItem.ReBoom_PrefValue = @"LogResponse";
					return responseItem;
				case 3:
					SettingsItem *encryptionItem;
					encryptionItem = [%c(SettingsItem) itemWithTitle:@"Disable Encryption" value:(GetPrefBool(@"DisableEncryption") ? @"Enabled" : @"Disabled") type:1];
					encryptionItem.ReBoom_PrefValue = @"DisableEncryption";
					return encryptionItem;
				default:
					return [%c(SettingsItem) itemWithTitle:@"ReBoom" value:@"Error" type:1];
			}
		default:
			return %orig;
	}
	
	return %orig;
}
%end

%hook SettingsItem
// Add our custom property
%property (strong) NSString *ReBoom_PrefValue;
-(void)unselected {
	SettingsItem *settingsItem = self;
	// If it is one of our buttons
	if (settingsItem.ReBoom_PrefValue) {
		if ([[[self valueForKey:@"valueLabel"] valueForKey:@"string_"] isEqualToString:@"Enabled"]) {
			SetPrefBool(settingsItem.ReBoom_PrefValue, NO);
			[self setValue:@"Disabled"];
		} else {
			SetPrefBool(settingsItem.ReBoom_PrefValue, YES);
			[self setValue:@"Enabled"];

			// Make the replay mode button and record mode button conflict (so you can only have one enabled at once)
			if (self == replayItem && [[[recordItem valueForKey:@"valueLabel"] valueForKey:@"string_"] isEqualToString:@"Enabled"]) {
				[recordItem selected];
				[recordItem unselected];
			} else if (self == recordItem && [[[replayItem valueForKey:@"valueLabel"] valueForKey:@"string_"] isEqualToString:@"Enabled"]) {
				[replayItem selected];
				[replayItem unselected];
			}
		}
	}
	%orig;
}
%end



/* INFO ALERT */

%hook HSAlertView
-(void)alertView:(HSAlertView *)view clickedButtonAtIndex:(int)index {
	%orig;
	if ([view.title isEqualToString:@"ReBoom"] && index == 1) {
		saveRecording([[NSString alloc] initWithFormat:@"%@", [[%c(TrialSession) currentSession] levelId]]);
	}
}
%end

// When the game loads
%hook AppController
-(BOOL)application:(id)arg1 didFinishLaunchingWithOptions:(id)arg2 {
	// Wait 1.5 seconds
	dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 1.5 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
		if (!GetPrefBool(@"HasShownAlert")) {
			SetPrefBool(@"HasShownAlert", YES);
			showAlert(@"Welcome to ReBoom. All options can be changed from within the game's settings menu.\n\n(This will not be shown again)", @"Got it!");
		}
	});
	return %orig;
}
%end
