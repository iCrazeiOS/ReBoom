/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class NSMutableDictionary, NSString;

__attribute__((visibility("hidden")))
@interface CCTMXLayerInfo : XXUnknownSuperclass {
	NSString* name_;
	CGSize layerSize_;
	unsigned* tiles_;
	BOOL visible_;
	unsigned char opacity_;
	BOOL ownTiles_;
	unsigned minGID_;
	unsigned maxGID_;
	NSMutableDictionary* properties_;
	CGPoint offset_;
}
@property(assign, nonatomic) CGPoint offset;
@property(retain, nonatomic) NSMutableDictionary* properties;
@property(assign, nonatomic) unsigned maxGID;
@property(assign, nonatomic) unsigned minGID;
@property(assign, nonatomic) BOOL ownTiles;
@property(assign, nonatomic) unsigned char opacity;
@property(assign, nonatomic) BOOL visible;
@property(assign, nonatomic) unsigned* tiles;
@property(assign, nonatomic) CGSize layerSize;
@property(retain, nonatomic) NSString* name;
-(void)dealloc;
-(id)init;
@end
