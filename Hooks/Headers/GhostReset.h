#import <UIKit/UIKit.h>
#import "Boom-Headers/HSAlertView.h"

@interface TrialSession : NSObject
+(id)currentSession;
-(void)quit;
-(NSString *)levelId;
@end

@interface LevelSign : NSObject
@property(nonatomic, assign) int selected_time;
@end
