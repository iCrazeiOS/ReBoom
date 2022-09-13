/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "HSTableView.h"
#import "HSTableViewDataSource.h"
#import "HSTableViewDelegate.h"

@class NSMutableDictionary, NSMutableArray, Level, NSString, TrialSession;

__attribute__((visibility("hidden")))
@interface GoalDialogFriendsList : HSTableView <HSTableViewDataSource, HSTableViewDelegate> {
	Level* level;
	TrialSession* session;
	int time;
	int diff;
	NSMutableArray* list;
	NSMutableDictionary* nicknames;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
-(void).cxx_destruct;
-(void)tableView:(id)view didSelectRowAtIndexPath:(id)indexPath;
-(float)tableView:(id)view heightForRowAtIndexPath:(id)indexPath;
-(float)tableView:(id)view heightForHeaderInSection:(int)section;
-(int)tableView:(id)view numberOfRowsInSection:(int)section;
-(int)numberOfSectionsInTableView:(id)tableView;
-(id)tableView:(id)view cellForRowAtIndexPath:(id)indexPath;
-(id)tableView:(id)view viewForHeaderInSection:(int)section;
-(void)cleanup;
-(id)initWithSize:(CGSize)size level:(id)level session:(id)session time:(int)time diff:(int)diff;
@end
