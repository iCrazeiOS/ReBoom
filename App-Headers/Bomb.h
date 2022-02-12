/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "HSB2QueryCallbackDelegate.h"
#import "HSB2RaycastListenerDelegate.h"
#import "LHSprite.h"

@class HSParticleSystemQuad, NSString, CCAction;

__attribute__((visibility("hidden")))
@interface Bomb : LHSprite <HSB2QueryCallbackDelegate, HSB2RaycastListenerDelegate> {
	HSB2RaycastListener* Object313;
	b2Fixture* reportedFixture;
	b2Fixture* blockingFixture;
	b2Vec2 blockingPoint;
	b2Fixture* bombFixture;
	BOOL lineOfSight;
	HSParticleSystemQuad* fuse;
	b2Vec2 totalImpulse;
	float totalVelocity;
	float maxImpulse;
	float imp0;
	float imp1;
	float imp2;
	float imp3;
	BOOL exploded;
	CCAction* shakeAction;
	unsigned blowEffectStep;
	BOOL wheelyIsMummy;
	BOOL triggered;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(readonly, assign) BOOL exploded;
@property(readonly, assign) BOOL triggered;
-(id).cxx_construct;
-(void).cxx_destruct;
-(void)setPosition:(CGPoint)position rotation:(float)rotation;
-(float)ReportFixture:(b2Fixture*)fixture point:(const b2Vec2*)point normal:(const b2Vec2*)normal fraction:(float)fraction;
-(bool)ReportFixture:(b2Fixture*)fixture;
-(void)applyImpulse:(id)impulse;
-(void)blow;
-(void)blowEffect1;
-(void)blowEffect2;
-(void)blowEffect3;
-(void)explosionDone;
-(void)postUpdate:(float)update;
-(void)addVelocity:(float)velocity;
-(void)addImpulse:(float)impulse;
-(void)trigger:(BOOL)trigger;
-(void)setShake:(float)shake;
-(void)addFuse;
-(void)postInitialization;
-(void)updateFuse;
-(void)cleanup;
@end

