/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "NSCopying.h"
#import "CCActionInterval.h"


__attribute__((visibility("hidden")))
@interface CCRepeat : CCActionInterval <NSCopying> {
	unsigned times_;
	unsigned total_;
	float nextDt_;
	BOOL isActionInstant_;
	CCFiniteTimeAction* innerAction_;
}
@property(retain, nonatomic) CCFiniteTimeAction* innerAction;
+(id)actionWithAction:(id)action times:(unsigned)times;
-(id)reverse;
-(BOOL)isDone;
-(void)update:(float)update;
-(void)stop;
-(void)startWithTarget:(id)target;
-(void)dealloc;
-(id)copyWithZone:(NSZone*)zone;
-(id)initWithAction:(id)action times:(unsigned)times;
@end
