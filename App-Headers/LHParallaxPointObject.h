/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class CCNode;

__attribute__((visibility("hidden")))
@interface LHParallaxPointObject : XXUnknownSuperclass {
	CGPoint position;
	CGPoint ratio;
	bool isLHSprite;
	CGPoint initialPosition;
	CCNode* ccsprite;
	b2Body* body;
}
@property(assign) b2Body* body;
@property(assign) CCNode* ccsprite;
@property(assign) CGPoint position;
@property(assign) CGPoint initialPosition;
@property(assign) bool isLHSprite;
@property(assign) CGPoint ratio;
+(id)pointWithCGPoint:(CGPoint)cgpoint;
-(id)initWithCGPoint:(CGPoint)cgpoint;
-(void)dealloc;
@end

