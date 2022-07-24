#import "Tweak.h"

NSString *getLevelURL() {
	NSString *path = [NSString stringWithFormat:@"%@/!prefs.plist", [[[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject] path]];

	// Create file if it doesn't exist
	if (![[NSFileManager defaultManager] fileExistsAtPath:path]) {
		[[NSFileManager defaultManager] createFileAtPath:path contents:nil attributes:nil];
	}

	// Load prefs from file
	NSMutableDictionary *prefsDict = [NSMutableDictionary dictionary];
	[prefsDict addEntriesFromDictionary:[NSDictionary dictionaryWithContentsOfFile:path]];
	// If key doesn't exist, set it to false ("Disabled")
	if (![[prefsDict allKeys] containsObject:@"CustomLevelURL"]) {
		[prefsDict setValue:@"" forKey:@"CustomLevelURL"];
		[prefsDict writeToFile:path atomically:YES];
		return @"";
	}

	// Get the value for the key
	NSString *value = [prefsDict valueForKey:@"CustomLevelURL"];
	return value;

	// return @"https://boom.markstam.eu/storage/online-levels/67f2b95b7271a20398120b6f3557d913.plhs";
}

void setLevelURL(NSString *url) {
	NSString *path = [NSString stringWithFormat:@"%@/!prefs.plist", [[[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject] path]];
	NSMutableDictionary *prefsDict = [NSMutableDictionary dictionary];
	[prefsDict addEntriesFromDictionary:[NSDictionary dictionaryWithContentsOfFile:path]];
	[prefsDict setObject:url forKey:@"CustomLevelURL"];
	[prefsDict writeToFile:path atomically:YES];
}

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
	// If key doesn't exist, set it to false ("Disabled")
	if (![[prefsDict allKeys] containsObject:key]) {
		id defaultValue = @(NO);
		if ([key isEqualToString:@"FixedDelta"]) defaultValue = @(YES);
		[prefsDict setValue:defaultValue forKey:key];
		[prefsDict writeToFile:path atomically:YES];
		return GetPrefBool(key);
	}

	// Get the value for the key
	NSString *value = [prefsDict valueForKey:key];

	// If there is no value, set it to false ("Disabled")
	if (!value) {
		id defaultValue = @(NO);
		if ([key isEqualToString:@"FixedDelta"]) defaultValue = @(YES);
		[prefsDict setValue:defaultValue forKey:key];
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
void loadReplay(NSString *name) {
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
				[strBuffer appendString:commands[ii]];
			}

			for (int ii = tas.length; ii < frame - 1; ii++) [tas.commands addObject:strEmpty];

			[tas.commands addObject:[NSString stringWithString:strBuffer]];
			tas.length = frame;
		}
	}
}

// Save TAS recording
void saveRecording(NSString *name) {
	NSURL *path = [NSURL URLWithString: [NSString stringWithFormat:@"%@%@%@", [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject], name, TAS_EXT]];
	[recording writeToURL:path atomically:NO encoding:NSASCIIStringEncoding error:NULL];

	if (LOGS_ENABLED) NSLog(@"Saved to %@!", path);

	showAlert(@"TAS recording has been saved!", @"Dismiss");
}

// Remove ghost file
void removeGhost(NSString *levelId) {
	NSArray *paths = NSSearchPathForDirectoriesInDomains(NSApplicationSupportDirectory, NSUserDomainMask, YES);
	NSString *applicationSupportDirectory = [paths firstObject];
	NSString *ghostPath = [NSString stringWithFormat:@"%@/%@.ghost", applicationSupportDirectory, levelId];
	if (LOGS_ENABLED) NSLog(@"[ReBoom removeGhost] Removing ghost file for level: %@...", levelId);
	[[NSFileManager defaultManager] removeItemAtPath:ghostPath error:nil];
}

// Fixed Delta & TAS
%hook CCDirector
-(BOOL)useFixedTimestep {
	return GetPrefBool(@"PauseBug") ? YES : %orig;
}
%end

/* this next bit is UGLY, but what can you do? */
%hook Wheely
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook WaterItemEffect
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook TrialLayer
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook TrialGameController
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook TrialBackground
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook Trampoline
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook ThemeSelect
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook SpringBoard
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook SoftBox
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook SoftBall
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook OilWell
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook MovingFlat
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook MenuTrialBackground
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook News
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook MenuTrial
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook LevelHelperLoader
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook GlassBall
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook FireBowl
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook Conveyor
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook CoinRain
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook ChallengeTurn
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook ChallengePlayer
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook ChallengeForceRandomOpponent
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook Challenge
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook Cage
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook Buoyant
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook BridgePart
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook Bomb
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook Object156
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)postUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end
%hook CCScheduler
-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
-(void)fixedUpdate:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;
}
%end

// TAS, Unlocks, Pause Bug, Disable Tutorials
%hook TrialSession
-(id)initWithLevel:(id)level challenge:(id)challenge tournament:(id)tournament {
	if (challenge != NULL || tournament != NULL) return %orig;

	NSString *customLevelURL = getLevelURL();
	// switch to custom level url if string is not empty
	if (![customLevelURL isEqualToString:@""]) {
		level = [NSMutableDictionary dictionaryWithDictionary:level];
		level[@"url"] = customLevelURL;
	}

	return %orig(level, challenge, tournament);
}

-(void)showTutorial { // disable tutorials
	if (!GetPrefBool(@"DisableTutorials")) %orig;
}

-(void)pauseSchedulerAndActionsRecursive:(id)recursive {
	if (!GetPrefBool(@"PauseBug")) %orig; 
}
-(void)resumeSchedulerAndActionsRecursive:(id)recursive {
	if (!GetPrefBool(@"PauseBug")) %orig; 
}

-(void)restartLevel {
	%orig;
	if (LOGS_ENABLED) NSLog(@"[ReBoom] Restarting level...");
	[self start_reboom];
}

-(void)onEnter {
	%orig;
	if (LOGS_ENABLED) NSLog(@"[ReBoom] Starting level...");
	[self start_reboom];

	if (GetPrefBool(@"HideControls")) {
		[[[%c(TrialSession) currentSession] hud] hideTouchControls:YES];
	}
}

%new
-(void)start_reboom {
	if (LOGS_ENABLED) NSLog(@"[ReBoom] [TrialSession start_reboom] called");

	// unlock next level
	if (GetPrefBool(@"EverythingUnlocked")) [[%c(LevelHandler) sharedInstance] unLockNextLevel];

	// replay mode
	if (GetPrefBool(@"TASMode") && ![self isChallenge] && ![self isTournament]) {
		if (LOGS_ENABLED) NSLog(@"[ReBoom] [TrialSession restartLevel] loading TAS recording...");
		loadReplay([self levelId]);
	}

	// record mode
	if (GetPrefBool(@"RecordMode")) {
		if (recording == NULL) recording = [[NSMutableString alloc] init];
		else [recording setString:@""];
	}

	frameID = 0;
	lastFrameID = 0;
}

-(void)update:(float)update {
	GetPrefBool(@"FixedDelta") ? %orig(FIXED_DELTA) : %orig;

	if (GetPrefBool(@"TASMode") && ![self isChallenge] && ![self isTournament]) {
		if (tas.length > 0 && frameID < tas.length && [tas.commands[frameID] length] > 0) {
			const NSString *list = tas.commands[frameID];
			
			for (int i = 0; i < [list length]; i++) {
				NSDictionary *selectors = @{@"r": @"right", @"R": @"stopRight", @"l": @"left", @"L": @"stopLeft", @"*": @"pause", @"-": @"resume"};
				NSString *characterAsNSString = [NSString stringWithFormat:@"%C", [list characterAtIndex:i]];
				if ([[selectors allKeys] containsObject:characterAsNSString]) {
					[self performSelector:NSSelectorFromString([selectors valueForKey:characterAsNSString])];
				}
			}
		}
	}

	frameID++;
}

// on win
-(void)goal:(float)goal {
	if (LOGS_ENABLED) NSLog(@"[TrialSession goal] called");
	if (GetPrefBool(@"RecordMode") && recording != NULL && ![recording isEqual:@""]) {
		if (LOGS_ENABLED) NSLog(@"[TrialSession goal] asking to save...");
		
		HSAlertView *delegate = [[%c(HSAlertView) alloc] init];
		HSAlertView *alertView = [[%c(HSAlertView) alloc] initWithTitle:@"ReBoom" message:@"Would you like to save the TAS recording?" delegate:delegate cancelButtonTitle:@"No" otherButtonTitles:@"Yes", nil];
		[alertView show];
	} else if (GetPrefBool(@"TASMode") && ![self isChallenge] && ![self isTournament]) {
		NSString *path = [NSString stringWithFormat:@"%@/%@%@", [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject].path, [self levelId], TAS_EXT];
		if ([[NSFileManager defaultManager] fileExistsAtPath:path]) {
			if (LOGS_ENABLED) NSLog(@"[TrialSession goal] showing TAS completion alert...");
			showAlert(@"TAS playback complete", @"Dismiss");
		}
	}

	%orig;
}

// when player taps right
-(void)right {
	%orig;
	if (GetPrefBool(@"RecordMode") && recording != NULL) {
		if (LOGS_ENABLED) NSLog(@"[TrialSession right] called with record mode on");
		if (lastFrameID < frameID + 1) {
			if (LOGS_ENABLED) NSLog(@"[TrialSession right] appending");
			[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
			lastFrameID = frameID + 1;
		}

		[recording appendString:@" r"];
	}
}

// when player taps left
-(void)left {
	%orig;
	if (GetPrefBool(@"RecordMode") && recording != NULL) {
		if (LOGS_ENABLED) NSLog(@"[TrialSession left] called with record mode on");
		if (lastFrameID < frameID + 1) {
			if (LOGS_ENABLED) NSLog(@"[TrialSession left] appending");
			[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
			lastFrameID = frameID + 1;
		}

		[recording appendString:@" l"];
	}
}

// when player releases right
-(void)stopRight {
	%orig;
	if (GetPrefBool(@"RecordMode") && recording != NULL) {
		if (LOGS_ENABLED) NSLog(@"[TrialSession stopRight] called with record mode on");
			if (lastFrameID < frameID + 1) {
				if (LOGS_ENABLED) NSLog(@"[TrialSession stopRight] appending");
				[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
				lastFrameID = frameID + 1;
			}

			[recording appendString:@" R"];
	}
}

// when player releases left
-(void)stopLeft {
	%orig;
	if (GetPrefBool(@"RecordMode") && recording != NULL) {
		if (LOGS_ENABLED) NSLog(@"[TrialSession stopLeft] called with record mode on");
			if (lastFrameID < frameID + 1) {
				if (LOGS_ENABLED) NSLog(@"[TrialSession stopLeft] appending");
				[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
				lastFrameID = frameID + 1;
			}

			[recording appendString:@" L"];
	}
}

// when player presses pause
-(void)pause {
	%orig;
	if (GetPrefBool(@"RecordMode") && recording != NULL) {
		if (LOGS_ENABLED) NSLog(@"[TrialSession pause] called with record mode on");
			if (lastFrameID < frameID + 1) {
				if (LOGS_ENABLED) NSLog(@"[TrialSession pause] appending");
				[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
				lastFrameID = frameID + 1;
			}

			[recording appendString:@" *"];
	}
}

// when player resumes the game
-(void)resume {
	%orig;
	if (GetPrefBool(@"RecordMode") && recording != NULL) {
		if (LOGS_ENABLED) NSLog(@"[TrialSession resume] called with record mode on");
			if (lastFrameID < frameID + 1) {
				if (LOGS_ENABLED) NSLog(@"[TrialSession resume] appending");
				[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
				lastFrameID = frameID + 1;
			}

			[recording appendString:@" -"];
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
	return YES;
}
%end

%hook Player
// Unlock Everything
-(BOOL)hasItem:(id)item id:(id)anId {
	return GetPrefBool(@"EverythingUnlocked") ? YES : %orig;
}

// Disable iCloud
-(BOOL)switchToICloudPlayer:(id)icloudPlayer {
	return NO;
}

// Custom server
+(void)setHost:(id)host {
    %orig(SERVER_HOST);
}
%end

%hook HSGameConfiguration
+(void)setHost:(id)host {
    %orig(SERVER_HOST);
}
%end

%hook HSNews
+(void)setHost:(id)host {
    %orig(SERVER_HOST);
}
%end

%hook ChallengeClient
+(void)setHost:(id)host {
    %orig(SERVER_HOST);
}
%end

%hook TournamentsClient
+(void)setTournamentUrl:(id)url {
	%orig([NSString stringWithFormat:@"%@/tournaments/", SERVER_HOST]);
}
%end

// Disable Game Center
%hook HSGameCenterManager
+(BOOL)isAvailable {
	return NO;
}
%end



// Replace functionality of "buy coins" button
%hook StoreGetCoinsDialog
-(void)onEnter {
	// Close the dialog immediately
	[self back];
	// Add coins
	[[%c(Player) sharedPlayer] incrementCoins:10000 archive:YES];
}
%end



// Hold down on the Level Sign (for 3 seconds) to reset ghost
%hook LevelSign
%property(nonatomic, assign) int selected_time;
-(void)selected {
	%orig;
	self.selected_time = [[NSDate date] timeIntervalSince1970];
}

-(void)unselected {
	if ([[NSDate date] timeIntervalSince1970] - self.selected_time >= 3) {
		HSAlertView *delegate = [[%c(HSAlertView) alloc] init];
		HSAlertView *alertView = [[%c(HSAlertView) alloc] initWithTitle:@"Remove Ghost?" message:[NSString stringWithFormat:@"Are you sure you want to reset your ghost for level: '%@'?", [self valueForKey:@"levelId"]] delegate:delegate cancelButtonTitle:@"Yes" otherButtonTitles:@"No", nil];
		[alertView show];
	} else %orig;
}
%end



/*  IN-GAME PREFS */

SettingsItem *replayItem, *recordItem, *levelURLItem, *discordItem;
int currentHeaderLabel = 0;

%hook Settings
-(void)onExit { // resets the counter used to show custom labels
	%orig;
	currentHeaderLabel = 0;
}

-(NSInteger)numberOfSectionsInTableView:(UITableView*)tableView {
	// Tell the game how many sections we'll have
	return 5;
}

-(int)tableView:(id)view numberOfRowsInSection:(int)section {
	// Tell the game how many rows we have in our custom sections
	int ret = %orig;
	if (section == 0) ret -= 2; // we want to remove the "Restore purchases" and "iCloud" buttons
	else if (section == 1) ret = 4;
	else if (section == 2) ret = 3;
	else if (section == 3) ret = 3;
	else if (section == 4) ret = 1;
	return ret;
}

-(id)tableView:(id)view cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	// Game's default section
	if (indexPath.section == 0) {
		SettingsItem *orig = %orig;

		// Check title of button, as its index may vary
		if ([((CCLabelTTF *)[orig valueForKey:@"titleLabel"]).string containsString:@"Facebook"]) { // modify the facebook button
			levelURLItem = [%c(SettingsItem) itemWithTitle:@"Custom Level" value:[getLevelURL() isEqualToString:@""] ? @"Unset" : @"Set" type:1];
			return levelURLItem;
		}
	}
	// Loop through our custom sections
	switch (indexPath.section) {
		case 1: {
			switch (indexPath.row) {
				case 0: {
					SettingsItem *pauseItem = [%c(SettingsItem) itemWithTitle:@"Un-patch Pause Bug" value:(GetPrefBool(@"PauseBug") ? @"Enabled" : @"Disabled") type:1];
					pauseItem.ReBoom_PrefValue = @"PauseBug";
					return pauseItem;
				} case 1: {
					SettingsItem *unlockItem = [%c(SettingsItem) itemWithTitle:@"Everything Unlocked" value:(GetPrefBool(@"EverythingUnlocked") ? @"Enabled" : @"Disabled") type:1];
					unlockItem.ReBoom_PrefValue = @"EverythingUnlocked";
					return unlockItem;
				} case 2: {
					SettingsItem *tutorialsItem = [%c(SettingsItem) itemWithTitle:@"Disable Tutorials" value:(GetPrefBool(@"DisableTutorials") ? @"Enabled" : @"Disabled") type:1];
					tutorialsItem.ReBoom_PrefValue = @"DisableTutorials";
					return tutorialsItem;
				} case 3: {
					SettingsItem *hideControlsItem = [%c(SettingsItem) itemWithTitle:@"Hide Touch Controls" value:(GetPrefBool(@"HideControls") ? @"Enabled" : @"Disabled") type:1];
					hideControlsItem.ReBoom_PrefValue = @"HideControls";
					return hideControlsItem;
				} default: {
					return [%c(SettingsItem) itemWithTitle:@"ReBoom" value:@"Error" type:1];
				}
			}
		} case 2: {
			switch (indexPath.row) {
				case 0: {
					replayItem = [%c(SettingsItem) itemWithTitle:@"Replay Mode" value:(GetPrefBool(@"TASMode") ? @"Enabled" : @"Disabled") type:1];
					replayItem.ReBoom_PrefValue = @"TASMode";
					return replayItem;
				} case 1: {
					recordItem = [%c(SettingsItem) itemWithTitle:@"Record Mode" value:(GetPrefBool(@"RecordMode") ? @"Enabled" : @"Disabled") type:1];
					recordItem.ReBoom_PrefValue = @"RecordMode";
					return recordItem;
				} case 2: {
					SettingsItem *deltaItem = [%c(SettingsItem) itemWithTitle:@"Fixed Delta Time" value:(YES ? @"Enabled" : @"Disabled") type:1];
					deltaItem.ReBoom_PrefValue = @"FixedDelta";
					return deltaItem;
				} default: {
					return [%c(SettingsItem) itemWithTitle:@"ReBoom" value:@"Error" type:1];
				}
			}
		} case 3: {
			switch (indexPath.row) {
				case 0: {
					SettingsItem *requestItem = [%c(SettingsItem) itemWithTitle:@"Log Requests" value:(GetPrefBool(@"LogRequest") ? @"Enabled" : @"Disabled") type:1];
					requestItem.ReBoom_PrefValue = @"LogRequest";
					return requestItem;
				} case 1: {
					SettingsItem *responseItem = [%c(SettingsItem) itemWithTitle:@"Log Responses" value:(GetPrefBool(@"LogResponse") ? @"Enabled" : @"Disabled") type:1];
					responseItem.ReBoom_PrefValue = @"LogResponse";
					return responseItem;
				} case 2: {
					SettingsItem *encryptionItem = [%c(SettingsItem) itemWithTitle:@"Disable Encryption" value:(GetPrefBool(@"DisableEncryption") ? @"Enabled" : @"Disabled") type:1];
					encryptionItem.ReBoom_PrefValue = @"DisableEncryption";
					return encryptionItem;
				} default: {
					return [%c(SettingsItem) itemWithTitle:@"ReBoom" value:@"Error" type:1];
				}
			}
		} case 4: {
			switch (indexPath.row) {
				case 0: {
					discordItem = [%c(SettingsItem) itemWithTitle:@"Join the discord" value:@"" type:1];
					return discordItem;
				} default: {
					return [%c(SettingsItem) itemWithTitle:@"ReBoom" value:@"Error" type:1];
				}
			}
		} default: {
			return %orig;
		}
	}
	
	return %orig;
}
%end

%hook SettingsItem
// Add our custom property
%property (strong) NSString *ReBoom_PrefValue;
-(void)unselected {
	// If it is one of our options
	if (self.ReBoom_PrefValue) {
		if ([[[self valueForKey:@"valueLabel"] valueForKey:@"string_"] isEqualToString:@"Enabled"]) {
			SetPrefBool(self.ReBoom_PrefValue, NO);
			[self setValue:@"Disabled"];
		} else {
			SetPrefBool(self.ReBoom_PrefValue, YES);
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
	} else if (self == levelURLItem) {
		HSAlertView *alertView = [[%c(HSAlertView) alloc] initWithTitle:@"Custom Level URL"  message:nil delegate:[[%c(HSAlertView) alloc] init] cancelButtonTitle:@"Cancel" otherButtonTitles:@"Save", nil];
		alertView.style = 1; // style with textfield
		alertView.inputTextField.placeholder = @"Leave blank to disable";
		[alertView show];
	} else if (self == discordItem) {
		[[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"https://discord.gg/wgrbBPvrQ7"] options:@{} completionHandler:nil];
	}
	%orig;
}
%end

// Custom settings footers
// almost definitely a better way to do this, but it works
%hook HSLabelSafeBMFont
-(void)setString:(NSString *)string updateLabel:(BOOL)update {
	if ([string hasPrefix:@"Boom! version "]) {
		string = @"";
		NSArray *customLabels = @[@"Miscellaneous", @"TAS Tools", @"Development Options", @"ReBoom by @iCrazeiOS\nThanks to Banana, Mac & lachylegend", @"ReBoom v1.0"];
		string = ((currentHeaderLabel < [customLabels count]) ? customLabels[currentHeaderLabel] : @"");
		currentHeaderLabel++;
	}
	%orig(string, update);
}
%end



/* INFO ALERT */

%hook HSAlertView
-(void)alertView:(HSAlertView *)view clickedButtonAtIndex:(int)index {
	%orig;
	if ([view.title isEqualToString:@"ReBoom"] && index == 1) {
		saveRecording([[NSString alloc] initWithFormat:@"%@", [[%c(TrialSession) currentSession] levelId]]);
	} else if ([view.title isEqualToString:@"Remove Ghost?"] && index == 0) {
		removeGhost([[%c(TrialSession) currentSession] levelId]);
		[[%c(TrialSession) currentSession] quit];
	} else if ([view.title isEqualToString:@"Custom Level URL"] && index == 1) {
		NSString *levelURL = view.inputTextField.text;
		if (![levelURL isEqualToString:@""] && ![levelURL hasPrefix:@"http"]) levelURL = [@"https://" stringByAppendingString:levelURL]; // all sites should be using https by now. many will refuse http, so I will be forcing a https prefix if no protocol is provided
		setLevelURL(levelURL);
		[levelURLItem setValue:[levelURL isEqualToString:@""] ? @"Unset" : @"Set"];
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


// Add key press listener to CustomSettingsViewController
%hook CustomNavigationViewController
-(NSArray *)keyCommands {
	UIKeyCommand *leftArrowKeyCommand = [UIKeyCommand keyCommandWithInput:UIKeyInputLeftArrow modifierFlags:0 action:@selector(hardwareKeyboardLeftArrowPressed)]; // left arrow to move left
	UIKeyCommand *rightArrowKeyCommand = [UIKeyCommand keyCommandWithInput:UIKeyInputRightArrow modifierFlags:0 action:@selector(hardwareKeyboardRightArrowPressed)]; // right arrow to move right
	UIKeyCommand *downArrowKeyCommand = [UIKeyCommand keyCommandWithInput:UIKeyInputDownArrow modifierFlags:0 action:@selector(hardwareKeyboardDownArrowPressed)]; // down arrow to stop
	UIKeyCommand *escapeKeyCommand = [UIKeyCommand keyCommandWithInput:UIKeyInputEscape modifierFlags:0 action:@selector(hardwareKeyboardEscapePressed)]; // escape to pause
	UIKeyCommand *RKeyCommand = [UIKeyCommand keyCommandWithInput:@"r" modifierFlags:0 action:@selector(hardwareKeyboardRKeyPressed)]; // R key to restart
	return @[leftArrowKeyCommand, rightArrowKeyCommand, downArrowKeyCommand, escapeKeyCommand, RKeyCommand];
}

// we need this to make the key listeners work
-(BOOL)canBecomeFirstResponder {
	return YES;
}

%new
-(void)hardwareKeyboardLeftArrowPressed { // left arrow to move left
	[[%c(TrialSession) currentSession] left];
	dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 0.1 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
		[[%c(TrialSession) currentSession] stopLeft];
	});
}

%new
-(void)hardwareKeyboardRightArrowPressed { // right arrow to move right
	[[%c(TrialSession) currentSession] right];
	dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 0.1 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
		[[%c(TrialSession) currentSession] stopRight];
	});
}

%new
-(void)hardwareKeyboardDownArrowPressed { // down arrow to stop
	// doesnt work properly but it isn't a priority atm
	[[%c(TrialSession) currentSession] left];
	[[%c(TrialSession) currentSession] right];
	dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 0.2 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
		[[%c(TrialSession) currentSession] stopLeft];
		[[%c(TrialSession) currentSession] stopRight];
	});
}

%new
-(void)hardwareKeyboardEscapePressed { // escape to pause
	((TrialSession *)[%c(TrialSession) currentSession]).paused ? [[%c(TrialSession) currentSession] resume] : [[%c(TrialSession) currentSession] pause];
}

%new
-(void)hardwareKeyboardRKeyPressed { // R key to restart
	[[%c(TrialSession) currentSession] restartLevel];
}
%end




%ctor {
	NSString *bundleID = [[NSBundle mainBundle] bundleIdentifier];
	if (!([bundleID containsString:@"com.happysprites.boom"] || [bundleID containsString:@"eu.markstam.boomclone"])) return;
	%init;
}
