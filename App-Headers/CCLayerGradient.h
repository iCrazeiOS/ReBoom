/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCLayerColor.h"


__attribute__((visibility("hidden")))
@interface CCLayerGradient : CCLayerColor {
	ccColor3B endColor_;
	unsigned char startOpacity_;
	unsigned char endOpacity_;
	CGPoint vector_;
	BOOL compressedInterpolation_;
}
@property(assign, nonatomic) BOOL compressedInterpolation;
@property(assign, nonatomic) CGPoint vector;
@property(assign, nonatomic) unsigned char endOpacity;
@property(assign, nonatomic) unsigned char startOpacity;
@property(assign, nonatomic) ccColor3B endColor;
@property(assign, nonatomic) ccColor3B startColor;
+(id)layerWithColor:(ccColor4B)color fadingTo:(ccColor4B)to alongVector:(CGPoint)vector;
+(id)layerWithColor:(ccColor4B)color fadingTo:(ccColor4B)to;
-(void)updateColor;
-(id)initWithColor:(ccColor4B)color fadingTo:(ccColor4B)to alongVector:(CGPoint)vector;
-(id)initWithColor:(ccColor4B)color fadingTo:(ccColor4B)to;
@end

