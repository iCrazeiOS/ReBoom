/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class CCTexture2D;

__attribute__((visibility("hidden")))
@interface CCTextureAtlas : XXUnknownSuperclass {
	unsigned totalQuads_;
	unsigned capacity_;
	ccV3F_C4B_T2F_Quad* quads_;
	unsigned short* indices_;
	CCTexture2D* texture_;
	unsigned VAOname_[2];
	unsigned buffersVBO_[4];
	unsigned currentBuffer;
	BOOL dirty_[2];
	BOOL allDirty_[2];
	unsigned minDirty_[2];
	unsigned maxDirty_[2];
}
@property(assign, nonatomic) ccV3F_C4B_T2F_Quad* quads;
@property(retain, nonatomic) CCTexture2D* texture;
@property(readonly, assign, nonatomic) unsigned capacity;
@property(readonly, assign, nonatomic) unsigned totalQuads;
+(id)textureAtlasWithTexture:(id)texture capacity:(unsigned)capacity;
+(id)textureAtlasWithFile:(id)file capacity:(unsigned)capacity;
-(void)drawNumberOfQuads:(unsigned)quads fromIndex:(unsigned)index;
-(void)drawNumberOfQuads:(unsigned)quads;
-(void)drawQuads;
-(void)moveQuadsFromIndex:(unsigned)index to:(unsigned)to;
-(void)increaseTotalQuadsWith:(unsigned)with;
-(void)fillWithEmptyQuadsFromIndex:(unsigned)index amount:(unsigned)amount;
-(BOOL)resizeCapacity:(unsigned)capacity;
-(void)removeAllQuads;
-(void)removeQuadsAtIndex:(unsigned)index amount:(unsigned)amount;
-(void)removeQuadAtIndex:(unsigned)index;
-(void)moveQuadsFromIndex:(unsigned)index amount:(unsigned)amount atIndex:(unsigned)index3;
-(void)insertQuadFromIndex:(unsigned)index atIndex:(unsigned)index2;
-(void)insertQuads:(ccV3F_C4B_T2F_Quad*)quads atIndex:(unsigned)index amount:(unsigned)amount;
-(void)insertQuad:(ccV3F_C4B_T2F_Quad*)quad atIndex:(unsigned)index;
-(void)updateQuad:(ccV3F_C4B_T2F_Quad*)quad atIndex:(unsigned)index;
-(void)mapBuffers;
-(void)setupDualVBOandVAO;
-(void)setupIndices;
-(void)dealloc;
-(id)description;
-(id)initWithTexture:(id)texture capacity:(unsigned)capacity;
-(id)initWithFile:(id)file capacity:(unsigned)capacity;
@end

