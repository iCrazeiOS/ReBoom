/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "FBSDKLoginCompleting.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class FBSDKLoginCompletionParameters;
@protocol NSObject;

@interface FBSDKLoginURLCompleter : XXUnknownSuperclass <FBSDKLoginCompleting> {
	FBSDKLoginCompletionParameters* _parameters;
	id<NSObject> _observer;
	BOOL _performExplicitFallback;
}
-(void).cxx_destruct;
-(void)attemptBrowserLogIn:(id)anIn;
-(void)setErrorWithDictionary:(id)dictionary;
-(void)setParametersWithDictionary:(id)dictionary appID:(id)anId;
-(void)completeLogIn:(id)anIn withHandler:(id)handler;
-(id)initWithURLParameters:(id)urlparameters appID:(id)anId;
-(id)init;
@end

