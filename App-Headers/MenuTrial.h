/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "HSMenuLayer.h"
#import "GKAchievementViewControllerDelegate.h"
#import "GKLeaderboardViewControllerDelegate.h"
#import "TrialGameControllerDelegate.h"

@class Object156, HSOpacityNode, NSString, CCMenu, TrialLayer;

__attribute__((visibility("hidden")))
@interface MenuTrial : HSMenuLayer <TrialGameControllerDelegate, GKAchievementViewControllerDelegate, GKLeaderboardViewControllerDelegate> {
	TrialLayer* trialLayer;
	HSOpacityNode* parent;
	Object156* wheely;
	CGRect worldSize;
	CGPoint startPosition;
	b2Vec2 b2StartPosition;
	unsigned iterations;
	CGPoint lastParallaxPosition;
	BOOL started;
	float diedTimer;
	float Object254;
	CCMenu* menuItems;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
+(id)scene;
-(id).cxx_construct;
-(void).cxx_destruct;
-(void)cleanup;
-(void)onExit;
-(void)update:(float)update;
-(void)showSplash;
-(void)onEnter;
-(id)controllerItemForIndex:(unsigned)index;
-(id)controllerItemConfig;
-(unsigned)controllerDefaultItem;
-(void)controllerCancel;
-(void)postFirstVisit;
-(void)leaderboardViewControllerDidFinish:(id)leaderboardViewController;
-(void)showLeaderboards:(id)leaderboards;
-(void)achievementViewControllerDidFinish:(id)achievementViewController;
-(void)showAchievements;
-(void)showGameCenter;
-(void)createMenu;
-(void)restart;
-(void)died;
-(void)setupTrialLayer;
-(void)postTransitionIn;
-(id)initWithMenu:(id)menu;
@end

