#import <UIKit/UIKit.h>

@interface TrialSession : NSObject
@property(assign, nonatomic) BOOL paused;
+(id)currentSession;
-(void)right;
-(void)left;
-(void)stopRight;
-(void)stopLeft;
-(void)pause;
-(void)resume;
-(void)restartLevel;
@end
