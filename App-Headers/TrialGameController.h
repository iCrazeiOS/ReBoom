/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class NSMutableDictionary, HSMenuItem, NSMutableArray, TrialSession, NSObject;
@protocol TrialGameControllerDelegate;

__attribute__((visibility("hidden")))
@interface TrialGameController : XXUnknownSuperclass {
	NSMutableArray* registeredControllers;
	TrialSession* session;
	BOOL isBreaking;
	BOOL Object402;
	BOOL Object353;
	BOOL gasPressed;
	BOOL leftPressedDuringBreak;
	BOOL rightPressedDuringBreak;
	BOOL gasPressedDuringBreak;
	BOOL isSimulator;
	BOOL isConnected;
	NSObject<TrialGameControllerDelegate>* delegate;
	HSMenuItem* item;
	int itemIndex;
	NSMutableDictionary* itemIndexCache;
	BOOL enabledFastMenuScrolling;
	float pressedTime;
}
@property(readonly, assign, nonatomic) BOOL isSimulator;
@property(retain, nonatomic) NSObject<TrialGameControllerDelegate>* delegate;
@property(readonly, assign, nonatomic) BOOL isConnected;
@property(retain, nonatomic) TrialSession* session;
+(id)sharedController;
-(void).cxx_destruct;
-(void)controllerTogglePauseResumeState;
-(void)updateGas;
-(void)resetItemCache:(id)cache;
-(void)delegateSetItemIndex:(int)index;
-(int)delegateControllerDefaultItem;
-(id)getItemForDPad:(BOOL)dpad key:(int)key;
-(id)controllerItemForTable:(id)table direction:(int)direction preSelectedIdentifier:(id)identifier;
-(void)controllerCallBackDPadRight:(BOOL)right;
-(void)controllerCallBackDPadLeft:(BOOL)left;
-(void)controllerCallBackDPadDown:(BOOL)down;
-(void)controllerCallBackDPadUp:(BOOL)up;
-(void)controllerCallBackShoulderRight:(BOOL)right;
-(void)controllerCallBackShoulderLeft:(BOOL)left;
-(void)controllerCallBackFaceButton:(BOOL)button button:(int)button2;
-(void)setupController:(id)controller;
-(void)controllersConnected;
-(void)controllersDisconnected;
-(void)setupControllers:(id)controllers;
-(void)listenForControllers;
-(void)setupSimulatorController;
-(void)update:(float)update;
-(void)delegateIsReady;
-(void)removeDelegate:(id)delegate;
-(void)removeSession:(id)session;
-(void)reset;
-(id)init;
@end

