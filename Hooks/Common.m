#import "Headers/Common.h"

// Get pref value
BOOL getPrefBool(NSString *key) {
	NSUserDefaults *preferences = [[NSUserDefaults alloc] initWithSuiteName:DEFAULTS_NAME];
	return [preferences boolForKey:key];
}

// Set pref value
void setPrefBool(NSString *key, BOOL value) {
	NSUserDefaults *preferences = [[NSUserDefaults alloc] initWithSuiteName:DEFAULTS_NAME];
	[preferences setBool:value forKey:key];
}

// Show the game's custom alert view
void showAlert(NSString *message, NSString *buttonText) {
	HSAlertView *delegate = [[objc_getClass("HSAlertView") alloc] init];
	HSAlertView *alertView = [[objc_getClass("HSAlertView") alloc] initWithTitle:@"ReBoom" message:message delegate:delegate cancelButtonTitle:buttonText otherButtonTitles:nil];
	[alertView show];
}
