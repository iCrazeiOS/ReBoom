/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library
#import "Boom-Structs.h"

@class NSMutableDictionary, NSMutableArray, NSString;

__attribute__((visibility("hidden")))
@interface CCTMXObjectGroup : XXUnknownSuperclass {
	NSString* groupName_;
	CGPoint positionOffset_;
	NSMutableArray* objects_;
	NSMutableDictionary* properties_;
}
@property(retain, nonatomic) NSMutableDictionary* properties;
@property(retain, nonatomic) NSMutableArray* objects;
@property(assign, nonatomic) CGPoint positionOffset;
@property(retain, nonatomic) NSString* groupName;
-(id)propertyNamed:(id)named;
-(id)objectNamed:(id)named;
-(void)dealloc;
-(id)init;
@end

