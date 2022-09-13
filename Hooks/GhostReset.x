#import "Headers/GhostReset.h"

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


%hook HSAlertView
-(void)alertView:(HSAlertView *)view clickedButtonAtIndex:(int)index {
	%orig;
	if ([view.title isEqualToString:@"Remove Ghost?"] && index == 0) {
        NSArray *paths = NSSearchPathForDirectoriesInDomains(NSApplicationSupportDirectory, NSUserDomainMask, YES);
        NSString *applicationSupportDirectory = [paths firstObject];
        NSString *ghostPath = [NSString stringWithFormat:@"%@/%@.ghost", applicationSupportDirectory, [[%c(TrialSession) currentSession] levelId]];
        [[NSFileManager defaultManager] removeItemAtPath:ghostPath error:nil];
		[[%c(TrialSession) currentSession] quit];
    }
}
%end



%ctor {
	NSString *bundleID = [[NSBundle mainBundle] bundleIdentifier];
	if (!([bundleID containsString:@"com.happysprites.boom"] || [bundleID containsString:@"eu.markstam.boomclone"])) return;
	%init;
}
