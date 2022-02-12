/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCLayer.h"

@class CCMenu, HSParticleSystemQuad, CCSprite, BoostIndicator, HSAdjustedOpacityNode, HSLabelSafeBMFont, HSMenuItemSprite, NSString, TrialSession;

__attribute__((visibility("hidden")))
@interface TrialHUD : CCLayer {
	CGSize screenSize;
	TrialSession* session;
	HSLabelSafeBMFont* timerLabel;
	CCMenu* leftMenu;
	CCMenu* rightMenu;
	CCMenu* actionMenu;
	HSMenuItemSprite* pauseButton;
	HSMenuItemSprite* restartButton;
	HSMenuItemSprite* leftButton;
	HSMenuItemSprite* rightButton;
	BoostIndicator* boostIndicator;
	CCSprite* pauseNormal;
	CCSprite* restartHelpArrow;
	CCSprite* collectedPickupsSprite;
	HSLabelSafeBMFont* collectedPickupsLabel;
	HSLabelSafeBMFont* collectedCoinsLabelAboveWheely;
	HSParticleSystemQuad* collectedTwinkle;
	HSLabelSafeBMFont* message;
	CCNode* dieNode;
	HSLabelSafeBMFont* levelCompletedNode;
	HSAdjustedOpacityNode* levelInfo;
	HSLabelSafeBMFont* timeHeader;
	HSLabelSafeBMFont* timeLabel;
	unsigned restartCounter;
	NSString* levelInfoInfo;
	NSString* levelInfoTarget;
}
-(void).cxx_destruct;
-(void)dealloc;
-(void)cleanup;
-(void)updateTimeLabel;
-(BOOL)ccTouchBegan:(id)began withEvent:(id)event;
-(void)registerWithTouchDispatcher;
-(void)setRestartCounter:(unsigned)counter;
-(void)breakOff;
-(void)breakOn;
-(void)setBoostLevel:(unsigned)level;
-(void)reset;
-(void)blinkRestartArrow;
-(void)died;
-(void)goal;
-(void)resume;
-(void)pause;
-(void)start;
-(void)firstUpdate;
-(void)pickupCollected:(id)collected trialLayer:(id)layer wheely:(id)wheely;
-(void)setPickups:(unsigned)pickups total:(unsigned)total;
-(void)setTimer:(int)timer;
-(void)setWheelyPosition:(CGPoint)position;
-(void)removeGoalInfo;
-(void)fadeGoalInfo;
-(void)setLevelInfo:(id)info target:(id)target;
-(void)setLevelInfo:(id)info;
-(void)message:(id)message color:(ccColor3B)color;
-(void)createGameControllers:(id)controllers;
-(void)showTouchControls:(BOOL)controls;
-(void)hideTouchControls:(BOOL)controls;
-(id)initWithSession:(id)session;
@end

