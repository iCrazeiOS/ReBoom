/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCLayer.h"

@class CCParallaxNode, NSString;

__attribute__((visibility("hidden")))
@interface MenuTrialBackground : CCLayer {
	CGSize screenSize;
	CCParallaxNode* parallaxBackground;
	BOOL autoParallax;
	NSString* currentBg;
	BOOL firstUpdate;
	BOOL shouldPlayThemeSong;
}
@property(assign, nonatomic) BOOL autoParallax;
-(void).cxx_destruct;
-(void)cleanup;
-(void)updateParallax:(CGPoint)parallax scale:(float)scale;
-(void)update:(float)update;
-(void)onEnterTransitionDidFinish;
-(void)onEnter;
-(BOOL)changeTheme:(id)theme;
-(BOOL)changeTheme;
-(id)init;
@end

