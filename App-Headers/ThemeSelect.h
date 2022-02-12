/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "TrialGameControllerDelegate.h"
#import "HSScrollViewDelegate.h"
#import "Boom-Structs.h"
#import "HSMenuLayer.h"

@class NSMutableDictionary, CCMenu, HSParticleSystemQuad, Wheely, LevelHelperLoader, CCSprite, Cage, NSDictionary, HSAdjustedOpacityNode, HSOpacityNode, HSLabelSafeBMFont, Theme, ThemeSelector, LHNode, NSString, HSScrollView, Object156, CCLayerColor;

__attribute__((visibility("hidden")))
@interface ThemeSelect : HSMenuLayer <HSScrollViewDelegate, TrialGameControllerDelegate> {
	HSScrollView* scrollLayer;
	HSAdjustedOpacityNode* map;
	LHNode* lhLayer;
	b2World* world;
	LevelHelperLoader* lh;
	float timeAccumulator;
	float deltaTime;
	Cage* goalCage;
	float lastScrollX;
	Wheely* hero;
	BOOL started;
	BOOL ropeAdded;
	BOOL shouldShowNormal;
	CCSprite* pinky;
	ThemeSelector* introJungle;
	ThemeSelector* introCity;
	ThemeSelector* introIce;
	ThemeSelector* introPyramid;
	ThemeSelector* introFactory;
	ThemeSelector* introFestival;
	ThemeSelector* introExtreme;
	Object156* wheely;
	HSOpacityNode* wheelyLayer;
	BOOL cageHit;
	CCSprite* bridge;
	CCLayerColor* splashBG;
	CCLayerColor* introBG;
	CCSprite* Object377;
	unsigned currentIntroMusic;
	HSParticleSystemQuad* dustLeft;
	HSParticleSystemQuad* dustRight;
	CCMenu* menuItems;
	CCMenu* skipMenu;
	float timer;
	BOOL isPlayingIntro;
	NSMutableDictionary* themeSelectors;
	Theme* introTheme;
	NSDictionary* themeIntroGroupSettings;
	HSLabelSafeBMFont* collectedMedalsLabel;
	NSString* themeId;
	unsigned selectedThemeIndex;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(readonly, assign, nonatomic) ThemeSelector* introJungle;
@property(readonly, assign, nonatomic) BOOL isPlayingIntro;
+(void)loadFriendsPosition;
+(id)friendAtTheme:(id)theme;
+(id)layerWithMenu:(id)menu themeId:(id)anId;
+(id)scene;
-(void).cxx_destruct;
-(void)autoScrollTo:(id)to;
-(id)controllerItemForIndex:(unsigned)index;
-(id)controllerItemConfig;
-(int)controllerItemIndex:(int)index;
-(unsigned)controllerDefaultItem;
-(void)controllerCancel;
-(void)postFirstVisit;
-(void)postTransitionIn;
-(void)scrollViewDidScroll:(id)scrollView;
-(void)updatePositions:(float)positions;
-(void)update:(float)update;
-(void)setupWorld:(id)world cageSelector:(SEL)selector;
-(void)dealloc;
-(void)cleanup;
-(void)onEnter;
-(void)registerOfferEvents;
-(id)transitionInAction;
-(void)setupIntroComing;
-(void)animateComingBridge;
-(void)comingBridgeDust;
-(void)comingStop;
-(void)comingIntroDone;
-(void)setupIntroExtreme;
-(void)themeIntroUnlockExtreme;
-(void)themeIntroGoal:(id)goal;
-(void)setupIntroForTheme:(id)theme;
-(void)themeIntroAnimateBridge;
-(void)themeIntroBridgeDust;
-(void)themeIntroCageOpen;
-(void)themeIntroAnimateHandsQuick;
-(void)themeIntroUnlockTheme;
-(void)themeIntroDone;
-(void)goal:(id)goal;
-(void)setupIntro;
-(void)fadeSplash;
-(void)showPinky;
-(void)quake;
-(void)shakeWorld;
-(void)animateLaughter;
-(void)animateHands;
-(void)poffPinky;
-(void)lowerCage;
-(void)animateHelp;
-(void)showBridge;
-(void)startEngine;
-(void)cageOpen;
-(void)animateHandsQuick;
-(void)poffBridge;
-(void)animateLaughter2;
-(void)introComplete;
-(void)extremeVisible;
-(void)setupNormal;
-(void)setupThemeSelect;
-(id)map;
-(id)initWithMenu:(id)menu themeId:(id)anId;
-(id)initWithMenu:(id)menu;
@end

