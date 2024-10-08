/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCNode.h"


__attribute__((visibility("hidden")))
@interface LHContactNode : CCNode {
	collisionMapElement* preCollisionMap;
	collisionMapElement* postCollisionMap;
	collisionMapElement* beginEndCollisionMap;
	LHContactListener* lhContactListener;
}
+(id)contactNodeWithWorld:(b2World*)world;
-(void)callListenerWithBodyA:(b2Body*)bodyA bodyB:(b2Body*)b contact:(b2Contact*)contact contactType:(int)type oldManifold:(const b2Manifold*)manifold impulse:(const b2ContactImpulse*)impulse listener:(id)listener selector:(SEL)selector;
-(void)beginEndContact:(b2Contact*)contact isBegin:(bool)begin;
-(void)postSolve:(b2Contact*)solve impulse:(const b2ContactImpulse*)impulse;
-(void)preSolve:(b2Contact*)solve manifold:(const b2Manifold*)manifold;
-(void)handleContact:(b2Contact*)contact contactType:(int)type oldManifold:(const b2Manifold*)manifold impulse:(const b2ContactImpulse*)impulse map:(collisionMapElement*)map;
-(void)cancelPostColisionCallbackBetweenTagA:(int)a andTagB:(int)b;
-(void)registerPostColisionCallbackBetweenTagA:(int)a andTagB:(int)b idListener:(id)listener selListener:(SEL)listener4;
-(void)cancelBeginOrEndColisionCallbackBetweenTagA:(int)a andTagB:(int)b;
-(void)registerBeginOrEndColisionCallbackBetweenTagA:(int)a andTagB:(int)b idListener:(id)listener selListener:(SEL)listener4;
-(void)cancelPreColisionCallbackBetweenTagA:(int)a andTagB:(int)b;
-(void)registerPreColisionCallbackBetweenTagA:(int)a andTagB:(int)b idListener:(id)listener selListener:(SEL)listener4;
-(void)cancelCallbackBetweenTagA:(int)a andTagB:(int)b map:(collisionMapElement*)map;
-(void)registerCallbackBetweenTagA:(int)a andTagB:(int)b map:(collisionMapElement**)map idListener:(id)listener selListener:(SEL)listener5;
-(id)initContactNodeWithWorld:(b2World*)world;
-(void)dealloc;
-(void)purgeMap:(collisionMapElement*)map;
-(void)purgeContactNodes:(contactNodeElement*)nodes;
@end

