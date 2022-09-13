/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "CCMenuItemSprite.h"
#import "Boom-Structs.h"


__attribute__((visibility("hidden")))
@interface CCMenuItemImage : CCMenuItemSprite {
}
+(id)itemWithNormalImage:(id)normalImage selectedImage:(id)image disabledImage:(id)image3 block:(id)block;
+(id)itemWithNormalImage:(id)normalImage selectedImage:(id)image block:(id)block;
+(id)itemWithNormalImage:(id)normalImage selectedImage:(id)image disabledImage:(id)image3 target:(id)target selector:(SEL)selector;
+(id)itemWithNormalImage:(id)normalImage selectedImage:(id)image disabledImage:(id)image3;
+(id)itemWithNormalImage:(id)normalImage selectedImage:(id)image target:(id)target selector:(SEL)selector;
+(id)itemWithNormalImage:(id)normalImage selectedImage:(id)image;
+(id)itemFromNormalImage:(id)normalImage selectedImage:(id)image disabledImage:(id)image3 block:(id)block;
+(id)itemFromNormalImage:(id)normalImage selectedImage:(id)image block:(id)block;
+(id)itemFromNormalImage:(id)normalImage selectedImage:(id)image disabledImage:(id)image3 target:(id)target selector:(SEL)selector;
+(id)itemFromNormalImage:(id)normalImage selectedImage:(id)image target:(id)target selector:(SEL)selector;
+(id)itemFromNormalImage:(id)normalImage selectedImage:(id)image;
-(void)setDisabledSpriteFrame:(id)frame;
-(void)setSelectedSpriteFrame:(id)frame;
-(void)setNormalSpriteFrame:(id)frame;
-(id)initWithNormalImage:(id)normalImage selectedImage:(id)image disabledImage:(id)image3 block:(id)block;
-(id)initWithNormalImage:(id)normalImage selectedImage:(id)image disabledImage:(id)image3 target:(id)target selector:(SEL)selector;
-(id)initFromNormalImage:(id)normalImage selectedImage:(id)image disabledImage:(id)image3 block:(id)block;
-(id)initFromNormalImage:(id)normalImage selectedImage:(id)image disabledImage:(id)image3 target:(id)target selector:(SEL)selector;
@end
