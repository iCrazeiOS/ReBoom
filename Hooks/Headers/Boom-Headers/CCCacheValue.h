/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class NSString;

__attribute__((visibility("hidden")))
@interface CCCacheValue : XXUnknownSuperclass {
	NSString* fullpath_;
	int resolutionType_;
}
@property(assign, nonatomic) int resolutionType;
@property(retain, nonatomic) NSString* fullpath;
-(void)dealloc;
-(id)initWithFullPath:(id)fullPath resolutionType:(int)type;
@end
