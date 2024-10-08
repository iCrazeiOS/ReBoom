/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCSprite.h"

@class CCSpriteFrame, NSArray;

__attribute__((visibility("hidden")))
@interface BoostIndicator : CCSprite {
	NSArray* frames;
	CCSpriteFrame* breakFrame;
	BOOL breakOn;
}
+(id)boostIndicator;
-(void).cxx_destruct;
-(void)breakOff;
-(void)breakOn;
-(void)triggerBreakOn;
-(void)setBoostLevel:(unsigned)level;
-(void)setupFrames;
@end

