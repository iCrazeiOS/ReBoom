/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "CCTouchHandler.h"

@class NSMutableSet;

__attribute__((visibility("hidden")))
@interface CCTargetedTouchHandler : CCTouchHandler {
	BOOL swallowsTouches;
	NSMutableSet* claimedTouches;
}
@property(readonly, assign, nonatomic) NSMutableSet* claimedTouches;
@property(assign, nonatomic) BOOL swallowsTouches;
+(id)handlerWithDelegate:(id)delegate priority:(int)priority swallowsTouches:(BOOL)touches;
-(void)dealloc;
-(id)initWithDelegate:(id)delegate priority:(int)priority swallowsTouches:(BOOL)touches;
@end
