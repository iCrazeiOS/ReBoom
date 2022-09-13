/*
	As the game is no longer on the App Store, the in-app purchase no longer work.
	This replaces the functionality of the 'buy coins' button, and just gives you 10,000 coins.
*/

#import "Headers/StoreDialog.h"

// Replace functionality of "buy coins" button
%hook StoreGetCoinsDialog
-(void)onEnter {
	// Close the dialog immediately
	[self back];
	// Add coins
	[[%c(Player) sharedPlayer] incrementCoins:10000 archive:YES];
}
%end



%ctor {
	NSString *bundleID = [[NSBundle mainBundle] bundleIdentifier];
	if (!([bundleID containsString:@"com.happysprites.boom"] || [bundleID containsString:@"eu.markstam.boomclone"])) return;
	%init;
}
