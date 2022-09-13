/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "CCRGBAProtocol.h"
#import "Boom-Structs.h"
#import "CCMenuItem.h"

@class NSMutableArray, NSString;

__attribute__((visibility("hidden")))
@interface CCMenuItemToggle : CCMenuItem <CCRGBAProtocol> {
	unsigned selectedIndex_;
	NSMutableArray* subItems_;
	unsigned char opacity_;
	ccColor3B color_;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(retain, nonatomic) NSMutableArray* subItems;
@property(assign, nonatomic) unsigned selectedIndex;
@property(readonly, assign, nonatomic) ccColor3B color;
@property(readonly, assign, nonatomic) unsigned char opacity;
+(id)itemWithItems:(id)items block:(id)block;
+(id)itemWithTarget:(id)target selector:(SEL)selector items:(id)items;
-(void)setColor:(ccColor3B)color;
-(void)setOpacity:(unsigned char)opacity;
-(id)selectedItem;
-(void)setIsEnabled:(BOOL)enabled;
-(void)activate;
-(void)unselected;
-(void)selected;
-(void)dealloc;
-(id)initWithItems:(id)items block:(id)block;
-(id)initWithTarget:(id)target selector:(SEL)selector items:(id)items vaList:(void*)list;
@end
