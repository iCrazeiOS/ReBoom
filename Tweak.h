#import <UIKit/UIKit.h>
#import "App-Headers/HSAlertView.h"

BOOL LOGS_ENABLED = NO;

#define TAS_EXT @".btas"
#define FIXED_DELTA (1.0f / 60.0f)

// #define MSG0S(rt,r,x,y) ((void(*)(rt, id, SEL))objc_msgSend_stret)(r, x, @selector(y))    // armv7
#define MSG0S(rt,r,x,y) ((void(*)(rt, id, SEL))objc_msgSend)(r, x, @selector(y))	// arm64(e)

@interface TrialSession : NSObject
-(void)right;
-(void)left;
-(void)stopRight;
-(void)stopLeft;
-(void)start_reboom;
-(BOOL)isChallenge;
-(BOOL)isTournament;
-(void)pause;
-(void)resume;
-(id)wheely;
-(NSString *)levelId;
+(id)currentSession;
@end

@interface SettingsItem : UITableViewCell
@property (readwrite, assign) NSString *ReBoom_PrefValue;
+(SettingsItem *)itemWithTitle:(NSString *)title value:(NSString *)value type:(int)type;
-(void)setValue:(NSString *)title;
-(void)selected;
-(void)unselected;
@end

@interface LevelHandler : NSObject
+(id)sharedInstance;
-(void)unLockNextLevel;
@end

@interface StoreGetCoinsDialog : NSObject
-(void)back;
@end

@interface Player : NSObject
+(Player *)sharedPlayer;
-(void)incrementCoins:(int)coins archive:(BOOL)archive;
@end



/* TAS Stuff */

struct Movie {
	int length;
	NSMutableArray* commands;
};
Movie tas;
NSMutableString* recording;
unsigned long frameID, lastFrameID = 0;
