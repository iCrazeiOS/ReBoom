/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library


__attribute__((visibility("hidden")))
@interface CCTimer : XXUnknownSuperclass {
	id target;
	/*function-pointer*/ void* impMethod;
	float elapsed;
	BOOL runForever;
	BOOL useDelay;
	unsigned nTimesExecuted;
	unsigned repeat;
	float delay;
	float interval;
	SEL selector;
}
@property(assign, nonatomic) float interval;
+(id)timerWithTarget:(id)target selector:(SEL)selector interval:(float)interval;
+(id)timerWithTarget:(id)target selector:(SEL)selector;
-(void)update:(float)update;
-(void)dealloc;
-(id)description;
-(id)initWithTarget:(id)target selector:(SEL)selector interval:(float)interval repeat:(unsigned)repeat delay:(float)delay;
-(id)initWithTarget:(id)target selector:(SEL)selector;
-(id)init;
@end

