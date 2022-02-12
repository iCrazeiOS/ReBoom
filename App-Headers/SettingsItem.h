/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "HSMenuItem.h"

@class CCSprite, HSLabelWithStroke, HSLabelTTF, HSAdjustedSprite, HSUISwitch;

__attribute__((visibility("hidden")))
@interface SettingsItem : HSMenuItem {
	int type;
	HSAdjustedSprite* icon;
	HSLabelWithStroke* titleLabel;
	HSLabelTTF* valueLabel;
	HSUISwitch* switchElement;
	CCNode* valueNode;
	CCSprite* fade;
	//CCSprite* brightenOverlay;
}
@property(readonly, assign, nonatomic) HSUISwitch* switchElement;
+(id)itemWithTitle:(id)title value:(id)value type:(int)type;
//-(void).cxx_destruct;
-(void)blur;
-(void)focus;
-(void)cleanup;
-(void)unselected;
-(void)selected;
-(id)itemForTouch:(id)touch;
-(void)addFade;
-(void)removeFade;
-(void)setValueNode:(id)node;
-(void)setValue:(id)value;
-(void)setTitle:(id)title;
-(void)setIcon:(id)icon;
-(void)setSwitchElement:(id)element state:(int)state;
@end

