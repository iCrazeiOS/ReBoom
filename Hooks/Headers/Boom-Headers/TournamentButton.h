/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "HSMenuItem.h"

@class Tournament, HSBadgeIndicator, HSLabelSafeBMFont;

__attribute__((visibility("hidden")))
@interface TournamentButton : HSMenuItem {
	HSLabelSafeBMFont* timeLabel;
	Tournament* currentTournament;
	BOOL syncFailure;
	BOOL hasSpinner;
	HSBadgeIndicator* infoBadge;
}
+(id)tournamentJoinButtonWithFailBlock:(id)failBlock;
+(id)tournamentButtonWithMenu:(id)menu;
-(void).cxx_destruct;
-(void)tournamentsClientSyncFailed;
-(void)tournamentsClientSyncCompleted;
-(void)cleanup;
-(void)updateTimeLabel;
-(void)adjustEmptyLabel;
-(void)onEnter;
@end
