/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class NSArray, NSMutableArray, NSString, NSURL;

@interface CLSMachOBinary : XXUnknownSuperclass {
	NSURL* _url;
	CLSMachOFile _file;
	NSMutableArray* _slices;
	NSString* _instanceIdentifier;
}
@property(readonly, copy, nonatomic) NSString* instanceIdentifier;
@property(readonly, assign, nonatomic) NSArray* slices;
@property(readonly, copy, nonatomic) NSString* path;
@property(readonly, copy, nonatomic) NSURL* URL;
+(id)hashNSString:(id)string;
+(id)MachOBinaryWithPath:(id)path;
-(void).cxx_destruct;
-(id)sliceForArchitecture:(id)architecture;
-(void)enumerateUUIDs:(id)uuids;
-(void)dealloc;
-(id)initWithURL:(id)url;
@end

