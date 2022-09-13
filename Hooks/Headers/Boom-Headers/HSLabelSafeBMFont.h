/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "HSJustify.h"
#import "CCLabelBMFont.h"

@class NSString;

__attribute__((visibility("hidden")))
@interface HSLabelSafeBMFont : CCLabelBMFont <HSJustify> {
	CGPoint nonadjustedPosition;
	CGRect clip;
	BOOL clipping;
	BOOL noJustifyOnEnter;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(assign, nonatomic) BOOL noJustifyOnEnter;
-(void)visit;
-(void)postVisit;
-(void)preVisitWithClippingRect;
-(void)clip:(CGRect)clip;
-(float)relativeScale;
-(void)onEnter;
-(void)setPosition:(CGPoint)position;
-(void)justifyRecursive;
-(void)justify;
-(void)createFontChars;
@end
