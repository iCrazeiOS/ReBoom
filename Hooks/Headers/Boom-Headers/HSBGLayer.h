/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library


__attribute__((visibility("hidden")))
@interface HSBGLayer : XXUnknownSuperclass {
	CGPoint ratio_;
	float scaleRatio_;
	CGPoint offset_;
	CGPoint speed_;
	float spriteWidth_;
	ccArray* children_;
}
@property(readonly, assign, nonatomic) ccArray* children;
@property(assign, nonatomic) float spriteWidth;
@property(assign, nonatomic) CGPoint speed;
@property(assign, nonatomic) CGPoint offset;
@property(assign, nonatomic) float scaleRatio;
@property(assign, nonatomic) CGPoint ratio;
+(id)bgLayerWithCGPoint:(CGPoint)cgpoint offset:(CGPoint)offset capacity:(unsigned)capacity;
-(void)dealloc;
-(id)initWithCGPoint:(CGPoint)cgpoint offset:(CGPoint)offset capacity:(unsigned)capacity;
@end

