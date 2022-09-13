/*

===== IMPORTANT =====

This is sample code demonstrating API, technology or techniques in development.
Although this sample code has been reviewed for technical accuracy, it is not
final. Apple is supplying this information to help you plan for the adoption of
the technologies and programming interfaces described herein. This information
is subject to change, and software implemented based on this sample code should
be tested with final operating system software and final documentation. Newer
versions of this sample code may be provided with future seeds of the API or
technology. For information about updates to this and other developer
documentation, view the New & Updated sidebars in subsequent documentation
seeds.

=====================

File: Texture2D.h
Abstract: Creates OpenGL 2D textures from images or text.

Version: 1.6

Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple Inc.
("Apple") in consideration of your agreement to the following terms, and your
use, installation, modification or redistribution of this Apple software
constitutes acceptance of these terms.  If you do not agree with these terms,
please do not use, install, modify or redistribute this Apple software.

In consideration of your agreement to abide by the following terms, and subject
to these terms, Apple grants you a personal, non-exclusive license, under
Apple's copyrights in this original Apple software (the "Apple Software"), to
use, reproduce, modify and redistribute the Apple Software, with or without
modifications, in source and/or binary forms; provided that if you redistribute
the Apple Software in its entirety and without modifications, you must retain
this notice and the following text and disclaimers in all such redistributions
of the Apple Software.
Neither the name, trademarks, service marks or logos of Apple Inc. may be used
to endorse or promote products derived from the Apple Software without specific
prior written permission from Apple.  Except as expressly stated in this notice,
no other rights or licenses, express or implied, are granted by Apple herein,
including but not limited to any patent rights that may be infringed by your
derivative works or by other works in which the Apple Software may be
incorporated.

The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO
WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED
WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE OR IN
COMBINATION WITH YOUR PRODUCTS.

IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION AND/OR
DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF
CONTRACT, TORT (INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF
APPLE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Copyright (C) 2008 Apple Inc. All Rights Reserved.

*/

#import <Foundation/Foundation.h> //	for NSObject

#import "ccTypes.h"
#import "ccMacros.h"


#if __CC_METAL_SUPPORTED_AND_ENABLED
#import <Metal/Metal.h>
#endif

#import "CCGL.h" // OpenGL stuff
#import "CCNS.h" // Next-Step stuff

@class CCSpriteFrame;

/**
 *  Possible texture pixel formats. Used by various rendering components, including CCTexture, CCRenderTexture, CCEffectNode.
 */
typedef NS_ENUM(NSUInteger, CCTexturePixelFormat) {
    
	///! 32-bit texture: RGBA8888
	CCTexturePixelFormat_RGBA8888,
    
	///! 32-bit texture without Alpha channel. Don't use it.
	CCTexturePixelFormat_RGB888,
    
	///! 16-bit texture without Alpha channel
	CCTexturePixelFormat_RGB565,
    
	///! 8-bit textures used as masks
	CCTexturePixelFormat_A8,
    
	///! 8-bit intensity texture
	CCTexturePixelFormat_I8,
    
	///! 16-bit textures used as masks
	CCTexturePixelFormat_AI88,
    
	///! 16-bit textures: RGBA4444
	CCTexturePixelFormat_RGBA4444,
    
	///! 16-bit textures: RGB5A1
	CCTexturePixelFormat_RGB5A1,
    
	///! 4-bit PVRTC-compressed texture: PVRTC4
	CCTexturePixelFormat_PVRTC4,
    
	///! 2-bit PVRTC-compressed texture: PVRTC2
	CCTexturePixelFormat_PVRTC2,

	///! 32-bit texture: BGRA8888
	CCTexturePixelFormat_BGRA8888,
    
	///! Default texture format: RGBA8888
	CCTexturePixelFormat_Default = CCTexturePixelFormat_RGBA8888,
};

/*
 Extension to set the Min / Mag filter
 */
typedef struct _ccTexParams {
    GLuint	minFilter;
    GLuint	magFilter;
    GLuint	wrapS;
    GLuint	wrapT;
} ccTexParams;


@class CCShader;

// Proxy object returned in place of a CCTexture or CCSpriteFrame by the texture cache.
// Weakly retained by the original object, so it can be know if the object is referenced when a memory warning arrives.
// This is used as a temporary fix for the texture cache until asset loading can be refactored better.
@interface CCProxy : NSObject

- (id)initWithTarget:(id)target;

@end

/**
 Represents a texture, an in-memory representation of an image in a compatible format the graphics processor can process.
 
 Allows to create OpenGL textures from image files, text (font rendering) and raw data.

 @note Be aware that the content of the generated texture will be upside-down! This is an OpenGL oddity.
 */
@interface CCTexture : NSObject

/// -----------------------------------------------------------------------
/// @name Creating a Texture
/// -----------------------------------------------------------------------

/**
 *  Initializes and returns a texture object using the specified data, pixelFormat, width, height, sizeInPixels and contentScale values.
 *
 *  @param data         Pointer to a buffer containing the raw data.
 *  @param pixelFormat  Pixelformat of the data
 *  @param width        Width if the texture
 *  @param height       Height of the texture
 *  @param sizeInPixels Size of resulting texture.
 *  @param contentScale Content scale.
 *
 *  @return An initialized CCTexture Object.
 *  @see CCTexturePixelFormat
 */
- (id)initWithData:(const void*)data pixelFormat:(CCTexturePixelFormat)pixelFormat pixelsWide:(NSUInteger)width pixelsHigh:(NSUInteger)height contentSizeInPixels:(CGSize)sizeInPixels contentScale:(CGFloat)contentScale;

/**
 *  Creates and returns a new texture, based on the specified image file path.
 *
 *  If the texture has already been loaded, and resides in the internal cache, the previously created texture is returned from the cache.
 *  While this is fast, it still has an overhead compared to manually caching textures in an ivar or property.
 *
 *  @param file File path to load (should not include any suffixes).
 *
 *  @return The CCTexture object.
 */
+(instancetype)textureWithFile:(NSString*)file;

/** A placeholder value for a blank sizeless texture.
 @return An empty texture. */
+(instancetype)none;

/// -------------------------------------------------------
/// @name Creating a Sprite Frame
/// -------------------------------------------------------

/**
 *  Creates a sprite frame from the texture.
 *
 *  @return A new sprite frame.
 *  @see CCSpriteFrame
 */
-(CCSpriteFrame*)createSpriteFrame;

/// -------------------------------------------------------
/// @name Texture Format and Size
/// -------------------------------------------------------

/** Pixel format of the texture.
 @see CCTexturePixelFormat */
@property(nonatomic,readonly) CCTexturePixelFormat pixelFormat;

/** Width in pixels. */
@property(nonatomic,readonly) NSUInteger pixelWidth;

/** Height in pixels. */
@property(nonatomic,readonly) NSUInteger pixelHeight;

/** Returns the content size of the texture in points. */
-(CGSize)contentSize;

/** Returns content size of the texture in pixels. */
@property(nonatomic,readonly, nonatomic) CGSize contentSizeInPixels;

/** Returns the contentScale of the texture.
 In general "HD" textures return a contentScale of 2.0, while non-HD textures return 1.0.
 
 Loading behavior is changed by [CCFileUtils set*ContentScaleFactor:]. The value can be changed manually if you want to force a certain content scale.
 */
@property(nonatomic, readwrite) CGFloat contentScale;

/// -------------------------------------------------------
/// @name Texture Settings
/// -------------------------------------------------------

/** Whether or not the texture has their Alpha premultiplied. */
@property(nonatomic,readwrite) BOOL premultipliedAlpha;

/** True if antialised. */
@property(nonatomic,assign,getter=isAntialiased) BOOL antialiased;

/* texture name */
@property(nonatomic,readonly) GLuint name;

// TODO This should really be split into a separate subclass somehow.
#if __CC_METAL_SUPPORTED_AND_ENABLED
@property(nonatomic,readonly) id<MTLTexture> metalTexture;
@property(nonatomic,readonly) id<MTLSamplerState> metalSampler;
#endif

/* texture max S */
@property(nonatomic,readwrite) GLfloat maxS;
/* texture max T */
@property(nonatomic,readwrite) GLfloat maxT;

// Check if the texture's weakly retained proxy still exists.
@property(atomic, readonly) BOOL hasProxy;

// Retrieve the proxy for this texture.
@property(atomic, readonly, weak) CCProxy *proxy;


/* These functions are needed to create mutable textures */
- (void) releaseData:(void*)data;
- (void*) keepData:(void*)data length:(NSUInteger)length;

@end

#pragma mark - Image
/**
 *  Extensions to make it easy to create a CCTexture2D object from an image file.
 *  Note that RGBA type textures will have their alpha premultiplied - use the blending mode (GL_ONE, GL_ONE_MINUS_SRC_ALPHA).
 */
@interface CCTexture (CGImage)

/**
 *  Initializes and returns a texture from a CGImage object.
 *
 *  @param cgImage      CGImage to use for texture
 *  @param contentScale Content scale.
 *
 *  @return An initialized CCTexture object.
 */
- (id)initWithCGImage:(CGImageRef)cgImage contentScale:(CGFloat)contentScale;

@end

#pragma mark - PixelFormat
@interface CCTexture (PixelFormat)
/** 
 * Sets the default pixel format for CGImages that contains alpha channel.
 *
 * How does it work ?
 * If the image is an RGBA (with Alpha) then the default pixel format will be used (it can be a 8-bit, 16-bit or 32-bit texture).
 * If the image is an RGB (without Alpha) then: If the default pixel format is RGBA8888 then a RGBA8888 (32-bit) will be used. Otherwise a RGB565 (16-bit texture) will be used.
 *
 * This parameter is not valid for PVR / PVR.CCZ images.
 *
 *  @param format Format to use with texture.
 *  @see CCTexturePixelFormat
 */
+(void)setDefaultAlphaPixelFormat:(CCTexturePixelFormat)format;

/**
 *  Returns the alpha pixel format.
 *
 *  @return The pixel format.
 *  @see CCTexturePixelFormat
 */
+(CCTexturePixelFormat)defaultAlphaPixelFormat;

/**
 *  Returns the bits-per-pixel of the in-memory OpenGL texture.
 *
 *  @return Number of bits per pixel.
 */
-(NSUInteger)bitsPerPixelForFormat;

/** Returns the pixel format in a NSString. */
-(NSString*)stringForFormat;

/**
 *  Helper functions that returns bits per pixels for a given format.
 *
 *  @param format Format to query for pixelsize.
 *
 *  @return Number of bits for pixelformat.
 *  @see CCTexturePixelFormat
 */
+(NSUInteger)bitsPerPixelForFormat:(CCTexturePixelFormat)format;

@end

/*
 Extensions to make it easy to create a CCTexture2D object from a PVRTC file
 Note that the generated textures don't have their alpha premultiplied - use the blending mode (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA).
 */
@interface CCTexture (PVRSupport)
/* Initializes a texture from a PVR file.
 
 Supported PVR formats:
 - BGRA 8888
 - RGBA 8888
 - RGBA 4444
 - RGBA 5551
 - RBG 565
 - A 8
 - I 8
 - AI 8
 - PVRTC 2BPP
 - PVRTC 4BPP
 
 By default PVR images are treated as if they alpha channel is NOT premultiplied. You can override this behavior with this class method:
 - PVRImagesHavePremultipliedAlpha:(BOOL)haveAlphaPremultiplied;
 
 IMPORTANT: This method is only defined on iOS. It is not supported on the Mac version.
 
 */
-(id) initWithPVRFile: (NSString*) file;

/* treats (or not) PVR files as if they have alpha premultiplied.
 Since it is impossible to know at runtime if the PVR images have the alpha channel premultiplied, it is
 possible load them as if they have (or not) the alpha channel premultiplied.
 
 By default it is disabled.
 
 */
+(void) PVRImagesHavePremultipliedAlpha:(BOOL)haveAlphaPremultiplied;

@end

@interface CCTexture (GLFilter)
/* sets the min filter, mag filter, wrap s and wrap t texture parameters.
 If the texture size is NPOT (non power of 2), then in can only use GL_CLAMP_TO_EDGE in GL_TEXTURE_WRAP_{S,T}.
 
 @warning Calling this method could allocate additional texture memory.
 
 */
-(void) setTexParameters: (ccTexParams*) texParams;

/* Generates mipmap images for the texture.
 It only works if the texture size is POT (power of 2).
 */
-(void) generateMipmap;

@end





