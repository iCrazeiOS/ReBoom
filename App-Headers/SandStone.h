/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "LHSprite.h"


__attribute__((visibility("hidden")))
@interface SandStone : LHSprite {
	BOOL triggered;
}
@property(readonly, assign) BOOL triggered;
-(void)trigger;
-(void)setShake:(float)shake;
-(void)break;
-(void)cleanup;
@end

