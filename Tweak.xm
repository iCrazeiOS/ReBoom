#import "Tweak.h"

inline bool GetPrefBool(NSString *key) {
	// change this to be <Boom!>/Documents/!prefs.plist
	return [[[NSDictionary dictionaryWithContentsOfFile:@"/var/mobile/Library/Preferences/com.dtu.reboomprefs.plist"] valueForKey:key] boolValue];
}

void showAlert(NSString *message, NSString *buttonText) {
	HSAlertView *delegate = [[%c(HSAlertView) alloc] init]; 
	HSAlertView *alertView = [[%c(HSAlertView) alloc] initWithTitle:@"ReBoom" message:message delegate:delegate cancelButtonTitle:buttonText otherButtonTitles:nil];
	alertView.cancelButtonIndex = 0;
	[alertView show];
}

// TAS MODE
void loadMovie(NSString *name) {
	if (LOGS_ENABLED) NSLog(@"Loading TAS recording with name: %@", name);
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
%hook TrialSession
-(void)restartLevel {
	%orig;

	// unlock next level
	if (GetPrefBool(@"EverythingUnlocked")) [handler SEL(unLockNextLevel)];

	// replay mode
	if (GetPrefBool(@"TASMode") && ![self SEL(isChallenge)] && ![self SEL(isTournament)]) {
		if (LOGS_ENABLED) NSLog(@"[TrialSession restartLevel] loading TAS recording...");
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
			if (LOGS_ENABLED) NSLog(@"[HSMenuItem selected] leftButton called");
			if (lastFrameID < frameID + 1) {
				if (LOGS_ENABLED) NSLog(@"[HSMenuItem selected] leftButton appending");
				[recording appendFormat:frameID == 0 ? @"%04lu :" : @"\n%04lu :", frameID + 1];
				lastFrameID = frameID + 1;
			}

			[recording appendString:@" ld"];
		} else if (self == rightButton) {
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


// @interface Settings : UITableView
// @end

// @interface HSUISwitch : NSObject
// +(HSUISwitch *)switchWithState:(id)state offFont:(id)font onFont:(id)font3 onStateChange:(id)change;
// -(HSUISwitch *)initWithState:(id)state offFont:(id)font onFont:(id)font3 onStateChange:(id)change;
// @end

// @interface SettingsItem : UITableViewCell
// +(SettingsItem *)itemWithTitle:(NSString *)title value:(NSString *)value type:(int)type;
// -(void)setTitle:(NSString *)title;
// -(UILabel *)titleLabel;
// -(void)setSwitchElement:(HSUISwitch *)element state:(int)state;
// @property(readonly, assign, nonatomic) HSUISwitch* switchElement;
// @end

// SettingsItem *newItem = [%c(SettingsItem) alloc];

// %hook Settings
// -(NSInteger) numberOfSectionsInTableView:(UITableView*)tableView {
// 	return 2;
// }

// -(int)tableView:(id)view numberOfRowsInSection:(int)section {
// 	return section == 1 ? 1 : %orig;
// }

// -(id)tableView:(id)view cellForRowAtIndexPath:(id)indexPath {
// 	NSIndexPath *index = indexPath;

// 	if (index.section == 1 && index.row == 0) {
// 		newItem = [%c(SettingsItem) itemWithTitle:@"ReBoom" value:@"" type:2];
// 		return newItem;
// 	}
	
// 	return %orig;
// }
// %end

// %hook SettingsItem
// -(id)itemForTouch:(id)touch {
// 	SettingsItem *settingsItem = %orig;
// 	if (settingsItem == newItem) {
// 		[[self titleLabel].text isEqualToString:@"Enabled"] ? [self setTitle:@"Disabled"] : [self setTitle:@"Enabled"];
// 	}
// 	return %orig;
// }
// %end
