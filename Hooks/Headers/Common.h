#import <UIKit/UIKit.h>
#import "Boom-Headers/HSAlertView.h"
#import <objc/runtime.h>

// functions defined in Common.m
#ifndef FUNCTIONS_INCLUDED
#define FUNCTIONS_INCLUDED
BOOL getPrefBool(NSString *key);
void setPrefBool(NSString *key, BOOL value);
void showAlert(NSString *message, NSString *buttonText);
#endif
