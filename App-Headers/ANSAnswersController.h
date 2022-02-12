/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "ANSUploaderDelegate.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class NSURL, ANSNetworkRetryHandler, ANSTimer, ANSUploader, NSString, ANSCrashMetadata, NSOperationQueue, ANSSettings, ANSEventFilter, ANSMetadata;

@interface ANSAnswersController : XXUnknownSuperclass <ANSUploaderDelegate> {
	NSOperationQueue* _eventQueue;
	NSString* _rootEventDirectory;
	ANSMetadata* _metadata;
	ANSCrashMetadata* _previousExecutionMetadata;
	ANSUploader* _uploader;
	ANSNetworkRetryHandler* _networkRetryHandler;
	NSURL* _currentLogURL;
	ANSEventFilter* _eventFilter;
	ANSSettings* _settings;
	ANSTimer* _flushTimer;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(readonly, assign, nonatomic) ANSTimer* flushTimer;
@property(readonly, assign, nonatomic) ANSSettings* settings;
@property(readonly, assign, nonatomic) ANSEventFilter* eventFilter;
@property(readonly, assign, nonatomic) NSURL* currentLogURL;
@property(readonly, assign, nonatomic) ANSNetworkRetryHandler* networkRetryHandler;
@property(readonly, assign, nonatomic) ANSUploader* uploader;
@property(readonly, assign, nonatomic) ANSCrashMetadata* previousExecutionMetadata;
@property(readonly, assign, nonatomic) ANSMetadata* metadata;
@property(readonly, assign, nonatomic) NSString* rootEventDirectory;
@property(readonly, assign, nonatomic) NSOperationQueue* eventQueue;
+(id)rootDirectory;
-(void).cxx_destruct;
-(void)uploader:(id)uploader completedRequest:(id)request withResponse:(id)response uniqueName:(id)name error:(id)error completionHandler:(id)handler;
-(void)uploader:(id)uploader session:(id)session didReceiveChallenge:(id)challenge completionHandler:(id)handler;
-(void)uploader:(id)uploader didFinishUploadWithUniqueName:(id)uniqueName error:(id)error;
-(id)uploader:(id)uploader filePathForUniqueName:(id)uniqueName;
-(id)multipartMimeURLWithBoundary:(id)boundary;
-(id)boundaryFromURL:(id)url;
-(void)uploadMultipartFiles:(id)files;
-(void)uploadAllMultipartFiles;
-(void)cleanupAndProcessExistingFiles;
-(id)uploadOperationForFileAtURL:(id)url withBoundary:(id)boundary;
-(id)operationsForCompressedLog:(id)compressedLog;
-(id)operationsForUncompressedLog:(id)uncompressedLog;
-(void)rotateAndSubmitCurrentLog;
-(BOOL)shouldSubmitLogAtURL:(id)url;
-(void)enqueueEvent:(id)event;
-(void)logCrashEvent:(id)event;
-(BOOL)shouldLogEvent;
-(void)logEvent:(id)event;
-(id)replacePreviousExecutionMetadataWithCurrentMetadata:(id)currentMetadata inRootDirectory:(id)rootDirectory;
-(void)removeAllLogs;
-(void)flushTimerFired;
-(void)setupFlushTimer;
-(void)initializeSettingsIfNeededWithFabricSettings:(id)fabricSettings;
-(void)fabricSettingsDidBecomeAvailable:(id)fabricSettings;
-(id)generateNewLogPath;
-(void)applicationLifecycleEvent:(id)event;
-(void)registerForApplicationLifecycleEvents;
-(id)uploaderWithQueue:(id)queue delegate:(id)delegate;
-(id)sharedFabricSDK;
-(id)crashMetadataPathForRootDirectory:(id)rootDirectory;
-(id)eventDirectoryForRootDirectory:(id)rootDirectory;
-(id)initWithBetaToken:(id)betaToken rootDirectory:(id)directory;
-(id)initWithBetaToken:(id)betaToken;
@end

