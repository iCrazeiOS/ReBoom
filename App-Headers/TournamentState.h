/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class Tournament, NSDate;

__attribute__((visibility("hidden")))
@interface TournamentState : XXUnknownSuperclass {
}
@property(retain, nonatomic) Tournament* lastActive;
@property(retain, nonatomic) Tournament* current;
@property(retain, nonatomic) NSDate* lastSync;
@property(assign, nonatomic) BOOL dirty;
+(id)loadState;
+(void)unbindInstance;
+(id)sharedInstance;
-(void)willSave;
-(void)fixState;
-(BOOL)stale;
-(void)resetCurrent;
-(void)reset;
@end

