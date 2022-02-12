/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "TrialGameControllerDelegate.h"
#import "HSMenuLayer.h"

@class CCMenu, CCSprite, HSAdjustedSprite, HSMenuItem, NSString;

__attribute__((visibility("hidden")))
@interface UnlockPopup : HSMenuLayer <TrialGameControllerDelegate> {
	HSAdjustedSprite* dialog;
	CCSprite* loading;
	NSString* product;
	NSString* themeId;
	HSMenuItem* backButton;
	CCMenu* allWorldsButton;
	CCMenu* thisWorldButton;
}
+(id)layerWithMenu:(id)menu product:(id)product theme:(id)theme;
-(void).cxx_destruct;
-(id)controllerItemForIndex:(unsigned)index;
-(id)controllerItemConfig;
-(unsigned)controllerDefaultItem;
-(void)controllerCancel;
-(void)postFirstVisit;
-(void)postTransitionIn;
-(void)purchaseItem:(id)item;
-(id)createSoftBuyNode:(id)node amount:(id)amount;
-(id)createBuyNode:(id)node;
-(id)addTarget_soft_coins:(id)coins;
-(id)addTarget_super_stars_previous:(id)previous;
-(id)addTarget_super_stars:(id)stars;
-(id)addTarget_medals_previous:(id)previous;
-(id)addTarget_medals:(id)medals;
-(id)addTarget_wc_win:(id)win;
-(id)addTarget_wc_top_5:(id)a5;
-(id)addTarget_wc_games:(id)games;
-(id)addTarget_vs_wins:(id)wins;
-(id)addTarget_active_vs:(id)vs;
-(id)addTarget_invited_friends:(id)friends;
-(void)setupTargets:(id)targets;
-(void)setupWithSoftCoins:(id)softCoins;
-(void)buildPopup;
-(void)stopLoading;
-(void)showError;
-(void)loadStore;
-(void)cleanup;
-(id)initWithMenu:(id)menu product:(id)product theme:(id)theme;
-(id)initWithMenu:(id)menu;
@end

