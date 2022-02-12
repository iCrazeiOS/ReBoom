/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "TrialGameControllerDelegate.h"
#import "HSMenuLayer.h"

@class NSMutableDictionary, CCSprite, HSAdjustedSprite;

__attribute__((visibility("hidden")))
@interface ChallengePurchaseRetries : HSMenuLayer <TrialGameControllerDelegate> {
	HSAdjustedSprite* dialog;
	CCSprite* loading;
	BOOL inGame;
	NSMutableDictionary* buttons;
	id onComplete;
}
+(id)layerWithMenu:(id)menu onComplete:(id)complete;
+(id)menuWithOnComplete:(id)onComplete;
-(void).cxx_destruct;
-(id)controllerItemForIndex:(unsigned)index;
-(id)controllerItemConfig;
-(unsigned)controllerDefaultItem;
-(void)controllerCancel;
-(void)postFirstVisit;
-(void)postTransitionIn;
-(void)done:(id)done;
-(void)purchaseItem:(id)item;
-(id)createInAppBuyButton:(unsigned)appBuyButton;
-(id)createCoinsBuyButton:(int)button;
-(id)createProductNode:(id)node retries:(unsigned)retries subTitle:(id)title consumable:(BOOL)consumable;
-(void)buildPopup;
-(void)stopLoading;
-(void)showError;
-(void)loadStore;
-(void)cleanup;
-(id)initWithMenu:(id)menu onComplete:(id)complete;
-(id)initWithMenu:(id)menu;
@end

