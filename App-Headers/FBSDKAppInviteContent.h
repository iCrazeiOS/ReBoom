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

@class NSString, NSURL;

@interface FBSDKAppInviteContent : XXUnknownSuperclass <FBSDKCopying, NSSecureCoding> {
	NSURL* _appInvitePreviewImageURL;
	NSURL* _appLinkURL;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(copy, nonatomic) NSURL* previewImageURL;
@property(copy, nonatomic) NSURL* appLinkURL;
@property(copy, nonatomic) NSURL* appInvitePreviewImageURL;
+(BOOL)supportsSecureCoding;
-(void).cxx_destruct;
-(id)copyWithZone:(NSZone*)zone;
-(void)encodeWithCoder:(id)coder;
-(id)initWithCoder:(id)coder;
-(BOOL)isEqualToAppInviteContent:(id)appInviteContent;
-(BOOL)isEqual:(id)equal;
@end

