/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "NSSecureCoding.h"
#import "NSCopying.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class NSDate, NSURL, NSString;

@interface FBSDKProfile : XXUnknownSuperclass <NSCopying, NSSecureCoding> {
	NSString* _userID;
	NSString* _firstName;
	NSString* _middleName;
	NSString* _lastName;
	NSString* _name;
	NSURL* _linkURL;
	NSDate* _refreshDate;
}
@property(readonly, assign, nonatomic) NSDate* refreshDate;
@property(readonly, assign, nonatomic) NSURL* linkURL;
@property(readonly, assign, nonatomic) NSString* name;
@property(readonly, assign, nonatomic) NSString* lastName;
@property(readonly, assign, nonatomic) NSString* middleName;
@property(readonly, assign, nonatomic) NSString* firstName;
@property(readonly, assign, nonatomic) NSString* userID;
+(void)observeChangeAccessTokenChange:(id)change;
+(BOOL)supportsSecureCoding;
+(void)enableUpdatesOnAccessTokenChange:(BOOL)change;
+(void)setCurrentProfile:(id)profile;
+(id)currentProfile;
+(id)fetchCachedProfile;
+(void)cacheProfile:(id)profile;
-(void).cxx_destruct;
-(void)encodeWithCoder:(id)coder;
-(id)initWithCoder:(id)coder;
-(BOOL)isEqualToProfile:(id)profile;
-(BOOL)isEqual:(id)equal;
-(unsigned)hash;
-(id)copyWithZone:(NSZone*)zone;
-(id)imagePathForPictureMode:(unsigned)pictureMode size:(CGSize)size;
-(id)initWithUserID:(id)userID firstName:(id)name middleName:(id)name3 lastName:(id)name4 name:(id)name5 linkURL:(id)url refreshDate:(id)date;
-(id)init;
@end

