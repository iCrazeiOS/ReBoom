/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCGrid3DAction.h"


__attribute__((visibility("hidden")))
@interface CCWaves : CCGrid3DAction {
	int waves;
	float amplitude;
	float amplitudeRate;
	BOOL vertical;
	BOOL horizontal;
}
@property(assign, nonatomic) float amplitudeRate;
@property(assign, nonatomic) float amplitude;
+(id)actionWithWaves:(int)waves amplitude:(float)amplitude horizontal:(BOOL)horizontal vertical:(BOOL)vertical grid:(ccGridSize)grid duration:(float)duration;
-(id)copyWithZone:(NSZone*)zone;
-(void)update:(float)update;
-(id)initWithWaves:(int)waves amplitude:(float)amplitude horizontal:(BOOL)horizontal vertical:(BOOL)vertical grid:(ccGridSize)grid duration:(float)duration;
@end

