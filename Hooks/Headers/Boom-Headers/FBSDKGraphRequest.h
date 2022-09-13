/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class NSMutableDictionary, NSString;

@interface FBSDKGraphRequest : XXUnknownSuperclass {
	NSMutableDictionary* _parameters;
	NSString* _tokenString;
	NSString* _graphPath;
	NSString* _HTTPMethod;
	NSString* _version;
	unsigned _flags;
}
@property(assign, nonatomic) unsigned flags;
@property(readonly, copy, nonatomic) NSString* version;
@property(readonly, copy, nonatomic) NSString* HTTPMethod;
@property(readonly, copy, nonatomic) NSString* graphPath;
@property(readonly, copy, nonatomic) NSString* tokenString;
@property(readonly, assign, nonatomic) NSMutableDictionary* parameters;
+(id)preprocessParams:(id)params;
+(id)serializeURL:(id)url params:(id)params httpMethod:(id)method;
+(id)serializeURL:(id)url params:(id)params;
+(BOOL)isAttachment:(id)attachment;
-(void).cxx_destruct;
-(id)description;
-(id)startWithCompletionHandler:(id)completionHandler;
-(BOOL)hasAttachments;
-(void)setGraphErrorRecoveryDisabled:(BOOL)disabled;
-(BOOL)isGraphErrorRecoveryDisabled;
-(id)initWithGraphPath:(id)graphPath parameters:(id)parameters tokenString:(id)string version:(id)version HTTPMethod:(id)method;
-(id)initWithGraphPath:(id)graphPath parameters:(id)parameters tokenString:(id)string HTTPMethod:(id)method flags:(unsigned)flags;
-(id)initWithGraphPath:(id)graphPath parameters:(id)parameters flags:(unsigned)flags;
-(id)initWithGraphPath:(id)graphPath parameters:(id)parameters HTTPMethod:(id)method;
-(id)initWithGraphPath:(id)graphPath parameters:(id)parameters;
-(id)init;
@end
