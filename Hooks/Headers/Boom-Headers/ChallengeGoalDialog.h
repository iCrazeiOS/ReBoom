/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "HSMenuLayer.h"
#import "TrialGameControllerDelegate.h"
#import "UITextViewDelegate.h"

@class TrialSession, NSMutableDictionary, NSString, Wheely, UITextView, TrialLayer;

__attribute__((visibility("hidden")))
@interface ChallengeGoalDialog : HSMenuLayer <TrialGameControllerDelegate, UITextViewDelegate> {
	TrialSession* session;
	TrialLayer* trialLayer;
	BOOL trialLayerFadedOut;
	unsigned retriesLeft;
	int yourTime;
	BOOL youWon;
	BOOL youHasTime;
	BOOL youHasPlayed;
	int opponentTime;
	BOOL opponentWon;
	BOOL opponentHasTime;
	BOOL opponentHasPlayed;
	int timeDiff;
	BOOL notFinishedAndNoRetriesLeft;
	NSMutableDictionary* buttons;
	Wheely* opponentHero;
	UITextView* inputView;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
+(id)layerWithMenu:(id)menu session:(id)session;
+(id)menuWithSession:(id)session;
-(void).cxx_destruct;
-(id)controllerItemForIndex:(unsigned)index;
-(id)controllerItemConfig;
-(unsigned)controllerDefaultItem;
-(void)controllerCancel;
-(void)postFirstVisit;
-(void)postTransitionIn;
-(void)cleanup;
-(void)setOpacity:(unsigned char)opacity;
-(void)createButtons;
-(void)onEnter;
-(id)initWithMenu:(id)menu session:(id)session;
-(id)initWithMenu:(id)menu;
@end
