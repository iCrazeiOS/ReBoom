#import "Headers/Common.h"

// disable iCloud
%hook Player
-(BOOL)switchToICloudPlayer:(id)icloudPlayer {
	return NO;
}
%end

// Disable Game Center
%hook HSGameCenterManager
+(BOOL)isAvailable {
	return NO;
}
%end



%ctor {
	NSString *bundleID = [[NSBundle mainBundle] bundleIdentifier];
	if (!([bundleID containsString:@"com.happysprites.boom"] || [bundleID containsString:@"eu.markstam.boomclone"])) return;
	%init;
}
