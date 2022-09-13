/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "TrialGameControllerDelegate.h"
#import "HSTableViewDataSource.h"
#import "HSTableViewDelegate.h"
#import "HSMenuLayer.h"

@class CCMenu, NSMutableArray, HSTableView, SignPost, NSString;

__attribute__((visibility("hidden")))
@interface WorldScoreBoard : HSMenuLayer <HSTableViewDelegate, HSTableViewDataSource, TrialGameControllerDelegate> {
	HSTableView* tableView;
	NSMutableArray* players;
	unsigned selfRank;
	SignPost* signPost;
	CCMenu* menuItems;
	BOOL reportDelegateAfterVisitAndTableIsReady;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
+(id)scene;
-(void).cxx_destruct;
-(id)controllerItemForIndex:(unsigned)index;
-(id)controllerItemConfig;
-(unsigned)controllerDefaultItem;
-(void)controllerCancel;
-(void)postFirstVisit;
-(void)postTransitionIn;
-(id)menuForUserAttention;
-(BOOL)canGrabUserAttention:(id)attention;
-(void)visit;
-(void)updatePost;
-(int)tableView:(id)view numberOfRowsInSection:(int)section;
-(int)numberOfSectionsInTableView:(id)tableView;
-(id)tableView:(id)view cellForRowAtIndexPath:(id)indexPath;
-(id)tableView:(id)view viewForHeaderInSection:(int)section;
-(void)tableView:(id)view didSelectRowAtIndexPath:(id)indexPath;
-(float)tableView:(id)view heightForHeaderInSection:(int)section;
-(float)tableView:(id)view heightForRowAtIndexPath:(id)indexPath;
-(void)cleanup;
-(void)onExit;
-(void)onEnter;
-(void)createMenu;
-(void)dealloc;
-(id)initWithMenu:(id)menu;
@end
