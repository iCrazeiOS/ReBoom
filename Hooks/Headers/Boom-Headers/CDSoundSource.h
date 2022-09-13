/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "CDAudioInterruptProtocol.h"
#import "CDAudioTransportProtocol.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class CDSoundEngine, NSString;

__attribute__((visibility("hidden")))
@interface CDSoundSource : XXUnknownSuperclass <CDAudioTransportProtocol, CDAudioInterruptProtocol> {
	int lastError;
	unsigned _sourceId;
	unsigned _sourceIndex;
	CDSoundEngine* _engine;
	int _soundId;
	float _preMuteGain;
	BOOL enabled_;
	BOOL mute_;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(readonly, assign) int lastError;
@property(readonly, assign) float durationInSeconds;
@property(assign, nonatomic) int soundId;
@property(readonly, assign) BOOL isPlaying;
@property(assign, nonatomic) BOOL looping;
@property(assign, nonatomic) float pan;
@property(assign, nonatomic) float gain;
@property(assign, nonatomic) float pitch;
-(void)setEnabled:(BOOL)enabled;
-(BOOL)enabled;
-(void)setMute:(BOOL)mute;
-(BOOL)mute;
-(BOOL)rewind;
-(BOOL)pause;
-(BOOL)play;
-(BOOL)stop;
-(void)dealloc;
-(id)init:(unsigned)init sourceIndex:(int)index soundEngine:(id)engine;
@end
