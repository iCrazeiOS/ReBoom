/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "CCTransitionScene.h"
#import "Boom-Structs.h"


__attribute__((visibility("hidden")))
@interface CCTransitionFade : CCTransitionScene {
	ccColor4B color;
}
+(id)transitionWithDuration:(float)duration scene:(id)scene withColor:(ccColor3B)color;
-(void)onExit;
-(void)onEnter;
-(id)initWithDuration:(float)duration scene:(id)scene;
-(id)initWithDuration:(float)duration scene:(id)scene withColor:(ccColor3B)color;
@end
