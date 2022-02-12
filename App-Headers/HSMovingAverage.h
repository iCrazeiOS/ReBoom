/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class NSMutableArray;

__attribute__((visibility("hidden")))
@interface HSMovingAverage : XXUnknownSuperclass {
	float _movingAverage;
	float _cumulativeAverage;
	NSMutableArray* _queue;
	unsigned _period;
	unsigned _count;
}
@property(assign, nonatomic) float cumulativeAverage;
@property(assign, nonatomic) float movingAverage;
@property(assign, nonatomic) unsigned count;
@property(assign, nonatomic) unsigned period;
@property(retain, nonatomic) NSMutableArray* queue;
-(void).cxx_destruct;
-(void)reset;
-(void)addFloat:(float)aFloat;
-(void)addDatum:(id)datum;
-(id)initWithPeriod:(unsigned)period;
@end

