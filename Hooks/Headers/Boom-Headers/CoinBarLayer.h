/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCLayer.h"

@class CCSprite, NSDate, NSNumberFormatter, HSMenuItem, HSLabelSafeBMFont, HSMenu;

__attribute__((visibility("hidden")))
@interface CoinBarLayer : CCLayer {
	HSLabelSafeBMFont* coins;
	NSNumberFormatter* formatter;
	CCSprite* coinBar;
	CCSprite* coinBarCoin;
	CCSprite* animatedCoin;
	HSLabelSafeBMFont* animatedCoinAmount;
	HSMenuItem* getCoinsItem;
	unsigned amount;
	HSMenu* menu;
	BOOL triggerUpdateOnVisit;
	CCSprite* offer;
	HSLabelSafeBMFont* offerTime;
	HSMenuItem* openOfferItem;
	NSDate* activeOfferTime;
}
+(id)coinBarLayer;
-(void).cxx_destruct;
-(void)visit;
-(void)cleanup;
-(void)updateOfferTime;
-(void)showMoney;
-(void)triggerCoinsUpdated;
-(void)showNewAmount;
-(void)coinsUpdated:(id)updated;
-(void)showOffer;
-(void)hideOffer;
-(void)showBar:(id)bar;
-(void)hideBar;
-(id)button;
-(void)showButton;
-(void)hideButton;
-(void)setup;
-(void)onEnter;
@end
