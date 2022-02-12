/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "CCTiledGrid3DAction.h"
#import "Boom-Structs.h"


__attribute__((visibility("hidden")))
@interface CCTurnOffTiles : CCTiledGrid3DAction {
	int seed;
	unsigned tilesCount;
	int* tilesOrder;
}
+(id)actionWithSeed:(int)seed grid:(ccGridSize)grid duration:(float)duration;
-(void)update:(float)update;
-(void)startWithTarget:(id)target;
-(void)turnOffTile:(ccGridSize)tile;
-(void)turnOnTile:(ccGridSize)tile;
-(void)shuffle:(int*)shuffle count:(unsigned)count;
-(void)dealloc;
-(id)copyWithZone:(NSZone*)zone;
-(id)initWithSeed:(int)seed grid:(ccGridSize)grid duration:(float)duration;
@end

