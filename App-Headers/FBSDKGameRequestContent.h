/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "FBSDKCopying.h"
#import "NSSecureCoding.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class NSArray, NSString;

@interface FBSDKGameRequestContent : XXUnknownSuperclass <FBSDKCopying, NSSecureCoding> {
	unsigned _actionType;
	NSString* _data;
	unsigned _filters;
	NSString* _message;
	NSString* _objectID;
	NSArray* _recipients;
	NSArray* _recipientSuggestions;
	NSString* _title;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(copy, nonatomic) NSArray* to;
@property(copy, nonatomic) NSString* title;
@property(copy, nonatomic) NSArray* suggestions;
@property(copy, nonatomic) NSArray* recipientSuggestions;
@property(copy, nonatomic) NSArray* recipients;
@property(copy, nonatomic) NSString* objectID;
@property(copy, nonatomic) NSString* message;
@property(assign, nonatomic) unsigned filters;
@property(copy, nonatomic) NSString* data;
@property(assign, nonatomic) unsigned actionType;
+(BOOL)supportsSecureCoding;
-(void).cxx_destruct;
-(id)copyWithZone:(NSZone*)zone;
-(void)encodeWithCoder:(id)coder;
-(id)initWithCoder:(id)coder;
-(BOOL)isEqualToGameRequestContent:(id)gameRequestContent;
-(BOOL)isEqual:(id)equal;
@end

