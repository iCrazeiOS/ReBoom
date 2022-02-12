#import "Tweak.h"

void showAlert(NSString *message, NSString *buttonText) {
	HSAlertView *delegate = [[%c(HSAlertView) alloc] init]; 
	HSAlertView *alertView = [[%c(HSAlertView) alloc] initWithTitle:@"ReBoom" message:message delegate:delegate cancelButtonTitle:buttonText otherButtonTitles:nil];
	alertView.cancelButtonIndex = 0;
	[alertView show];
}

inline bool GetPrefBool(NSString *key) {
	// return [[[NSDictionary dictionaryWithContentsOfFile:@"/var/mobile/Library/Preferences/com.dtu.reboomprefs.plist"] valueForKey:key] boolValue];
	NSString *path = [NSString stringWithFormat:@"%@/!prefs.plist", [[[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject] path]];

	// showAlert(path, @"ok");
	// NSLog(@"ReBoom: %@", path);

	if (![[NSFileManager defaultManager] fileExistsAtPath:path]) {
		[[NSFileManager defaultManager] createFileAtPath:path contents:nil attributes:nil];
	}
	NSMutableDictionary *prefsDict = [NSMutableDictionary dictionary];
	[prefsDict addEntriesFromDictionary:[NSDictionary dictionaryWithContentsOfFile:path]];

	if (![[prefsDict allKeys] containsObject:key]) {
		[prefsDict setValue:@(NO) forKey:key];
		[prefsDict writeToFile:path atomically:YES];
		return GetPrefBool(key);
	}

	NSString *value = [prefsDict valueForKey:key];

	if (!value) {
		[prefsDict setValue:@(NO) forKey:key];
		[prefsDict writeToFile:path atomically:YES];
		return GetPrefBool(key);
	}

	// showAlert([NSString stringWithFormat:@"%@: %@", key, [key boolValue] ? @"YES": @"NO"], @"OK");

	return [value boolValue];

	// return [[[NSDictionary dictionaryWithContentsOfFile:path] valueForKey:key] boolValue];
}

inline void SetPrefBool(NSString *key, BOOL value) {
	// return [[[NSDictionary dictionaryWithContentsOfFile:@"/var/mobile/Library/Preferences/com.dtu.reboomprefs.plist"] valueForKey:key] boolValue];
	// NSDictionary *prefsDict = [NSDictionary dictionaryWithContentsOfFile:];
	// [prefsDict setValue:value forKey:key];

	// NSLog(@"[iCraze Boom] called set");

	NSString *path = [NSString stringWithFormat:@"%@/!prefs.plist", [[[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject] path]];
	NSMutableDictionary *prefsDict = [NSMutableDictionary dictionary];
	[prefsDict addEntriesFromDictionary:[NSDictionary dictionaryWithContentsOfFile:path]];
	[prefsDict setObject:(value ? @"YES" : @"NO") forKey:key];
	[prefsDict writeToFile:path atomically:YES];
}

// TAS MODE
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
					if ([commands[ii] isEqual:@"rd"]) {
						[strBuffer appendString:@"r"];
					} else if ([commands[ii] isEqual:@"ru"]) {
						[strBuffer appendString:@"R"];
					} else if ([commands[ii] isEqual:@"ld"]) {
						[strBuffer appendString:@"l"];
					} else if ([commands[ii] isEqual:@"lu"]) {
						[strBuffer appendString:@"L"];
					} else if ([commands[ii] isEqual:@"***"]) {
						[strBuffer appendString:@"*"];
					} else if ([commands[ii] isEqual:@"log"]) {
						[strBuffer appendString:@"p"];
					}
				}
			}

			for (int ii = tas.length; ii < frame - 1; ii++) {
				[tas.commands addObject:strEmpty];
			}

			[tas.commands addObject:[NSString stringWithString:strBuffer]];
			tas.length = frame;
		}
	}

	[fileContent release];
}

// RECORD MODE
void saveRecording(NSString *name) {
	// super ugly
	NSURL *path = [NSURL URLWithString: [NSString stringWithFormat:@"%@%@%@", [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject], name, TAS_EXT]];
	[recording writeToURL:path atomically:NO encoding:NSASCIIStringEncoding error:NULL];

	if (LOGS_ENABLED) NSLog(@"Saved to %@!", path);
}

// PAUSE BUG
%hook TrialSession
-(void)pauseSchedulerAndActionsRecursive:(id)a {
	if (!GetPrefBool(@"PauseBug")) %orig; 
}
-(void)resumeSchedulerAndActionsRecursive:(id)a {
	if (!GetPrefBool(@"PauseBug")) %orig; 
}
%end

// FIXED DELTA and TAS MODE
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


BOOL clickedLeft = NO;
BOOL clickedRight = NO;
BOOL running = NO;
// int progress = 0;

%hook TrialSession
-(void)restartLevel {
	%orig;

	running = NO;
	// progress = 1;

	// NSLog(@"[ReBoom] Restarting level...");

	// unlock next level
	if (GetPrefBool(@"EverythingUnlocked")) [handler SEL(unLockNextLevel)];

	// replay mode
	if (GetPrefBool(@"TASMode") && ![self SEL(isChallenge)] && ![self SEL(isTournament)]) {
		if (LOGS_ENABLED) NSLog(@"[ReBoom] [TrialSession restartLevel] loading TAS recording...");
		loadMovie([self SEL(levelId)]);
	}

	// record mode
	if (GetPrefBool(@"RecordMode")) {
		if (recording == NULL) {
			recording = [[NSMutableString alloc] init];
		} else {
			[recording setString:@""];
		}
	}

	frameID = 0;
	lastFrameID = 0;
}
-(void)update:(float)a {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;

	// replay
	if (GetPrefBool(@"TASMode") && ![self SEL(isChallenge)] && ![self SEL(isTournament)]) {
		if (tas.length > 0 && frameID < tas.length && leftButton != NULL && rightButton != NULL && [tas.commands[frameID] length] > 0) {
			const NSString *list = tas.commands[frameID];

			if (clickedLeft && clickedRight) {
				clickedLeft = NO;
				clickedRight = NO;
				[self restartLevel];
			}

			running = YES;
			
			for (int i = 0; i < [list length]; i++) {
				switch([list characterAtIndex:i]) {
					case 'r':
						[rightButton SEL(selected)];
						break;
					case 'R':
						[rightButton SEL(unselected)];
						break;
					case 'l':
						[leftButton SEL(selected)];
						break;
					case 'L':
						[leftButton SEL(unselected)];
						break;
					case '*':
						[self SEL(pause)];
						break;
					case 'p':
						const CGPoint pos = [((CALayer *)[self SEL(wheely)]) position];
						CGPoint vel;
						MSG0S(CGPoint*, &vel, [self SEL(wheely)], Object88); // getVelocity

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
		saveRecording([[NSString alloc] initWithFormat:@"%@", [self SEL(levelId)]]);
		
		showAlert(@"Saved recording", @"Dismiss");
	}

	%orig;
}
%end

// FINDING BUTTONS and RECORDING
%hook HSMenuItem
-(void)selected {
	if (LOGS_ENABLED) NSLog(@"[HSMenuItem selected] called");
	if (GetPrefBool(@"RecordMode") && recording != NULL) {
		if (self == leftButton) {
			if (!running) clickedLeft = YES;
			if (LOGS_ENABLED) NSLog(@"[HSMenuItem selected] leftButton called");
			if (lastFrameID < frameID + 1) {
				if (LOGS_ENABLED) NSLog(@"[HSMenuItem selected] leftButton appending");
				[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
				lastFrameID = frameID + 1;
			}

			[recording appendString:@" ld"];
		} else if (self == rightButton) {
			if (!running) clickedRight = YES;
			if (LOGS_ENABLED) NSLog(@"[HSMenuItem selected] rightButton called");
			if (lastFrameID < frameID + 1) {
				if (LOGS_ENABLED) NSLog(@"[HSMenuItem selected] rightButton appending");
				[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
				lastFrameID = frameID + 1;
			}

			[recording appendString:@" rd"];
		}
	} else if (LOGS_ENABLED) NSLog(@"[HSMenuItem selected] not recording. RecordMode: %@", GetPrefBool(@"RecordMode") ? @"YES" : @"NO");

	%orig;
}

-(void)unselected {
	if (LOGS_ENABLED) NSLog(@"[HSMenuItem unselected] called");
	if (GetPrefBool(@"RecordMode") && recording != NULL) {
		if (self == leftButton) {
			if (LOGS_ENABLED) NSLog(@"[HSMenuItem unselected] leftButton called");
			if (lastFrameID < frameID + 1) {
				if (LOGS_ENABLED) NSLog(@"[HSMenuItem unselected] leftButton appending");
				[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
				lastFrameID = frameID + 1;
			}

			[recording appendString:@" lu"];
		} else if (self == rightButton) {
			if (LOGS_ENABLED) NSLog(@"[HSMenuItem unselected] rightButton called");
			if (lastFrameID < frameID + 1) {
				if (LOGS_ENABLED) NSLog(@"[HSMenuItem unselected] rightButton appending");
				[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
				lastFrameID = frameID + 1;
			}

			[recording appendString:@" ru"];
		}
	}

	%orig;
}

-(struct CGRect)rect {
	CGRect rec = %orig;

	if (LOGS_ENABLED) NSLog(@"[HSMenuItem rect] called - looking for buttons");

	if (rec.size.width == 200.0f && rec.size.height == 150.0f) {
		rightButton = self;
		if (LOGS_ENABLED) NSLog(@"[TrialSession rect] found right button: %@", rightButton);
	} else if (rec.size.width == 400.0f && rec.size.height == 150.0f) {
		leftButton = self;
		if (LOGS_ENABLED) NSLog(@"[TrialSession rect] found left button: %@", leftButton);
	}

	return rec;
}
%end

// ENCRYPTION
%hook HSAppSecurity
+(id)AES256Encrypt:(id)toEncrypt withKey:(id)key salt:(id)salt {
	if (GetPrefBool(@"LogRequest")) if (LOGS_ENABLED) NSLog(@"%@", [[NSString alloc] initWithData:toEncrypt encoding:NSUTF8StringEncoding]);
	return GetPrefBool(@"DisableEncryption") ? toEncrypt : %orig;
}
+(id)AES256Decrypt:(id)toDecrypt withKey:(id)key salt:(id)salt {
	id result = %orig;
	if (GetPrefBool(@"LogResponse")) if (LOGS_ENABLED) NSLog(@"Decrypted with key %@ and salt %@:\n%@", key, salt, [[NSString alloc] initWithData:result encoding:NSUTF8StringEncoding]);
	return result;
}
%end

%hook HSRequestSecurity
+(id)request:(id)a path:(id)path parameters:(id)params secureString:(id)d post:(BOOL)e secretKey:(id)f result:(id)g progress:(id)h timeout:(id)i packetSize:(id)j packetDelay:(double)k {
	if (GetPrefBool(@"LogRequest")) if (LOGS_ENABLED) NSLog(@"Sent request to %@...", path);
	return %orig;
}
%end

// CHECKSUMS
%hook Checksums
+(BOOL)verify_file:(id)file {
	return GetPrefBool(@"DisableChecksums") ? YES : %orig;
}
%end

// EVERYTHING UNLOCKED
%hook Player
-(BOOL)hasItem:(id)item id:(id)b {
	return GetPrefBool(@"EverythingUnlocked") ? YES : %orig;
}
%end
%hook LevelHandler
-(id)init {
	id result = %orig;
	handler = result;
	return result;
}
%end

// iCLOUD
%hook Player
-(BOOL)switchToICloudPlayer:(id)player {
	return GetPrefBool(@"DisableICloud") ? NO : %orig;
}
%end

















/* EXPERIMENTAL IN-GAME PREFS */


@interface Settings : UITableView
@end

@interface HSUISwitch : NSObject
+(HSUISwitch *)switchWithState:(id)state offFont:(id)font onFont:(id)font3 onStateChange:(id)change;
-(HSUISwitch *)initWithState:(id)state offFont:(id)font onFont:(id)font3 onStateChange:(id)change;
@end

@interface CCLabelTTF : NSObject {
	NSString *string_;
}
@end

@interface SettingsItem : UITableViewCell {
	CCLabelTTF* valueLabel;
}
@property (readwrite, assign) NSString *ReBoom_PrefValue;
+(SettingsItem *)itemWithTitle:(NSString *)title value:(NSString *)value type:(int)type;
-(void)setTitle:(NSString *)title;
-(void)setValue:(NSString *)title;
-(UILabel *)titleLabel;
-(void)setSwitchElement:(HSUISwitch *)element state:(int)state;
@property(readonly, assign, nonatomic) HSUISwitch* switchElement;
-(void)selected;
-(void)unselected;
@end

SettingsItem *replayItem;
SettingsItem *recordItem;

%hook Settings
-(NSInteger) numberOfSectionsInTableView:(UITableView*)tableView {
	return 4;
}

-(int)tableView:(id)view numberOfRowsInSection:(int)section {
	int ret = %orig;
	if (section == 1) ret = 3;
	else if (section == 2) ret = 3;
	else if (section == 3) ret = 4;
	return ret;
}

-(id)tableView:(id)view cellForRowAtIndexPath:(id)indexPath {
	NSIndexPath *index = indexPath;

	switch (index.section) {
		case 1:
			switch (index.row) {
				case 0:
					SettingsItem *pauseItem;
					pauseItem = [%c(SettingsItem) itemWithTitle:@"Pause Bug" value:(GetPrefBool(@"PauseBug") ? @"Enabled" : @"Disabled") type:1];
					pauseItem.ReBoom_PrefValue = @"PauseBug";
					return pauseItem;
				case 1:
					SettingsItem *unlockItem;
					unlockItem = [%c(SettingsItem) itemWithTitle:@"Everything Unlocked" value:(GetPrefBool(@"EverythingUnlocked") ? @"Enabled" : @"Disabled") type:1];
					unlockItem.ReBoom_PrefValue = @"EverythingUnlocked";
					return unlockItem;
				case 2:
					SettingsItem *icloudItem;
					icloudItem = [%c(SettingsItem) itemWithTitle:@"Disable iCloud" value:(GetPrefBool(@"DisableICloud") ? @"Enabled" : @"Disabled") type:1];
					icloudItem.ReBoom_PrefValue = @"DisableICloud";
					return icloudItem;
				default:
					return [%c(SettingsItem) itemWithTitle:@"Unknown" value:@"Unknown" type:1];
			}
		case 2:
			switch (index.row) {
				case 0:
					replayItem = [%c(SettingsItem) itemWithTitle:@"Replay Mode" value:(GetPrefBool(@"TASMode") ? @"Enabled" : @"Disabled") type:1];
					replayItem.ReBoom_PrefValue = @"TASMode";
					return replayItem;
				case 1:
					recordItem = [%c(SettingsItem) itemWithTitle:@"Record Mode" value:(GetPrefBool(@"RecordMode") ? @"Enabled" : @"Disabled") type:1];
					recordItem.ReBoom_PrefValue = @"RecordMode";
					return recordItem;
				case 2:
					SettingsItem *deltaItem;
					deltaItem = [%c(SettingsItem) itemWithTitle:@"Fixed Delta Time" value:(GetPrefBool(@"FixedDelta") ? @"Enabled" : @"Disabled") type:1];
					deltaItem.ReBoom_PrefValue = @"FixedDelta";
					return deltaItem;
				default:
					return [%c(SettingsItem) itemWithTitle:@"Unknown" value:@"Unknown" type:1];
			}
		case 3:
			switch (index.row) {
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
%property (strong) NSString *ReBoom_PrefValue;
-(void)unselected {
	SettingsItem *settingsItem = self;
	if (settingsItem.ReBoom_PrefValue) {
		NSLog(@"[iCraze Boom] called onclick");
		if ([[[self valueForKey:@"valueLabel"] valueForKey:@"string_"] isEqualToString:@"Enabled"]) {
			SetPrefBool(settingsItem.ReBoom_PrefValue, NO);
			[self setValue:@"Disabled"];
		} else {
			SetPrefBool(settingsItem.ReBoom_PrefValue, YES);
			[self setValue:@"Enabled"];

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





%ctor {
	dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 1.5 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
		showAlert(@"To record a TAS: Start a level then click restart.\n\nTo replay a TAS: Start a level, move left & right, then click restart.", @"Got it!");
	});
}
