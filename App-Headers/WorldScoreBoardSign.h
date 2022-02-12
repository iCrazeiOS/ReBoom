/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "HSMenuItem.h"

@class WorldPlayer, CCSprite, Wheely, HSLabelSafeBMFont;

__attribute__((visibility("hidden")))
@interface WorldScoreBoardSign : HSMenuItem {
	HSLabelSafeBMFont* nickLabel;
	HSLabelSafeBMFont* rankLabel;
	CCNode* flag;
	Wheely* character;
	CCSprite* brightenOverlay;
	CCSprite* photoFrame;
	CCSprite* photo;
	WorldPlayer* player_;
}
@property(retain, nonatomic) WorldPlayer* player;
+(id)signWithPlayer:(id)player sprite:(id)sprite block:(id)block;
+(id)slowerSignWithPlayer:(id)player block:(id)block;
+(id)selfSignWithPlayer:(id)player block:(id)block;
+(id)fasterSignWithPlayer:(id)player block:(id)block;
-(void).cxx_destruct;
-(void)blur;
-(void)focus;
-(void)dealloc;
-(void)cleanup;
-(void)setupPhoto:(id)photo;
-(void)unselected;
-(void)selected;
-(void)setupSign:(id)sign sprite:(id)sprite;
@end

