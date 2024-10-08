/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "CCTiledGrid3DAction.h"
#import "Boom-Structs.h"


__attribute__((visibility("hidden")))
@interface CCShakyTiles3D : CCTiledGrid3DAction {
	int randrange;
	BOOL shakeZ;
}
+(id)actionWithRange:(int)range shakeZ:(BOOL)z grid:(ccGridSize)grid duration:(float)duration;
-(void)update:(float)update;
-(id)copyWithZone:(NSZone*)zone;
-(id)initWithRange:(int)range shakeZ:(BOOL)z grid:(ccGridSize)grid duration:(float)duration;
@end

