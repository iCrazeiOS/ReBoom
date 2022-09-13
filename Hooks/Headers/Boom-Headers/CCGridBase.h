/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library
#import "Boom-Structs.h"

@class CCTexture2D, CCGLProgram, CCGrabber;

__attribute__((visibility("hidden")))
@interface CCGridBase : XXUnknownSuperclass {
	BOOL active_;
	int reuseGrid_;
	ccGridSize gridSize_;
	CCTexture2D* texture_;
	CGPoint step_;
	CCGrabber* grabber_;
	BOOL isTextureFlipped_;
	CCGLProgram* shaderProgram_;
	int directorProjection_;
}
@property(assign, nonatomic) CCGLProgram* shaderProgram;
@property(assign, nonatomic) BOOL isTextureFlipped;
@property(retain, nonatomic) CCGrabber* grabber;
@property(retain, nonatomic) CCTexture2D* texture;
@property(assign, nonatomic) CGPoint step;
@property(readonly, assign, nonatomic) ccGridSize gridSize;
@property(assign, nonatomic) int reuseGrid;
@property(assign, nonatomic) BOOL active;
+(id)gridWithSize:(ccGridSize)size;
+(id)gridWithSize:(ccGridSize)size texture:(id)texture flippedTexture:(BOOL)texture3;
-(void)calculateVertexPoints;
-(void)reuse;
-(void)blit;
-(void)afterDraw:(id)draw;
-(void)beforeDraw;
-(void)set2DProjection;
-(void)dealloc;
-(id)description;
-(id)initWithSize:(ccGridSize)size;
-(id)initWithSize:(ccGridSize)size texture:(id)texture flippedTexture:(BOOL)texture3;
@end
