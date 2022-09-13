/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <UIKit/UIView.h> // Unknown library
#import "Boom-Structs.h"
//#import "UITextFieldDelegate.h"
#import "HSAlertViewDelegate.h"

@class UIImage, NSMutableArray, UILabel, UIImageView, UITextField, NSString, HSAlertOverlayWindow, UITextView, HSAlertViewController;

__attribute__((visibility("hidden")))
@interface HSAlertView : UIView <UITextFieldDelegate, HSAlertViewDelegate> {
	UIImage* _backgroundImage;
	UILabel* _titleLabel;
	UILabel* _messageLabel;
	UITextView* _messageTextView;
	UIImageView* _messageTextViewMaskImageView;
	UITextField* _inputTextField;
	NSMutableArray* _buttons;
	HSAlertOverlayWindow* ow;
	HSAlertViewController* avc;
	BOOL usesMessageTextView;
	id<HSAlertViewDelegate> delegate;
	int cancelButtonIndex;
	int firstOtherButtonIndex;
	int buttonLayout;
	float width;
	float maxHeight;
	int style;
	HSAlertView* _strongAlertReference;
	id _activeDismissHandler;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) NSUInteger hash;
@property(copy, nonatomic) id activeDismissHandler;
@property(retain, nonatomic) HSAlertView* strongAlertReference;
@property(readonly, assign, nonatomic) UITextField* inputTextField;
@property(assign, nonatomic) int style;
@property(retain, nonatomic) UIImage* backgroundImage;
@property(assign, nonatomic) BOOL usesMessageTextView;
@property(assign, nonatomic) float maxHeight;
@property(assign, nonatomic) float width;
@property(assign, nonatomic) int buttonLayout;
@property(readonly, assign, nonatomic, getter=isVisible) BOOL visible;
@property(readonly, assign, nonatomic) int numberOfButtons;
@property(readonly, assign, nonatomic) int firstOtherButtonIndex;
@property(assign, nonatomic) int cancelButtonIndex;
@property(assign, nonatomic) id<HSAlertViewDelegate> delegate;
@property(copy, nonatomic) NSString* message;
@property(copy, nonatomic) NSString* title;
@property(readonly, assign, nonatomic) UITextView* messageTextView;
@property(readonly, assign, nonatomic) UILabel* messageLabel;
@property(readonly, assign, nonatomic) UILabel* titleLabel;
@property(readonly, assign, nonatomic) NSMutableArray* buttons;
+(id)alertViewWithTitle:(id)title message:(id)message cancelButtonTitle:(id)title3 otherButtonTitles:(id)titles;
+(void)upgradeAlert:(id)alert message:(id)message appId:(int)anId;
+(id)activeAlert;
// -(void).cxx_destruct;
-(void)dealloc;
-(void)alertView:(id)view clickedButtonAtIndex:(int)index;
-(void)showWithDismissHandler:(id)dismissHandler;
-(CGSize)buttonsAreaSize_Stacked;
-(CGSize)buttonsAreaSize_SideBySide;
-(CGSize)inputTextFieldSize;
-(CGSize)messageLabelSize;
-(CGSize)titleLabelSize;
-(CGSize)recalcSizeAndLayout:(BOOL)layout;
-(void)onButtonPress:(id)press;
-(void)pulse;
-(void)show;
-(void)releaseWindow:(int)window;
-(void)dismissWithClickedButtonIndex:(int)clickedButtonIndex animated:(BOOL)animated;
-(id)buttonTitleAtIndex:(int)index;
-(int)addButtonWithTitle:(id)title;
-(BOOL)textFieldShouldReturn:(id)textField;
-(id)messageTextViewMaskView;
-(void)onKeyboardWillHide:(id)onKeyboard;
-(void)onKeyboardWillShow:(id)onKeyboard;
-(void)drawRect:(CGRect)rect;
-(void)layoutSubviews;
-(CGSize)sizeThatFits:(CGSize)fits;
-(void)HSAlertView_commonInit;
-(id)initWithTitle:(id)title message:(id)message cancelButtonTitle:(id)title3 otherButtonTitles:(id)titles vaList:(void*)list;
-(id)initWithTitle:(id)title message:(id)message cancelButtonTitle:(id)title3 otherButtonTitles:(id)titles;
-(id)initWithTitle:(id)title message:(id)message delegate:(id)delegate cancelButtonTitle:(id)title4 otherButtonTitles:(id)titles;
-(id)initWithFrame:(CGRect)frame;
-(id)init;
@end
