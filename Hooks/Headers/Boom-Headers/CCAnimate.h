/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "NSCopying.h"
#import "CCActionInterval.h"

@class NSData, CCAnimation;

__attribute__((visibility("hidden")))
@interface CCAnimate : CCActionInterval <NSCopying> {
	NSData* splitTimes_;
	int nextFrame_;
	CCAnimation* animation_;
	id origFrame_;
	unsigned executedLoops_;
}
@property(retain, nonatomic) CCAnimation* animation;
+(id)actionWithAnimation:(id)animation;
+(id)actionWithDuration:(float)duration animation:(id)animation restoreOriginalFrame:(BOOL)frame;
+(id)actionWithAnimation:(id)animation restoreOriginalFrame:(BOOL)frame;
-(id)reverse;
-(void)update:(float)update;
-(void)stop;
-(void)startWithTarget:(id)target;
-(void)dealloc;
-(id)copyWithZone:(NSZone*)zone;
-(id)initWithAnimation:(id)animation;
-(id)initWithDuration:(float)duration animation:(id)animation restoreOriginalFrame:(BOOL)frame;
-(id)initWithAnimation:(id)animation restoreOriginalFrame:(BOOL)frame;
@end
