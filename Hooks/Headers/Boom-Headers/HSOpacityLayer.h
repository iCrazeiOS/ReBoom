/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCLayer.h"
#import "CCRGBAProtocol.h"

@class NSString;

__attribute__((visibility("hidden")))
@interface HSOpacityLayer : CCLayer <CCRGBAProtocol> {
	unsigned char opacity_;
	ccColor3B color_;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) NSUInteger hash;
//@property(nonatomic) ccColor3B color;
@property(assign, nonatomic) CGFloat opacity;
-(id)init;
@end
