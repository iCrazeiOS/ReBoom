#import "Common.h"
#import <UIKit/UIKit.h>

static BOOL LOGS_ENABLED = NO;

#define TAS_EXT @".btas"
#define FIXED_DELTA (1.0f / 60.0f)

@interface TrialHUD : NSObject
-(void)hideTouchControls:(BOOL)hide;
@end

@interface TrialSession : NSObject
+(id)currentSession;
-(void)right;
-(void)left;
-(void)stopRight;
-(void)stopLeft;
-(void)startReBoom;
-(BOOL)isChallenge;
-(BOOL)isTournament;
-(void)pause;
-(void)resume;
-(NSString *)levelId;
-(void)restartLevel;
-(TrialHUD *)hud;
@end

@interface HSAdjustedSprite : NSObject
+(id)spriteWithSpriteFrameName:(id)spriteFrameName;
@end

@interface SettingsItem : UITableViewCell
@property (readwrite, assign) NSString *reboomValue;
+(SettingsItem *)itemWithTitle:(NSString *)title value:(NSString *)value type:(int)type;
-(void)setValue:(NSString *)title;
-(void)activate;
-(void)setIcon:(HSAdjustedSprite *)icon;
@end

@interface LevelHandler : NSObject
+(id)sharedInstance;
-(void)unLockNextLevel;
@end

@interface CCLabelTTF : NSObject
@property (nonatomic,copy) NSString *string;
@end

@interface CustomNavigationViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, retain) NSArray *customLevels;
@property (nonatomic, retain) NSDictionary *selectedCustomLevel;
@end



/* TAS Stuff */

struct Movie {
	int length;
	NSMutableArray* commands;
};
struct Movie tas;
NSMutableString* recording;
static unsigned long frameID, lastFrameID = 0;
