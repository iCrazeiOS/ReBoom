/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class NSArray, NSMutableDictionary, GKLocalPlayer, NSDate;
@protocol NSObject, HSGameCenterManagerDelegate;

__attribute__((visibility("hidden")))
@interface HSGameCenterManager : XXUnknownSuperclass {
	BOOL isDeviceSupported;
	BOOL isSessionValid;
	BOOL isAuthenticated;
	BOOL isAuthenticating;
	BOOL deviceRequiresManualNetworkRetry;
	BOOL deviceRequiresManualSessionResume;
	GKLocalPlayer* player;
	NSMutableDictionary* playerAchievements;
	NSMutableDictionary* playerScores;
	NSMutableDictionary* playerLeaderboardRanking;
	NSArray* gameAchievements;
	id<NSObject, HSGameCenterManagerDelegate> delegate;
	NSDate* authenticationStartTime;
	BOOL deviceHasShowsBannerProperty;
	BOOL hasCustomBannerSupport;
	BOOL hasLocalChanges;
	BOOL devEnvironment;
}
@property(assign, nonatomic) BOOL hasLocalChanges;
@property(readonly, assign, nonatomic) BOOL isAuthenticated;
@property(readonly, assign, nonatomic) BOOL isAuthenticating;
@property(retain, nonatomic) NSArray* gameAchievements;
@property(retain, nonatomic) id<NSObject, HSGameCenterManagerDelegate> delegate;
+(void)reset;
+(BOOL)isAvailable;
+(id)sharedInstance;
-(void).cxx_destruct;
-(int)getPlayerBoardRankNormalized:(id)normalized;
-(id)getPlayerBoardScore:(id)score;
-(id)getPlayerAchievement:(id)achievement;
-(void)resumeSession;
-(void)pauseSession;
-(void)resetPlayerRanking;
-(void)resetPlayerScores;
-(void)resetPlayerAchievements;
-(void)reportAchievement:(id)achievement percentComplete:(double)complete withBanner:(BOOL)banner;
-(void)reportAchievement:(id)achievement percentComplete:(double)complete;
-(void)reportAchievement:(id)achievement;
-(void)reportScore:(long long)score forCategory:(id)category;
-(void)reportScore:(long long)score forCategory:(id)category descending:(BOOL)descending;
-(double)getAuthenticationTimeElapsed;
-(void)alertView:(id)view didDismissWithButtonIndex:(int)buttonIndex;
-(void)authenticate:(BOOL)authenticate callback:(id)callback;
-(void)authenticate;
-(void)syncLeaderboardRanking:(id)ranking;
-(void)syncLeaderboardRanking;
-(void)syncGameAchievements;
-(void)unLoadPlayer;
-(void)archiveState;
-(id)getPlayer;
-(void)syncPlayerScore:(id)score;
-(void)syncPlayerAchievement:(id)achievement;
-(void)syncPlayer;
-(void)loadPlayer:(id)player;
-(id)loadLocalGameData:(id)data;
-(void)archiveLocalGameData:(id)data file:(id)file;
-(id)identifierFor:(id)aFor type:(id)type;
-(id)init;
@end

