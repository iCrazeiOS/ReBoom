/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library


__attribute__((visibility("hidden")))
@interface JKSerializer : XXUnknownSuperclass {
	JKEncodeState* encodeState;
}
+(id)serializeObject:(id)object options:(unsigned)options encodeOption:(unsigned)option block:(id)block delegate:(id)delegate selector:(SEL)selector error:(id*)error;
-(void)dealloc;
-(void)releaseState;
-(id)serializeObject:(id)object options:(unsigned)options encodeOption:(unsigned)option block:(id)block delegate:(id)delegate selector:(SEL)selector error:(id*)error;
@end
