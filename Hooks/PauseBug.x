/*
	'Unpatch' the 'Pause Bug'.
	It can be used to skip parts of certain levels.

	Read more about the bug here: https://boomhappysprites.fandom.com/wiki/The_Pause_Bug
*/

#import "Headers/Common.h"

%hook TrialSession
-(void)pauseSchedulerAndActionsRecursive:(id)recursive {
	if (!getPrefBool(@"PauseBug")) %orig; 
}

-(void)resumeSchedulerAndActionsRecursive:(id)recursive {
	if (!getPrefBool(@"PauseBug")) %orig; 
}
%end



%ctor {
	NSString *bundleID = [[NSBundle mainBundle] bundleIdentifier];
	if ([bundleID containsString:@"com.happysprites.boom"] || [bundleID containsString:@"eu.markstam.boomclone"]) %init;
}
