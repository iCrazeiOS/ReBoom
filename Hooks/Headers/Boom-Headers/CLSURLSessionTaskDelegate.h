/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "NSObject.h"


@protocol CLSURLSessionTaskDelegate <NSObject>
-(void)task:(id)task didCompleteWithError:(id)error;
-(id)task:(id)task willPerformHTTPRedirection:(id)redirection newRequest:(id)request;
@end

