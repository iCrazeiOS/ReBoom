/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class NSRecursiveLock;

@interface FABAsyncOperation : XXUnknownSuperclass {
	BOOL _internalExecuting;
	BOOL _internalFinished;
	id _asyncCompletion;
	NSRecursiveLock* _lock;
}
@property(copy, nonatomic) id asyncCompletion;
@property(retain, nonatomic) NSRecursiveLock* lock;
-(void).cxx_destruct;
-(void)finishWithError:(id)error;
-(void)markDone;
-(void)markStarted;
-(void)unlockedMarkComplete;
-(void)unlockedMarkStarted;
-(void)unlockedMarkFinished;
-(BOOL)checkForCancellation;
-(void)lock:(id)lock;
-(void)changeValueForKey:(id)key inBlock:(id)block;
-(void)start;
-(BOOL)isFinished;
-(BOOL)isExecuting;
-(BOOL)isAsynchronous;
-(BOOL)isConcurrent;
-(id)init;
@end

