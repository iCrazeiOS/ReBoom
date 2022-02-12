/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "TrialGameControllerDelegate.h"
#import "HSMenuLayer.h"
#import "Boom-Structs.h"

@class CCMenu;

__attribute__((visibility("hidden")))
@interface TutorialChallenge : HSMenuLayer <TrialGameControllerDelegate> {
	CCMenu* menuItems;
}
+(id)menuWithSession:(id)session;
+(id)layerWithMenu:(id)menu session:(id)session;
-(void).cxx_destruct;
-(id)controllerItemForIndex:(unsigned)index;
-(id)controllerItemConfig;
-(unsigned)controllerDefaultItem;
-(void)controllerCancel;
-(void)postFirstVisit;
-(void)cleanup;
-(void)onEnter;
-(id)initWithMenu:(id)menu session:(id)session;
-(id)initWithMenu:(id)menu;
@end

