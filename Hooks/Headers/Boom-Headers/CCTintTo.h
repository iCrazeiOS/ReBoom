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
@interface CCTintTo : CCActionInterval <NSCopying> {
	ccColor3B to_;
	ccColor3B from_;
}
+(id)actionWithDuration:(float)duration red:(unsigned char)red green:(unsigned char)green blue:(unsigned char)blue;
-(void)update:(float)update;
-(void)startWithTarget:(id)target;
-(id)copyWithZone:(NSZone*)zone;
-(id)initWithDuration:(float)duration red:(unsigned char)red green:(unsigned char)green blue:(unsigned char)blue;
@end
