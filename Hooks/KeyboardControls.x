/*
	Adds keyboard support for people playing the game on Apple Silicon Macs.
	Should also support iPads with keyboards connected, but I don't have one to test with.
*/

#import "Headers/KeyboardControls.h"

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
	if ([bundleID containsString:@"com.happysprites.boom"] || [bundleID containsString:@"eu.markstam.boomclone"]) %init;
}
