/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "HSMenuItem.h"


__attribute__((visibility("hidden")))
@interface InfoButton : HSMenuItem {
	BOOL relativeScaleSet;
	float relativeScale;
}
+(id)starButtonWithBlock:(id)block;
+(id)infoButtonWithBlock:(id)block;
-(void)setScale:(float)scale;
-(void)setRelativeScale:(float)scale;
@end

