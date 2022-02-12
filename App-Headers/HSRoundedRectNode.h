/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCNode.h"


__attribute__((visibility("hidden")))
@interface HSRoundedRectNode : CCNode {
	CGSize size;
	float radius;
	ccColor4F borderColor;
	ccColor4F fillColor;
	float lineWidth;
	unsigned cornerSegments;
	float borderWidth;
}
@property(assign, nonatomic) unsigned cornerSegments;
@property(assign, nonatomic) float borderWidth;
@property(assign, nonatomic) ccColor4F fillColor;
@property(assign, nonatomic) ccColor4F borderColor;
@property(assign, nonatomic) float radius;
@property(assign, nonatomic) CGSize size;
-(void)draw;
-(id)initWithRectSize:(CGSize)rectSize;
@end

