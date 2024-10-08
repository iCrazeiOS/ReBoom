/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "HSOpacityNode.h"
#import "HSJustify.h"

@class NSString;

__attribute__((visibility("hidden")))
@interface HSAdjustedOpacityNode : HSOpacityNode <HSJustify> {
	CGPoint nonadjustedPosition;
	CGRect clip;
	BOOL clipping;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) NSUInteger hash;
-(void)visit;
-(void)postVisit;
-(void)preVisitWithClippingRect;
-(void)clip:(CGRect)clip;
-(float)relativeScale;
-(void)onEnter;
-(void)justifyRecursive;
-(void)justify;
-(void)setPosition:(CGPoint)position;
@end

