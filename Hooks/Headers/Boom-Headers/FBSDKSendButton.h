/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "FBSDKButtonImpressionTracking.h"
#import "FBSDKButton.h"
#import "FBSDKSharingButton.h"

@class FBSDKMessageDialog, NSString;
@protocol FBSDKSharingContent;

@interface FBSDKSendButton : FBSDKButton <FBSDKButtonImpressionTracking, FBSDKSharingButton> {
	FBSDKMessageDialog* _dialog;
}
@property(copy, nonatomic) id<FBSDKSharingContent> shareContent;
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
-(void).cxx_destruct;
-(void)_share:(id)share;
-(BOOL)isImplicitlyDisabled;
-(void)configureButton;
-(id)impressionTrackingIdentifier;
-(id)impressionTrackingEventName;
-(id)analyticsParameters;
@end
