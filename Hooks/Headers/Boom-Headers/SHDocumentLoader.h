/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class NSMutableDictionary;

__attribute__((visibility("hidden")))
@interface SHDocumentLoader : XXUnknownSuperclass {
	NSMutableDictionary* scenes;
}
+(id)sharedInstance;
-(void).cxx_destruct;
-(id)animationsForSHDocument:(id)shdocument;
-(id)physicsDictionaryForSpriteNamed:(id)spriteNamed inDocument:(id)document;
-(id)textureDictionaryForSpriteNamed:(id)spriteNamed inDocument:(id)document;
-(id)sceneNodeForSHDocument:(id)shdocument;
-(id)init;
-(void)dealloc;
@end
