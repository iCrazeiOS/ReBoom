/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class NSSet, NSDate, NSError, NSString;

@interface FBSDKLoginCompletionParameters : XXUnknownSuperclass {
	BOOL _systemAccount;
	NSString* _accessTokenString;
	NSSet* _permissions;
	NSSet* _declinedPermissions;
	NSString* _appID;
	NSString* _userID;
	NSError* _error;
	NSDate* _expirationDate;
	NSString* _challenge;
}
@property(copy, nonatomic) NSString* challenge;
@property(copy, nonatomic) NSDate* expirationDate;
@property(assign, nonatomic, getter=isSystemAccount) BOOL systemAccount;
@property(copy, nonatomic) NSError* error;
@property(copy, nonatomic) NSString* userID;
@property(copy, nonatomic) NSString* appID;
@property(copy, nonatomic) NSSet* declinedPermissions;
@property(copy, nonatomic) NSSet* permissions;
@property(copy, nonatomic) NSString* accessTokenString;
-(void).cxx_destruct;
-(id)initWithError:(id)error;
-(id)init;
@end

