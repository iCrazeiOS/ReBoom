/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCActionInstant.h"


__attribute__((visibility("hidden")))
@interface CCFlipX : CCActionInstant {
	BOOL flipX;
}
+(id)actionWithFlipX:(BOOL)flipX;
-(id)copyWithZone:(NSZone*)zone;
-(id)reverse;
-(void)update:(float)update;
-(id)initWithFlipX:(BOOL)flipX;
@end

