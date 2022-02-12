/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "CCTiledGrid3DAction.h"
#import "Boom-Structs.h"


__attribute__((visibility("hidden")))
@interface CCWavesTiles3D : CCTiledGrid3DAction {
	int waves;
	float amplitude;
	float amplitudeRate;
}
@property(assign, nonatomic) float amplitudeRate;
@property(assign, nonatomic) float amplitude;
+(id)actionWithWaves:(int)waves amplitude:(float)amplitude grid:(ccGridSize)grid duration:(float)duration;
-(void)update:(float)update;
-(id)copyWithZone:(NSZone*)zone;
-(id)initWithWaves:(int)waves amplitude:(float)amplitude grid:(ccGridSize)grid duration:(float)duration;
@end

