/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "HSOpacityNode.h"
#import "Boom-Structs.h"

@class CCTexture2D;

__attribute__((visibility("hidden")))
@interface HSLine : HSOpacityNode {
	ccV3F_C4B_T2F_Quad* quads_;
	unsigned short* indices_;
	linePoint* points;
	float halfWidth;
	unsigned segments;
	unsigned numPoints;
	unsigned total;
	unsigned VAOname_;
	unsigned buffersVBO_[2];
	BOOL _flippedTexture;
	CCTexture2D* _texture;
	float _width;
	CGPoint pStart;
	CGPoint pEnd;
}
@property(assign, nonatomic) CGPoint pEnd;
@property(assign, nonatomic) CGPoint pStart;
@property(assign, nonatomic) BOOL flippedTexture;
@property(assign, nonatomic) float width;
@property(retain, nonatomic) CCTexture2D* texture;
+(id)lineWithPoints:(unsigned)points segments:(unsigned)segments;
-(void).cxx_destruct;
-(void)setOpacity:(unsigned char)opacity;
-(void)draw;
-(void)generateStrips;
-(void)updateCurve;
-(void)setPoint:(CGPoint)point atIndex:(unsigned)index;
-(void)initVAO;
-(void)dealloc;
-(void)setupIndices;
-(void)updateTexCoords;
-(id)initWithPoints:(unsigned)points segments:(unsigned)segments;
@end
