/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "TrialGameControllerDelegate.h"
#import "HSMenuLayer.h"

@class CCMenu, Challenge, Wheely, CCSprite, NSString;

__attribute__((visibility("hidden")))
@interface ChallengeSummary : HSMenuLayer <TrialGameControllerDelegate> {
	Challenge* challenge;
	BOOL animated;
	BOOL justCompletedTurn;
	BOOL justCompletedTurnWithDuplicate;
	BOOL justReceivedResults;
	BOOL selfIsWinner;
	BOOL synced;
	BOOL showChartboost;
	CCSprite* background;
	NSString* challengerHeroStyle;
	NSString* challengerEngineStyle;
	NSString* challengerWheelStyle;
	CCMenu* menuItems;
	Wheely* opponentHero;
}
+(id)layerWithMenu:(id)menu challenge:(id)challenge;
+(id)sceneWithChallenge:(id)challenge;
-(void).cxx_destruct;
-(id)controllerItemForIndex:(unsigned)index;
-(id)controllerItemConfig;
-(unsigned)controllerDefaultItem;
-(void)controllerCancel;
-(void)postFirstVisit;
-(void)postTransitionIn;
-(void)exit;
-(void)cleanup;
-(void)registerOfferEvent;
-(void)onEnter;
-(void)animateWins:(id)wins to:(id)to reward:(id)reward coinBarAnimation:(BOOL)animation;
-(void)createMenu;
-(void)createUI;
-(id)initWithMenu:(id)menu challenge:(id)challenge;
-(id)initWithMenu:(id)menu;
@end

