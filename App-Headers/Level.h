/*
* This header is generated by classdump-dyld 1.0
* on Thursday, January 11, 2018 at 9:32:04 AM Central European Standard Time
* Operating System: Version 10.3.3 (Build 14G60)
* Image Source: /private/var/mobile/Documents/Dumped/Boom!
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import "CoreData/NSManagedObject.h"

@class NSNumber, NSString, NSSet;

@interface Level : NSManagedObject

@property (nonatomic,retain) NSNumber * completed; 
@property (nonatomic,retain) id consumed; 
@property (nonatomic,retain) NSString * levelId; 
@property (nonatomic,retain) NSNumber * locked; 
@property (nonatomic,retain) NSNumber * medalBits; 
@property (nonatomic,retain) NSString * version; 
@property (nonatomic,retain) id friendsStatus; 
@property (nonatomic,retain) NSNumber * statusSynced; 
@property (nonatomic,retain) NSSet * timings; 
@property (nonatomic,retain) NSSet * tournament; 
@property (nonatomic,retain) NSString * name; 
@property (nonatomic,retain) NSString * url; 
@property (nonatomic,retain) NSString * themeName; 
@property (nonatomic,retain) NSString * target; 
+(void)sendStatus;
+(id)levelStateById:(id)arg1 version:(id)arg2 ;
+(id)newLevelStateById:(id)arg1 version:(id)arg2 ;
+(id)allPlayedNormalLevels;
+(void)sendStatus:(id)arg1 ;
+(id)levelStatesById:(id)arg1 ;
+(id)levelStatesByIdAndVersion:(id)arg1 ;
+(id)newLevelStateById:(id)arg1 version:(id)arg2 url:(id)arg3 name:(id)arg4 themeName:(id)arg5 target:(id)arg6 ;
+(id)unLockedLevels;
+(id)levelsWithConsumedPileCoins;
+(id)mergeGameState:(id)arg1 ;
-(void)sendStatus;
-(void)fetchFriendsStatus:(/*^block*/id)arg1 ;
-(id)saveBestRun:(id)arg1 error:(id*)arg2 ;
-(id)levelData;
-(id)ghostFilePath;
-(id)goalCheckpoint;
-(id)ghostData;
-(id)levelName;
-(id)groupData;
-(unsigned)completedMedals;
-(char)completedSuperStar;
-(char)isDownloaded;
-(void)willSave;
-(void)awakeFromFetch;
-(char)isOnline;
-(id)serialize;
@end

