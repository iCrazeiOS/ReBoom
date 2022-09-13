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
@interface CCRotateBy : CCActionInterval <NSCopying> {
	float angle_;
	float startAngle_;
}
+(id)actionWithDuration:(float)duration angle:(float)angle;
-(id)reverse;
-(void)update:(float)update;
-(void)startWithTarget:(id)target;
-(id)copyWithZone:(NSZone*)zone;
-(id)initWithDuration:(float)duration angle:(float)angle;
@end
