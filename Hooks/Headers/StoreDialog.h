#import "Headers/Common.h"

@interface StoreGetCoinsDialog : NSObject
-(void)back;
@end

@interface Player : NSObject
+(Player *)sharedPlayer;
-(void)incrementCoins:(int)coins archive:(BOOL)archive;
@end
