/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "HSMenuLayer.h"
#import "TrialGameControllerDelegate.h"

@class UITextView, NSDictionary, HSAdjustedSprite, CCMenu;

__attribute__((visibility("hidden")))
@interface NewsSplash : HSMenuLayer <TrialGameControllerDelegate> {
	HSAdjustedSprite* dialog;
	CCMenu* menuItems;
	UITextView* textView;
	NSDictionary* article;
}
-(void).cxx_destruct;
-(id)controllerItemForIndex:(unsigned)index;
-(id)controllerItemConfig;
-(unsigned)controllerDefaultItem;
-(void)controllerCancel;
-(void)postFirstVisit;
-(void)cleanup;
-(void)postTransitionIn;
-(void)close;
-(void)continue;
-(void)setupWithText:(id)text;
-(id)initWithMenu:(id)menu article:(id)article;
@end
