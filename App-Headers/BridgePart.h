/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "LHSprite.h"

@class HSParticleSystemQuad;

__attribute__((visibility("hidden")))
@interface BridgePart : LHSprite {
	BOOL triggered;
	BOOL remove;
	BOOL breakable;
	HSParticleSystemQuad* q;
}
-(void).cxx_destruct;
-(void)postUpdate:(float)update;
-(void)trigger;
-(void)break;
-(void)postInitialization;
-(void)cleanup;
@end

