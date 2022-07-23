#import <UIKit/UIKit.h>
#import "App-Headers/HSAlertView.h"

BOOL LOGS_ENABLED = NO;

#define TAS_EXT @".btas"
#define FIXED_DELTA (1.0f / 60.0f)
#define SERVER_HOST @"https://boom.markstam.eu"

@interface TrialHUD : NSObject
-(void)hideTouchControls:(BOOL)hide;
@end

@interface TrialSession : NSObject
@property(assign, nonatomic) BOOL paused;
+(id)currentSession;
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
-(void)quit;
-(NSString *)levelId;
-(void)restartLevel;
-(TrialHUD *)hud;
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

@interface LevelSign : NSObject
@property(nonatomic, assign) int selected_time;
@end

@interface CCLabelTTF : NSObject
@property (nonatomic,copy) NSString *string;
@end

@interface SettingsItem () {
	CCLabelTTF *titleLabel;
}
@end



/* TAS Stuff */

struct Movie {
	int length;
	NSMutableArray* commands;
};
Movie tas;
NSMutableString* recording;
unsigned long frameID, lastFrameID = 0;





@interface FLEXManager : NSObject
+(id)sharedManager;
-(void)toggleExplorer;
@end
