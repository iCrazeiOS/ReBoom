/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "CCActionCamera.h"
#import "Boom-Structs.h"
#import "NSCopying.h"


__attribute__((visibility("hidden")))
@interface CCOrbitCamera : CCActionCamera <NSCopying> {
	float radius_;
	float deltaRadius_;
	float angleZ_;
	float deltaAngleZ_;
	float angleX_;
	float deltaAngleX_;
	float radZ_;
	float radDeltaZ_;
	float radX_;
	float radDeltaX_;
}
+(id)actionWithDuration:(float)duration radius:(float)radius deltaRadius:(float)radius3 angleZ:(float)z deltaAngleZ:(float)z5 angleX:(float)x deltaAngleX:(float)x7;
-(void)sphericalRadius:(float*)radius zenith:(float*)zenith azimuth:(float*)azimuth;
-(void)update:(float)update;
-(void)startWithTarget:(id)target;
-(id)initWithDuration:(float)duration radius:(float)radius deltaRadius:(float)radius3 angleZ:(float)z deltaAngleZ:(float)z5 angleX:(float)x deltaAngleX:(float)x7;
-(id)copyWithZone:(NSZone*)zone;
@end

