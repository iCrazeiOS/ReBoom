/*
	Almost everything in this file is for TAS or settings.
	All other options can be found in the Hooks directory.
*/

#import "Headers/Main.h"

NSString *getLevelURL() {
	NSUserDefaults *preferences = [[NSUserDefaults alloc] initWithSuiteName:DEFAULTS_NAME];
	return [preferences objectForKey:@"CustomLevelURL"];
}

// Load TAS recording
void loadReplay(NSString *name) {
	tas.length = 0;
	tas.commands = [[NSMutableArray alloc] init];

	NSString *path = [NSString stringWithFormat:@"%@/%@%@", [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject].path, name, TAS_EXT];
	if (![[NSFileManager defaultManager] fileExistsAtPath:path]) return;

	NSString *fileContent = [[NSString alloc] initWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
	NSArray *lines = [fileContent componentsSeparatedByString:@"\n"];

	NSMutableString *strBuffer = [NSMutableString string];

	for (int i = 0; i < [lines count]; i++) {
		if (![lines[i] isEqualToString:@""]) {
			NSArray *sides = [lines[i] componentsSeparatedByString:@":"];
			int frame = [sides[0] intValue];

			[strBuffer setString:@""];
			NSArray *commands = [sides[1] componentsSeparatedByString:@" "];
			for (int ii = 0; ii < [commands count]; ii++) [strBuffer appendString:commands[ii]];
			for (int ii = tas.length; ii < frame - 1; ii++) [tas.commands addObject:[NSString string]];

			[tas.commands addObject:[NSString stringWithString:strBuffer]];
			tas.length = frame;
		}
	}
}

// TAS, Unlocks, Pause Bug, Disable Tutorials
%hook TrialSession
-(id)initWithLevel:(id)level challenge:(id)challenge tournament:(id)tournament {
	if (challenge || tournament) return %orig;

	NSString *customLevelURL = getLevelURL();
	// switch to custom level url if string is not empty
	if (![customLevelURL isEqualToString:@""]) {
		// verify that the URL is valid
		NSData *data = [NSData dataWithContentsOfURL:[NSURL URLWithString:customLevelURL]];
		if (data) {
			NSDictionary *plistDict = [NSPropertyListSerialization propertyListWithData:data options:NSPropertyListImmutable format:NULL error:NULL];
			level = [NSMutableDictionary dictionaryWithDictionary:level];
			level[@"url"] = customLevelURL;
			if ([plistDict objectForKey:@"SPRITES_INFO"]) {
				os_log(OS_LOG_DEFAULT, "reboom level sprites detected");
				os_log(OS_LOG_DEFAULT, "reboom Custom level name 1: %{public}@", [plistDict objectForKey:@"CustomLevelName"]);
				level[@"levelName"] = [plistDict objectForKey:@"CustomLevelName"] ?: @"Custom Level"; // doesn't work rn
			} else {
				showAlert(@"Error: The custom level seems to be invalid", @"Dismiss");
				return %orig;
			}
		} else {
			showAlert(@"Error: The custom level URL seems to be invalid (or could not be fetched)", @"Dismiss");
			return %orig;
		}
	}

	os_log(OS_LOG_DEFAULT, "reboom Custom level name 2: %{public}@", level[@"levelName"]);
	return %orig(level, challenge, tournament);
}

-(void)showTutorial { // disable tutorials
	if (!getPrefBool(@"DisableTutorials")) %orig;
}

-(void)restartLevel {
	%orig;
	[self startReBoom];
}

-(void)onEnter {
	%orig;
	[self startReBoom];
	if (getPrefBool(@"HideControls")) [[[%c(TrialSession) currentSession] hud] hideTouchControls:YES];
}

%new
-(void)startReBoom {
	// unlock next level
	if (getPrefBool(@"EverythingUnlocked")) [[%c(LevelHandler) sharedInstance] unLockNextLevel];

	// replay mode
	if (getPrefBool(@"TASMode") && ![self isChallenge] && ![self isTournament] && [getLevelURL() isEqualToString:@""]) loadReplay([self levelId]);

	// record mode
	if (getPrefBool(@"RecordMode") && ![self isChallenge] && ![self isTournament] && [getLevelURL() isEqualToString:@""]) {
		if (recording) [recording setString:@""];
		else recording = [[NSMutableString alloc] init];
	}

	frameID = 0;
	lastFrameID = 0;
}

-(void)update:(float)update {
	%orig(FIXED_DELTA);

	if (getPrefBool(@"TASMode") && ![self isChallenge] && ![self isTournament]) {
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

// on level completion
-(void)goal:(float)goal {
	if (getPrefBool(@"RecordMode") && recording && ![recording isEqualToString:@""]) {
		HSAlertView *delegate = [[%c(HSAlertView) alloc] init];
		HSAlertView *alertView = [[%c(HSAlertView) alloc] initWithTitle:@"ReBoom" message:@"Would you like to save the TAS recording?" delegate:delegate cancelButtonTitle:@"No" otherButtonTitles:@"Yes", nil];
		[alertView show];
	} else if (getPrefBool(@"TASMode") && ![self isChallenge] && ![self isTournament]) {
		NSString *path = [NSString stringWithFormat:@"%@/%@%@", [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject].path, [self levelId], TAS_EXT];
		if ([[NSFileManager defaultManager] fileExistsAtPath:path]) showAlert(@"TAS playback complete", @"Dismiss");
	}

	%orig;
}

// when player taps right
-(void)right {
	%orig;
	if (getPrefBool(@"RecordMode") && recording) {
		if (lastFrameID < frameID + 1) {
			[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
			lastFrameID = frameID + 1;
		}

		[recording appendString:@" r"];
	}
}

// when player taps left
-(void)left {
	%orig;
	if (getPrefBool(@"RecordMode") && recording) {
		if (lastFrameID < frameID + 1) {
			[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
			lastFrameID = frameID + 1;
		}

		[recording appendString:@" l"];
	}
}

// when player releases right
-(void)stopRight {
	%orig;
	if (getPrefBool(@"RecordMode") && recording) {
		if (lastFrameID < frameID + 1) {
			[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
			lastFrameID = frameID + 1;
		}

		[recording appendString:@" R"];
	}
}

// when player releases left
-(void)stopLeft {
	%orig;
	if (getPrefBool(@"RecordMode") && recording) {
		if (lastFrameID < frameID + 1) {
			[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
			lastFrameID = frameID + 1;
		}

		[recording appendString:@" L"];
	}
}

// when player presses pause
-(void)pause {
	%orig;
	if (getPrefBool(@"RecordMode") && recording) {
		if (lastFrameID < frameID + 1) {
			[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
			lastFrameID = frameID + 1;
		}

		[recording appendString:@" *"];
	}
}

// when player resumes the game
-(void)resume {
	%orig;
	if (getPrefBool(@"RecordMode") && recording) {
		if (lastFrameID < frameID + 1) {
			[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
			lastFrameID = frameID + 1;
		}

		[recording appendString:@" -"];
	}
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
	return getPrefBool(@"EverythingUnlocked") ? YES : %orig;
}
%end



/*  IN-GAME PREFS */

SettingsItem *replayItem, *recordItem, *levelURLItem, *repoItem, *discordItem;
int currentHeaderLabel = 0;

%hook Settings
-(void)onExit { // resets the counter used to show custom labels
	%orig;
	currentHeaderLabel = 0;
}

-(NSInteger)numberOfSectionsInTableView:(UITableView*)tableView {
	// Tell the game how many sections we'll have
	return 4; // 1 for the default section, plus 3 for our custom ones
}

-(int)tableView:(id)view numberOfRowsInSection:(int)section {
	// Tell the game how many rows we have in our custom sections
	int ret = %orig;
	if (section == 0) ret -= 1; // we want to remove the "Restore purchases" button from the game's orignal settings
	else if (section == 1) ret = 4; // our first custom section
	else if (section == 2) ret = 2; // our second custom section
	else if (section == 3) ret = 1; // our third custom section
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
		} else if ([((CCLabelTTF *)[orig valueForKey:@"titleLabel"]).string containsString:@"iCloud"]) { // modify the twitter button
			repoItem = [%c(SettingsItem) itemWithTitle:@"Browse Levels" value:@"" type:1];
			return repoItem;
		}
	}
	// Loop through our custom sections
	switch (indexPath.section) {
		case 1: {
			switch (indexPath.row) {
				case 0: {
					SettingsItem *pauseItem = [%c(SettingsItem) itemWithTitle:@"Un-patch Pause Bug" value:(getPrefBool(@"PauseBug") ? @"Enabled" : @"Disabled") type:1];
					pauseItem.reboomValue = @"PauseBug";
					return pauseItem;
				} case 1: {
					SettingsItem *unlockItem = [%c(SettingsItem) itemWithTitle:@"Everything Unlocked" value:(getPrefBool(@"EverythingUnlocked") ? @"Enabled" : @"Disabled") type:1];
					unlockItem.reboomValue = @"EverythingUnlocked";
					return unlockItem;
				} case 2: {
					SettingsItem *tutorialsItem = [%c(SettingsItem) itemWithTitle:@"Disable Tutorials" value:(getPrefBool(@"DisableTutorials") ? @"Enabled" : @"Disabled") type:1];
					tutorialsItem.reboomValue = @"DisableTutorials";
					return tutorialsItem;
				} case 3: {
					SettingsItem *hideControlsItem = [%c(SettingsItem) itemWithTitle:@"Hide Touch Controls" value:(getPrefBool(@"HideControls") ? @"Enabled" : @"Disabled") type:1];
					hideControlsItem.reboomValue = @"HideControls";
					return hideControlsItem;
				} default: {
					return [%c(SettingsItem) itemWithTitle:@"ReBoom" value:@"Error" type:1];
				}
			}
		} case 2: {
			switch (indexPath.row) {
				case 0: {
					replayItem = [%c(SettingsItem) itemWithTitle:@"Replay Mode" value:(getPrefBool(@"TASMode") ? @"Enabled" : @"Disabled") type:1];
					replayItem.reboomValue = @"TASMode";
					return replayItem;
				} case 1: {
					recordItem = [%c(SettingsItem) itemWithTitle:@"Record Mode" value:(getPrefBool(@"RecordMode") ? @"Enabled" : @"Disabled") type:1];
					recordItem.reboomValue = @"RecordMode";
					return recordItem;
				} default: {
					return [%c(SettingsItem) itemWithTitle:@"ReBoom" value:@"Error" type:1];
				}
			}
		} case 3: {
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
%property (strong) NSString *reboomValue;
-(void)activate {
	// If it is one of our options
	if (self.reboomValue) {
		if ([[[self valueForKey:@"valueLabel"] valueForKey:@"string_"] isEqualToString:@"Enabled"]) {
			setPrefBool(self.reboomValue, NO);
			[self setValue:@"Disabled"];
		} else {
			setPrefBool(self.reboomValue, YES);
			[self setValue:@"Enabled"];

			// Make the replay mode button and record mode button conflict (so you can only have one enabled at once)
			if (self == replayItem && [[[recordItem valueForKey:@"valueLabel"] valueForKey:@"string_"] isEqualToString:@"Enabled"]) {
				[recordItem activate];
			} else if (self == recordItem && [[[replayItem valueForKey:@"valueLabel"] valueForKey:@"string_"] isEqualToString:@"Enabled"]) {
				[replayItem activate];
			}
		}
	} else if (self == levelURLItem) {
		HSAlertView *alertView = [[%c(HSAlertView) alloc] initWithTitle:@"Custom Level URL"  message:nil delegate:[[%c(HSAlertView) alloc] init] cancelButtonTitle:@"Cancel" otherButtonTitles:@"Save", nil];
		alertView.style = 1; // style with textfield
		alertView.inputTextField.placeholder = @"Leave blank to disable";
		[alertView show];
	} else if (self == repoItem) {
		UIViewController *gameVC = [[[UIApplication sharedApplication] keyWindow] rootViewController];
		if ([gameVC isKindOfClass:objc_getClass("CustomNavigationViewController")]) {
			CustomNavigationViewController *vc = (CustomNavigationViewController *)gameVC;
			UITableView *tableView = [[UITableView alloc] initWithFrame:[[UIScreen mainScreen] bounds] style:0];
			tableView.delegate = vc;
			tableView.dataSource = vc;
			[gameVC.view addSubview:tableView];

			// probably a much better way to do this but it's 3am and i can't think of it
			dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{ // background thread so it doesn't block the main thread
				while (!vc.selectedCustomLevel) usleep(100000); // wait until not nil
				dispatch_async(dispatch_get_main_queue(), ^{ // go back to the main thread
					NSUserDefaults *preferences = [[NSUserDefaults alloc] initWithSuiteName:DEFAULTS_NAME];
					[preferences setObject:[NSString stringWithFormat:@"https://raw.githubusercontent.com/iCrazeiOS/ReBoom-Levels/main/Levels/%@.plhs", vc.selectedCustomLevel[@"filename"]] forKey:@"CustomLevelURL"];
					[levelURLItem setValue:vc.selectedCustomLevel[@"display_name"]]; // set button text to level name

					vc.selectedCustomLevel = nil; // reset
				});
			});
		}
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
	if ([string hasPrefix:@"Boom! version "]) { // replace original labels
		string = @"";
		// loop through each of our labels
		NSArray *customLabels = @[@"Miscellaneous:", @"TAS Tools:", @"ReBoom by @iCrazeiOS\nThanks to Banana, Mac & lachylegend", @"ReBoom v1.0"];
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
	NSString *customName = nil;
	if ([view.title isEqualToString:@"ReBoom"] && index == 1) { // only matches the "save TAS" alert
		// save TAS recording to file   ( Boom/Documents/{levelID}.btas )
		NSURL *path = [NSURL URLWithString: [NSString stringWithFormat:@"%@%@%@", [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] firstObject], [[%c(TrialSession) currentSession] levelId], TAS_EXT]];
		[recording writeToURL:path atomically:NO encoding:NSASCIIStringEncoding error:NULL];
		showAlert(@"TAS recording has been saved!", @"Dismiss");
	} else if ([view.title isEqualToString:@"Custom Level URL"] && index == 1) {
		NSString *levelURL = view.inputTextField.text;
		if (![levelURL isEqualToString:@""]) {
			// if no protocol is specified, prepend https://
			if (![levelURL hasPrefix:@"http"]) levelURL = [@"https://" stringByAppendingString:levelURL]; // all sites should be using https by now. many will refuse http, so I will be forcing a https prefix if no protocol is provided

			// verify that the URL is valid
			NSData *data = [NSData dataWithContentsOfURL:[NSURL URLWithString:levelURL]];
			if (data) { // url fetched successfully
				NSDictionary *plistDict = [NSPropertyListSerialization propertyListWithData:data options:NSPropertyListImmutable format:NULL error:NULL];
				if ([plistDict objectForKey:@"SPRITES_INFO"]) { // valid level
					if ([plistDict objectForKey:@"CustomLevelName"]) customName = [plistDict objectForKey:@"CustomLevelName"];
				} else { // invalid level
					showAlert(@"Error: The URL you provided does not seem to be a valid level", @"Dismiss");
					return;
				}
			} else { // failed to fetch url
				showAlert(@"Error: The URL you provided is not a valid URL (or could not be fetched)", @"Dismiss");
				return;
			}
		}

		// save url
		NSUserDefaults *preferences = [[NSUserDefaults alloc] initWithSuiteName:DEFAULTS_NAME];
		[preferences setObject:levelURL forKey:@"CustomLevelURL"];

		// if empty, setvalue to 'Unset', else if custom name is set, setvalue to that, else setvalue to 'Set'
		[levelURLItem setValue:[levelURL isEqualToString:@""] ? @"Unset" : (customName ?: @"Set")];
	}
}
%end

// When the game loads
%hook AppController
-(BOOL)application:(id)arg1 didFinishLaunchingWithOptions:(id)arg2 {
	// Wait 1.5 seconds
	dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 1.5 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
		// Only show the alert if the user has not seen it before
		if (!getPrefBool(@"HasShownAlert")) {
			setPrefBool(@"HasShownAlert", YES);
			showAlert(@"Welcome to ReBoom. All options can be changed from within the game's settings menu.\n\n(This will not be shown again)", @"Got it!");
		}
	});
	return %orig;
}
%end



%ctor {
	NSString *bundleID = [[NSBundle mainBundle] bundleIdentifier];
	if ([bundleID containsString:@"com.happysprites.boom"] || [bundleID containsString:@"eu.markstam.boomclone"]) %init;
}
