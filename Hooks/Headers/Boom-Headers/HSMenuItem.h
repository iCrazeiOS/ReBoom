/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCMenuItemSpriteIndependent.h"
#import "HSJustify.h"
#import "CCTargetedTouchDelegate.h"

@class NSMutableDictionary, CCSprite, NSMutableArray, CCAction, NSString;

__attribute__((visibility("hidden")))
@interface HSMenuItem : CCMenuItemSpriteIndependent <CCTargetedTouchDelegate, HSJustify> {
	ccColor3B selectedColor;
	CCSprite* brightenOverlay;
	CCNode<CCRGBAProtocol>* label;
	CGRect touchAreaOffset;
	BOOL animate;
	CCAction* animation;
	unsigned char disabledOpacity;
	NSMutableDictionary* objectOriginalColors;
	BOOL registeredForTouch;
	BOOL touchDown;
	BOOL swipeTriggered;
	CGPoint touchDownAt;
	id selected_block_;
	id unselected_block_;
	id swipe_block_;
	id disabled_block_;
	CGPoint nonadjustedPosition;
	NSMutableArray* subItems;
	BOOL noJustifyOnEnter;
	BOOL quiet;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) NSUInteger hash;
@property(assign, nonatomic) BOOL quiet;
@property(assign, nonatomic) BOOL noJustifyOnEnter;
@property(retain, nonatomic) NSMutableDictionary* objectOriginalColors;
@property(assign, nonatomic) unsigned char disabledOpacity;
@property(assign, nonatomic) BOOL animate;
@property(assign, nonatomic) CGRect touchAreaOffset;
@property(retain, nonatomic) CCNode<CCRGBAProtocol>* label;
@property(retain, nonatomic) CCSprite* brightenOverlay;
@property(copy, nonatomic) id disabledBlock;
@property(copy, nonatomic) id swipeBlock;
@property(copy, nonatomic) id unselectedBlock;
@property(copy, nonatomic) id selectedBlock;
@property(assign, nonatomic) ccColor3B selectedColor;
+(id)independentItemWithNormalSprite:(id)normalSprite selectedColor:(ccColor3B)color brighten:(BOOL)brighten block:(id)block;
+(id)independentItemWithNormalSprite:(id)normalSprite selectedColor:(ccColor3B)color block:(id)block;
+(id)independentItemWithNormalSprite:(id)normalSprite block:(id)block;
+(id)independentItemWithNormalSprite:(id)normalSprite;
+(id)itemWithNormalSprite:(id)normalSprite selectedColor:(ccColor3B)color brighten:(BOOL)brighten block:(id)block;
+(id)itemWithNormalSprite:(id)normalSprite selectedColor:(ccColor3B)color block:(id)block;
+(id)itemWithNormalSprite:(id)normalSprite block:(id)block;
+(id)itemWithNormalSprite:(id)normalSprite;
//-(void).cxx_destruct;
-(id)itemForTouch:(id)touch;
-(void)addSubItemForTouch:(id)touch;
-(void)claimTouch:(id)touch;
-(void)ccTouchCancelled:(id)cancelled withEvent:(id)event;
-(void)ccTouchEnded:(id)ended withEvent:(id)event;
-(void)ccTouchMoved:(id)moved withEvent:(id)event;
-(BOOL)ccTouchBegan:(id)began withEvent:(id)event;
-(BOOL)touchInside:(id)inside;
-(void)blur;
-(void)focus;
-(void)setIsEnabled:(BOOL)enabled;
-(void)setOpacity:(unsigned char)opacity;
-(void)setLabel:(id)label offset:(CGPoint)offset alignment:(int)alignment;
-(void)setLabel:(id)label offset:(CGPoint)offset;
-(void)cleanup;
-(void)setVisible:(BOOL)visible;
-(void)onExit;
-(void)onEnter;
-(void)justifyRecursive;
-(void)justify;
-(void)setPosition:(CGPoint)position;
-(void)setSelectedColor:(ccColor3B )selectedColor;
-(void)activate;
-(void)swiped;
-(BOOL)respondsToSelector:(SEL)selector;
-(void)unselected;
-(void)selected;
-(id)initWithNormalSprite:(id)normalSprite selectedSprite:(id)sprite disabledSprite:(id)sprite3 block:(id)block;
-(CGPoint)convertToNodeSpace:(CGPoint)nodeSpace;
-(CGRect)rect;
@end
