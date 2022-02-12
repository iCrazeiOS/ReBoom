/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "AFHTTPRequestOperation.h"

@class NSError, NSXMLParser;

__attribute__((visibility("hidden")))
@interface AFXMLRequestOperation : AFHTTPRequestOperation {
	NSXMLParser* _responseXMLParser;
	NSError* _XMLError;
}
@property(retain, nonatomic) NSError* XMLError;
@property(retain, nonatomic) NSXMLParser* responseXMLParser;
+(BOOL)canProcessRequest:(id)request;
+(id)acceptableContentTypes;
+(id)XMLParserRequestOperationWithRequest:(id)request success:(id)success failure:(id)failure;
-(void).cxx_destruct;
-(void)setCompletionBlockWithSuccess:(id)success failure:(id)failure;
-(void)cancel;
-(id)error;
@end

