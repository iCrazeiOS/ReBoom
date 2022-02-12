/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library


@interface FBSDKServerConfigurationManager : XXUnknownSuperclass {
}
+(BOOL)_serverConfigurationTimestampIsValid:(id)valid;
+(id)_parseDialogConfigurations:(id)configurations;
+(id)_loadServerConfigurationFromUserDefaultsForAppID:(id)appID;
+(void)_loadServerConfigurationFromServerForAppID:(id)appID;
+(void)_loadServerConfigurationForAppID:(id)appID;
+(void)_didLoadServerConfiguration:(id)configuration appID:(id)anId error:(id)error didLoadFromUserDefaults:(BOOL)userDefaults;
+(BOOL)_cachedServerConfigurationIsValidForAppID:(id)appID;
+(id)requestToLoadServerConfiguration:(id)loadServerConfiguration;
+(void)processLoadRequestResponse:(id)response error:(id)error appID:(id)anId;
+(void)loadServerConfigurationWithCompletionBlock:(id)completionBlock;
+(id)cachedServerConfiguration;
+(void)initialize;
-(id)init;
@end

