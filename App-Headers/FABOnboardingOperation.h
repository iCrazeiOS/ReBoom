/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "FABNetworkOperation.h"

@class FABNetworkClient, NSDictionary, NSError, FABApplicationIdentiferModel, NSString;
@protocol FABOnboardingOperationDelegate;

@interface FABOnboardingOperation : FABNetworkOperation {
	BOOL _shouldCreate;
	NSError* _error;
	FABApplicationIdentiferModel* _appIdentifierModel;
	NSString* _appEndpoint;
	id<FABOnboardingOperationDelegate> _delegate;
	FABNetworkClient* _networkClient;
	NSDictionary* _kitVersionsByKitBundleIdentifier;
}
@property(readonly, assign, nonatomic) NSError* error;
@property(readonly, copy, nonatomic) NSDictionary* kitVersionsByKitBundleIdentifier;
@property(readonly, assign, nonatomic) __weak FABNetworkClient* networkClient;
@property(readonly, assign, nonatomic) id<FABOnboardingOperationDelegate> delegate;
@property(readonly, assign, nonatomic) NSString* appEndpoint;
@property(readonly, assign, nonatomic) FABApplicationIdentiferModel* appIdentifierModel;
@property(assign, nonatomic) BOOL shouldCreate;
-(void).cxx_destruct;
-(id)onboardingRequestForAppCreate:(BOOL)appCreate;
-(id)appUpdateURL;
-(id)appCreateURL;
-(id)errorForCode:(unsigned)code userInfo:(id)info;
-(id)appInstallSource;
-(id)appDisplayVersion;
-(id)appBuildVersion;
-(id)appName;
-(id)appPlatform;
-(id)appBundleIdentifier;
-(void)beginAppConfigure;
-(void)main;
-(id)initWithDelegate:(id)delegate shouldCreate:(BOOL)create APIKey:(id)key kitVersionsByKitBundleIdentifier:(id)identifier appIdentifierModel:(id)model endpointString:(id)string networkClient:(id)client;
-(id)initWithAPIKey:(id)apikey;
@end

