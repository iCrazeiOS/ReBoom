/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class NSNumber, NSDate, NSString;

__attribute__((visibility("hidden")))
@interface Theme : XXUnknownSuperclass {
}
@property(retain, nonatomic) NSDate* visible;
@property(retain, nonatomic) NSString* themeId;
@property(retain, nonatomic) NSNumber* locked;
@property(retain, nonatomic) NSNumber* intoPlayed;
@property(assign, nonatomic) BOOL justUnlocked;
+(void)reportChangedThemesToGameCenter;
+(id)mergeGameState:(id)state;
+(id)gameStateChecksums;
+(id)gameStateForTheme:(id)theme;
+(void)changedLevelId:(id)anId;
+(id)unLockedThemes;
+(id)newThemeStateById:(id)anId;
+(id)themeStateById:(id)anId;
-(void)reportResultsToGameCenter;
-(void)shouldReportToGameCenter;
-(id)gameState;
-(id)serialize;
-(void)willSave;
-(id)totalTime;
-(id)targetCompleted_super_stars_previous:(id)previous;
-(id)targetCompleted_super_stars:(id)stars;
-(id)targetCompleted_medals_previous:(id)previous;
-(id)targetCompleted_medals:(id)medals;
-(id)targetCompleted_wc_win:(id)win;
-(id)targetCompleted_wc_top_5:(id)a5;
-(id)targetCompleted_wc_games:(id)games;
-(id)targetCompleted_vs_wins:(id)wins;
-(id)targetCompleted_active_vs:(id)vs;
-(id)targetCompleted_invited_friends:(id)friends;
-(BOOL)targetsFulfilled;
-(BOOL)unlock:(BOOL)unlock;
-(BOOL)isCompleted;
-(id)previousTheme;
-(void)setVisible:(id)visible force:(BOOL)force;
@end

