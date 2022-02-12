/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class NSMutableArray, NSMutableDictionary, CDSoundEngine;

__attribute__((visibility("hidden")))
@interface CDBufferManager : XXUnknownSuperclass {
	NSMutableDictionary* loadedBuffers;
	NSMutableArray* freedBuffers;
	CDSoundEngine* soundEngine;
	int nextBufferId;
}
-(void)releaseBufferForFile:(id)file;
-(int)bufferForFile:(id)file create:(BOOL)create;
-(void)dealloc;
-(id)initWithEngine:(id)engine;
@end

