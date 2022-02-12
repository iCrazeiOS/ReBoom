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

@class NSString;

@interface FBSDKAppGroupContent : XXUnknownSuperclass <FBSDKCopying, NSSecureCoding> {
	NSString* _groupDescription;
	NSString* _name;
	unsigned _privacy;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(assign, nonatomic) unsigned privacy;
@property(copy, nonatomic) NSString* name;
@property(copy, nonatomic) NSString* groupDescription;
+(BOOL)supportsSecureCoding;
-(void).cxx_destruct;
-(id)copyWithZone:(NSZone*)zone;
-(void)encodeWithCoder:(id)coder;
-(id)initWithCoder:(id)coder;
-(BOOL)isEqualToAppGroupContent:(id)appGroupContent;
-(BOOL)isEqual:(id)equal;
@end

