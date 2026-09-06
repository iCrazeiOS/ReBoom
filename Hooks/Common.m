/*
	Some common functions used by the rest of the tweak.
*/

#import "Headers/Common.h"

// Get pref value
BOOL getPrefBool(NSString *key) {
	NSUserDefaults *preferences = [NSUserDefaults standardUserDefaults];
	return [preferences boolForKey:[NSString stringWithFormat:@"reboom_%@", key]];
}

// Set pref value
void setPrefBool(NSString *key, BOOL value) {
	NSUserDefaults *preferences = [NSUserDefaults standardUserDefaults];
	[preferences setBool:value forKey:[NSString stringWithFormat:@"reboom_%@", key]];
}

// Show the game's custom alert view
void showAlert(NSString *message, NSString *buttonText) {
	HSAlertView *alertView = [[objc_getClass("HSAlertView") alloc] initWithTitle:@"ReBoom" message:message delegate:nil cancelButtonTitle:buttonText otherButtonTitles:nil];
	alertView.delegate = alertView;
	[alertView show];
}
