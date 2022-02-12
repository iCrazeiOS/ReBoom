/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library
#import "NSStreamDelegate.h"

@class NSData, NSOutputStream, NSString;

@interface FABMultipartMimeStreamEncoder : XXUnknownSuperclass <NSStreamDelegate> {
	unsigned _length;
	NSString* _boundary;
	NSOutputStream* _outputStream;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(readonly, copy, nonatomic) NSString* contentLengthHTTPHeaderValue;
@property(readonly, copy, nonatomic) NSString* contentTypeHTTPHeaderValue;
@property(retain, nonatomic) NSOutputStream* outputStream;
@property(readonly, copy, nonatomic) NSData* footerData;
@property(readonly, copy, nonatomic) NSData* headerData;
@property(copy, nonatomic) NSString* boundary;
@property(assign, nonatomic) unsigned length;
+(id)generateBoundary;
+(id)encoderWithStream:(id)stream andBoundary:(id)boundary;
+(id)contentTypeHTTPHeaderValueWithBoundary:(id)boundary;
+(void)populateRequest:(id)request withDataFromEncoder:(id)encoder;
-(void).cxx_destruct;
-(void)writeData:(id)data;
-(BOOL)writeBytes:(const void*)bytes ofLength:(unsigned)length;
-(void)addFile:(id)file fileName:(id)name mimeType:(id)type fieldName:(id)name4;
-(void)addValue:(id)value fieldName:(id)name;
-(void)addFileData:(id)data fileName:(id)name mimeType:(id)type fieldName:(id)name4;
-(void)endEncoding;
-(void)beginEncoding;
-(void)encode:(id)encode;
-(id)initWithStream:(id)stream andBoundary:(id)boundary;
@end

