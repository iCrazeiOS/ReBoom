/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "HSSceneLayer.h"

@class HSProgressBar;

__attribute__((visibility("hidden")))
@interface HSLoadingScreen : HSSceneLayer {
	CGSize screenSize;
	id action;
	HSProgressBar* progressBar;
}
+(id)sceneWithAction:(id)action;
-(void).cxx_destruct;
-(void)cleanup;
-(void)setProgress:(float)progress;
-(void)showProgressBar;
-(void)onEnterTransitionDidFinish;
-(id)initWithAction:(id)action;
@end

