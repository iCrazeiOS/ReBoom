/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library


@interface FBSDKError : XXUnknownSuperclass {
}
+(id)unknownErrorWithMessage:(id)message;
+(id)requiredArgumentErrorWithName:(id)name message:(id)message underlyingError:(id)error;
+(id)requiredArgumentErrorWithName:(id)name message:(id)message;
+(id)invalidCollectionErrorWithName:(id)name collection:(id)collection item:(id)item message:(id)message underlyingError:(id)error;
+(id)invalidCollectionErrorWithName:(id)name collection:(id)collection item:(id)item message:(id)message;
+(id)invalidArgumentErrorWithName:(id)name value:(id)value message:(id)message underlyingError:(id)error;
+(id)invalidArgumentErrorWithName:(id)name value:(id)value message:(id)message;
+(id)errorWithCode:(int)code userInfo:(id)info message:(id)message underlyingError:(id)error;
+(id)errorWithCode:(int)code message:(id)message underlyingError:(id)error;
+(id)errorWithCode:(int)code message:(id)message;
+(BOOL)errorIsNetworkError:(id)error;
+(id)errorDomain;
-(id)init;
@end

