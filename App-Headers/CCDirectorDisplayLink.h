/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "CCDirectorIOS.h"
#import "Boom-Structs.h"

@class CADisplayLink;

__attribute__((visibility("hidden")))
@interface CCDirectorDisplayLink : CCDirectorIOS {
	CADisplayLink* displayLink_;
	double lastDisplayTime_;
}
-(void)dealloc;
-(void)threadMainLoop;
-(void)calculateDeltaTime;
-(void)stopAnimation;
-(void)startAnimation;
-(void)setAnimationInterval:(double)interval;
-(void)mainLoop:(id)loop;
@end

