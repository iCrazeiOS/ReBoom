/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Powerup.h"
#import "PowerupProtocol.h"
#import "Boom-Structs.h"

@class Object156;

__attribute__((visibility("hidden")))
@interface RocketPowerup : Powerup <PowerupProtocol> {
	b2Vec2 origin;
	Object156* powerupTarget;
}
+(id)spriteWithBatchNode:(id)batchNode rect:(CGRect)rect;
+(id)spriteWithFile:(id)file rect:(CGRect)rect;
-(void)setPowerupTarget:(id)target;
-(id)powerupTarget;
-(id).cxx_construct;
-(void)cleanup;
-(void)dealloc;
-(void)reSpawn;
-(void)triggerPowerup;
-(void)postInitialization;
-(void)setBounce:(float)bounce;
-(void)rocketInit;
-(id)initWithBatchNode:(id)batchNode rect:(CGRect)rect;
-(id)initWithFile:(id)file rect:(CGRect)rect;
-(id)init;
@end
