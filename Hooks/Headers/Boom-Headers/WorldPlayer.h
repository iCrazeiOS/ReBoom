/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library
#import "ProfileDataSource.h"

@class NSDictionary, NSString;

__attribute__((visibility("hidden")))
@interface WorldPlayer : XXUnknownSuperclass <ProfileDataSource> {
	NSDictionary* playerDict;
	NSDictionary* data;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(retain, nonatomic) NSDictionary* data;
-(void).cxx_destruct;
-(id)profile;
-(id)worldRank;
-(id)maxGroupIdUnlocked;
-(float)totalDistance;
-(unsigned)totalEarnedSuperStars;
-(unsigned)totalEarnedMedals;
-(id)tournamentStats;
-(id)challengeStats;
-(id)uuid;
-(id)countryCode;
-(id)nickname;
-(id)wheelStyle;
-(id)engineStyle;
-(id)heroStyle;
-(void)dealloc;
-(id)initWithDictionary:(id)dictionary;
@end
