/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "LHSprite.h"


__attribute__((visibility("hidden")))
@interface Trampoline : LHSprite {
	LHSprite* left;
	LHSprite* trampoline;
	LHSprite* trampolineSprite;
	b2PrismaticJoint* trampolineJoint;
	unsigned links;
	float forceFactor;
}
-(void).cxx_destruct;
-(void)postUpdate:(float)update;
-(void)postInitialization;
-(void)cleanup;
@end

