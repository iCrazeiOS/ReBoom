/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "NSCopying.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class NSMutableArray;

__attribute__((visibility("hidden")))
@interface CCPointArray : XXUnknownSuperclass <NSCopying> {
	NSMutableArray* controlPoints_;
}
@property(retain, nonatomic) NSMutableArray* controlPoints;
+(id)arrayWithCapacity:(unsigned)capacity;
-(void)reverseInline;
-(id)reverse;
-(unsigned)count;
-(void)removeControlPointAtIndex:(unsigned)index;
-(void)replaceControlPoint:(CGPoint)point atIndex:(unsigned)index;
-(CGPoint)getControlPointAtIndex:(int)index;
-(void)insertControlPoint:(CGPoint)point atIndex:(unsigned)index;
-(void)addControlPoint:(CGPoint)point;
-(void)dealloc;
-(id)copyWithZone:(NSZone*)zone;
-(id)initWithCapacity:(unsigned)capacity;
-(id)init;
@end

