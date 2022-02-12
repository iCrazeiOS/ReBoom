/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "UIWebViewDelegate.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class NSString, UIButton, UIActivityIndicatorView, UIWebView;
@protocol FBSDKWebDialogViewDelegate;

@interface FBSDKWebDialogView : XXUnknownSuperclass <UIWebViewDelegate> {
	UIButton* _closeButton;
	UIActivityIndicatorView* _loadingView;
	UIWebView* _webView;
	id<FBSDKWebDialogViewDelegate> _delegate;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(assign, nonatomic) id<FBSDKWebDialogViewDelegate> delegate;
-(void).cxx_destruct;
-(void)webViewDidFinishLoad:(id)webView;
-(BOOL)webView:(id)view shouldStartLoadWithRequest:(id)request navigationType:(int)type;
-(void)webView:(id)view didFailLoadWithError:(id)error;
-(void)_close:(id)close;
-(void)layoutSubviews;
-(void)drawRect:(CGRect)rect;
-(void)stopLoading;
-(void)loadURL:(id)url;
-(void)dealloc;
-(id)initWithFrame:(CGRect)frame;
@end

