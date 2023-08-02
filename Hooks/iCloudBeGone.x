/*
	Disables iCloud / Game Center integration.
*/

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
