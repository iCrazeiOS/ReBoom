/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "AFMultipartFormData.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class NSMutableURLRequest, AFMultipartBodyStream;

__attribute__((visibility("hidden")))
@interface AFStreamingMultipartFormData : XXUnknownSuperclass <AFMultipartFormData> {
	NSMutableURLRequest* _request;
	AFMultipartBodyStream* _bodyStream;
	unsigned _stringEncoding;
}
@property(assign, nonatomic) unsigned stringEncoding;
@property(retain, nonatomic) AFMultipartBodyStream* bodyStream;
@property(copy, nonatomic) NSMutableURLRequest* request;
-(void).cxx_destruct;
-(id)requestByFinalizingMultipartFormData;
-(void)throttleBandwidthWithPacketSize:(unsigned)packetSize delay:(double)delay;
-(void)appendPartWithHeaders:(id)headers body:(id)body;
-(void)appendPartWithFormData:(id)formData name:(id)name;
-(void)appendPartWithFileData:(id)fileData name:(id)name fileName:(id)name3 mimeType:(id)type;
-(void)appendPartWithInputStream:(id)inputStream name:(id)name fileName:(id)name3 length:(unsigned long long)length mimeType:(id)type;
-(BOOL)appendPartWithFileURL:(id)fileURL name:(id)name fileName:(id)name3 mimeType:(id)type error:(id*)error;
-(BOOL)appendPartWithFileURL:(id)fileURL name:(id)name error:(id*)error;
-(id)initWithURLRequest:(id)urlrequest stringEncoding:(unsigned)encoding;
@end

