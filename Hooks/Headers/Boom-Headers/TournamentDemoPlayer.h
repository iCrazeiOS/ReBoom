/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class NSNumber, NSString;

__attribute__((visibility("hidden")))
@interface TournamentDemoPlayer : XXUnknownSuperclass {
	NSString* nickname;
	NSString* heroStyle;
	NSString* engineStyle;
	NSString* wheelStyle;
	NSNumber* currentTime;
	NSNumber* ghost_version;
	NSNumber* uuid;
	NSString* countryCode;
	NSNumber* _isSelf;
}
@property(retain, nonatomic) NSNumber* isSelf;
@property(retain, nonatomic) NSString* countryCode;
@property(retain, nonatomic) NSNumber* uuid;
@property(retain, nonatomic) NSNumber* ghost_version;
@property(retain, nonatomic) NSNumber* currentTime;
@property(retain, nonatomic) NSString* wheelStyle;
@property(retain, nonatomic) NSString* engineStyle;
@property(retain, nonatomic) NSString* heroStyle;
@property(retain, nonatomic) NSString* nickname;
+(id)player3;
+(id)player2;
+(id)player1;
-(void).cxx_destruct;
-(id)nicknameWithMaxLength:(unsigned)maxLength;
@end

