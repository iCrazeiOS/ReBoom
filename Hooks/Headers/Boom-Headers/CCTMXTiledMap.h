/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "CCNode.h"
#import "Boom-Structs.h"

@class NSMutableDictionary, NSMutableArray;

__attribute__((visibility("hidden")))
@interface CCTMXTiledMap : CCNode {
	CGSize mapSize_;
	CGSize tileSize_;
	int mapOrientation_;
	NSMutableArray* objectGroups_;
	NSMutableDictionary* properties_;
	NSMutableDictionary* tileProperties_;
}
@property(retain, nonatomic) NSMutableDictionary* properties;
@property(retain, nonatomic) NSMutableArray* objectGroups;
@property(readonly, assign, nonatomic) int mapOrientation;
@property(readonly, assign, nonatomic) CGSize tileSize;
@property(readonly, assign, nonatomic) CGSize mapSize;
+(id)tiledMapWithXML:(id)xml resourcePath:(id)path;
+(id)tiledMapWithTMXFile:(id)tmxfile;
-(id)propertiesForGID:(unsigned)gid;
-(id)propertyNamed:(id)named;
-(id)objectGroupNamed:(id)named;
-(id)layerNamed:(id)named;
-(id)tilesetForLayer:(id)layer map:(id)map;
-(id)parseLayer:(id)layer map:(id)map;
-(void)dealloc;
-(id)initWithTMXFile:(id)tmxfile;
-(id)initWithXML:(id)xml resourcePath:(id)path;
-(void)buildWithMapInfo:(id)mapInfo;
@end
