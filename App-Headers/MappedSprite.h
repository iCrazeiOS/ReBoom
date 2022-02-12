/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCSprite.h"


__attribute__((visibility("hidden")))
@interface MappedSprite : CCSprite {
	ccV3F_C4B_T2F* mappedVertices;
	unsigned segments;
}
-(void)draw;
-(void)setPoint:(b2Vec2)point forIndex:(unsigned)index;
-(void)setCenter:(b2Vec2)center;
-(void)cleanup;
-(void)configureWithSegments:(unsigned)segments;
@end

