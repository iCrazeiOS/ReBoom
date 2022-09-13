/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library
#import "Boom-Structs.h"
#import "CCESRenderer.h"

@class EAGLContext, NSString;

__attribute__((visibility("hidden")))
@interface CCES2Renderer : XXUnknownSuperclass <CCESRenderer> {
	int backingWidth_;
	int backingHeight_;
	unsigned samplesToUse_;
	BOOL multiSampling_;
	unsigned depthFormat_;
	unsigned pixelFormat_;
	unsigned defaultFramebuffer_;
	unsigned colorRenderbuffer_;
	unsigned depthBuffer_;
	unsigned msaaFramebuffer_;
	unsigned msaaColorbuffer_;
	EAGLContext* context_;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(readonly, assign, nonatomic) EAGLContext* context;
@property(readonly, assign, nonatomic) unsigned msaaColorbuffer;
@property(readonly, assign, nonatomic) unsigned msaaFramebuffer;
@property(readonly, assign, nonatomic) unsigned defaultFramebuffer;
@property(readonly, assign, nonatomic) unsigned colorRenderbuffer;
-(void)dealloc;
-(unsigned)msaaColorBuffer;
-(unsigned)msaaFrameBuffer;
-(unsigned)defaultFrameBuffer;
-(unsigned)colorRenderBuffer;
-(CGSize)backingSize;
-(BOOL)resizeFromLayer:(id)layer;
-(id)initWithDepthFormat:(unsigned)depthFormat withPixelFormat:(unsigned)pixelFormat withSharegroup:(id)sharegroup withMultiSampling:(BOOL)multiSampling withNumberOfSamples:(unsigned)samples;
@end
