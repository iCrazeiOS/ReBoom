/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class UIView, UIColor;

@interface FBSDKLikeBoxBorderView : XXUnknownSuperclass {
	float _borderCornerRadius;
	float _borderWidth;
	unsigned _caretPosition;
	UIView* _contentView;
	UIColor* _fillColor;
	UIColor* _foregroundColor;
}
@property(retain, nonatomic) UIColor* foregroundColor;
@property(retain, nonatomic) UIColor* fillColor;
@property(retain, nonatomic) UIView* contentView;
@property(readonly, assign, nonatomic) UIEdgeInsets contentInsets;
@property(assign, nonatomic) unsigned caretPosition;
@property(assign, nonatomic) float borderWidth;
@property(assign, nonatomic) float borderCornerRadius;
-(void).cxx_destruct;
-(void)_initializeContent;
-(UIEdgeInsets)_borderInsets;
-(void)drawRect:(CGRect)rect;
-(CGSize)sizeThatFits:(CGSize)fits;
-(void)layoutSubviews;
-(CGSize)intrinsicContentSize;
-(void)setBackgroundColor:(id)color;
-(id)initWithCoder:(id)coder;
-(id)initWithFrame:(CGRect)frame;
@end

