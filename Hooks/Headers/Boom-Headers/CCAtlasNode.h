/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "CCRGBAProtocol.h"
#import "CCTextureProtocol.h"
#import "Boom-Structs.h"
#import "CCNode.h"

@class CCTextureAtlas, NSString;

__attribute__((visibility("hidden")))
@interface CCAtlasNode : CCNode <CCRGBAProtocol, CCTextureProtocol> {
	CCTextureAtlas* textureAtlas_;
	unsigned itemsPerRow_;
	unsigned itemsPerColumn_;
	unsigned itemWidth_;
	unsigned itemHeight_;
	unsigned quadsToDraw_;
	ccBlendFunc blendFunc_;
	unsigned char opacity_;
	ccColor3B color_;
	ccColor3B colorUnmodified_;
	BOOL opacityModifyRGB_;
	int uniformColor_;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(assign, nonatomic) unsigned quadsToDraw;
@property(assign, nonatomic) ccColor3B color;
@property(assign, nonatomic) unsigned char opacity;
@property(assign, nonatomic) ccBlendFunc blendFunc;
@property(retain, nonatomic) CCTextureAtlas* textureAtlas;
+(id)atlasWithTileFile:(id)tileFile tileWidth:(unsigned)width tileHeight:(unsigned)height itemsToRender:(unsigned)render;
-(id)texture;
-(void)setTexture:(id)texture;
-(void)updateBlendFunc;
-(void)updateOpacityModifyRGB;
-(BOOL)doesOpacityModifyRGB;
-(void)setOpacityModifyRGB:(BOOL)rgb;
-(void)draw;
-(void)updateAtlasValues;
-(void)calculateMaxItems;
-(void)dealloc;
-(id)initWithTileFile:(id)tileFile tileWidth:(unsigned)width tileHeight:(unsigned)height itemsToRender:(unsigned)render;
-(id)init;
@end
