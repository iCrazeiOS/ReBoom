/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "TrialGameControllerDelegate.h"
#import "HSMenuLayer.h"

@class HSMenuItem;

__attribute__((visibility("hidden")))
@interface UnlockFeature : HSMenuLayer <TrialGameControllerDelegate> {
	HSMenuItem* okButton;
}
+(id)layerWithMenu:(id)menu reward:(id)reward;
-(void).cxx_destruct;
-(id)controllerItemForIndex:(unsigned)index;
-(id)controllerItemConfig;
-(unsigned)controllerDefaultItem;
-(void)controllerCancel;
-(void)postFirstVisit;
-(void)postTransitionIn;
-(void)cleanup;
-(id)initWithMenu:(id)menu reward:(id)reward;
@end
