/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "FBSDKSharingDialog.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class NSString;
@protocol FBSDKSharingContent, FBSDKSharingDelegate;

@interface FBSDKMessageDialog : XXUnknownSuperclass <FBSDKSharingDialog> {
	BOOL _shouldFailOnDataError;
	id<FBSDKSharingDelegate> _delegate;
	id<FBSDKSharingContent> _shareContent;
}
@property(assign, nonatomic) BOOL shouldFailOnDataError;
@property(copy, nonatomic) id<FBSDKSharingContent> shareContent;
@property(assign, nonatomic) __weak id<FBSDKSharingDelegate> delegate;
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
+(id)showWithContent:(id)content delegate:(id)delegate;
+(void)initialize;
-(void).cxx_destruct;
-(void)_logDialogShow;
-(void)_invokeDelegateDidFailWithError:(id)_invokeDelegate;
-(void)_invokeDelegateDidCompleteWithResults:(id)_invokeDelegate;
-(void)_invokeDelegateDidCancel;
-(void)_handleCompletionWithDialogResults:(id)dialogResults response:(id)response;
-(BOOL)_canShowNative;
-(BOOL)validateWithError:(id*)error;
-(BOOL)show;
-(BOOL)canShow;
@end

