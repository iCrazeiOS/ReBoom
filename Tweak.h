#import <UIKit/UIKit.h>
#import "App-Headers/HSAlertView.h"

BOOL LOGS_ENABLED = NO;

#define TAS_EXT @".btas"
#define FIXED_DELTA (1.0f / 60.0f)

#define SEL(x) performSelector:@selector(x)

// #define MSG0S(rt,r,x,y) ((void(*)(rt, id, SEL))objc_msgSend_stret)(r, x, @selector(y))    // armv7
#define MSG0S(rt,r,x,y) ((void(*)(rt, id, SEL))objc_msgSend)(r, x, @selector(y))	// arm64(e)

@interface TrialSession : NSObject
-(void)right;
-(void)left;
-(void)stopRight;
-(void)stopLeft;
-(void)start_reboom;
@end

@interface SettingsItem : UITableViewCell
@property (readwrite, assign) NSString *ReBoom_PrefValue;
+(SettingsItem *)itemWithTitle:(NSString *)title value:(NSString *)value type:(int)type;
-(void)setValue:(NSString *)title;
-(void)selected;
-(void)unselected;
@end

/* TAS STRUCT START */

struct Movie {
	int length;
	NSMutableArray* commands;
};

/* TAS STRUCT END */



/* VARIABLES START */

// Used for unlocks
id handler;

// TAS global variables
Movie tas;
NSMutableString* recording;
unsigned long frameID, lastFrameID = 0;

/* VARIABLES END */