/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCGrid3DAction.h"


__attribute__((visibility("hidden")))
@interface CCLens3D : CCGrid3DAction {
	CGPoint position_;
	float radius_;
	float lensEffect_;
	BOOL dirty_;
}
@property(assign, nonatomic) CGPoint position;
@property(assign, nonatomic) float lensEffect;
+(id)actionWithPosition:(CGPoint)position radius:(float)radius grid:(ccGridSize)grid duration:(float)duration;
-(void)update:(float)update;
-(id)copyWithZone:(NSZone*)zone;
-(id)initWithPosition:(CGPoint)position radius:(float)radius grid:(ccGridSize)grid duration:(float)duration;
@end

