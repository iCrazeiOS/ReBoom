#import <UIKit/UIKit.h>
#import "App-Headers/HSAlertView.h"

BOOL LOGS_ENABLED = NO;

#define TAS_EXT @".btas"
#define FIXED_DELTA (1.0f / 60.0f)

#define SEL(x) performSelector:@selector(x)

// #define MSG0S(rt,r,x,y) ((void(*)(rt, id, SEL))objc_msgSend_stret)(r, x, @selector(y))    // armv7
#define MSG0S(rt,r,x,y) ((void(*)(rt, id, SEL))objc_msgSend)(r, x, @selector(y))	// arm64(e)


/* TAS STRUCT START */

struct Movie {
	int length;

	// each entry (frame) in the array is a NSString of command characters:
	// - left down: l
	// - left up: L
	// - right down: r
	// - right up: R
	// -- example: @"rRrRrRrl"
	NSMutableArray* commands;
};

/* TAS STRUCT END */

/* VARIABLES START */

// everything unlocked variable
id handler;

// TAS global variables
Movie tas;
NSMutableString* recording;
id leftButton, rightButton;
unsigned long frameID, lastFrameID = 0;

/* VARIABLES END */