/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library
#import "NSXMLParserDelegate.h"
#import "Boom-Structs.h"

@class NSMutableDictionary, NSMutableArray, NSString, NSMutableString;

__attribute__((visibility("hidden")))
@interface CCTMXMapInfo : XXUnknownSuperclass <NSXMLParserDelegate> {
	NSMutableString* currentString;
	BOOL storingCharacters;
	int layerAttribs;
	int parentElement;
	unsigned parentGID_;
	NSString* filename_;
	NSString* resources_;
	int orientation_;
	CGSize mapSize_;
	CGSize tileSize_;
	NSMutableArray* layers_;
	NSMutableArray* tilesets_;
	NSMutableArray* objectGroups_;
	NSMutableDictionary* properties_;
	NSMutableDictionary* tileProperties_;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(retain, nonatomic) NSMutableDictionary* tileProperties;
@property(retain, nonatomic) NSMutableDictionary* properties;
@property(retain, nonatomic) NSMutableArray* objectGroups;
@property(retain, nonatomic) NSString* resources;
@property(retain, nonatomic) NSString* filename;
@property(retain, nonatomic) NSMutableArray* tilesets;
@property(retain, nonatomic) NSMutableArray* layers;
@property(assign, nonatomic) CGSize tileSize;
@property(assign, nonatomic) CGSize mapSize;
@property(assign, nonatomic) int orientation;
+(id)formatWithXML:(id)xml resourcePath:(id)path;
+(id)formatWithTMXFile:(id)tmxfile;
-(void)parser:(id)parser parseErrorOccurred:(id)occurred;
-(void)parser:(id)parser foundCharacters:(id)characters;
-(void)parser:(id)parser didEndElement:(id)element namespaceURI:(id)uri qualifiedName:(id)name;
-(void)parser:(id)parser didStartElement:(id)element namespaceURI:(id)uri qualifiedName:(id)name attributes:(id)attributes;
-(void)parseXMLFile:(id)file;
-(void)parseXMLString:(id)string;
-(void)parseXMLData:(id)data;
-(void)dealloc;
-(id)initWithTMXFile:(id)tmxfile;
-(id)initWithXML:(id)xml resourcePath:(id)path;
-(void)internalInit:(id)init resourcePath:(id)path;
@end

