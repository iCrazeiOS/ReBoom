/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class ANSMetadata, NSDictionary, ANSCrashMetadata, NSURL;

@interface ANSRotateCrashMetadataOperation : XXUnknownSuperclass {
	NSURL* _crashMetadataURL;
	ANSMetadata* _currentMetadata;
	ANSCrashMetadata* _crashMetadata;
	NSDictionary* _currentMetadataDictionary;
}
@property(retain, nonatomic) NSDictionary* currentMetadataDictionary;
@property(retain, nonatomic) ANSCrashMetadata* crashMetadata;
@property(retain, nonatomic) ANSMetadata* currentMetadata;
@property(retain, nonatomic) NSURL* crashMetadataURL;
-(void).cxx_destruct;
-(void)main;
-(id)initWithCrashMetadataURL:(id)crashMetadataURL currentMetadata:(id)metadata;
@end

