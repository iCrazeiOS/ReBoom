/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCLayer.h"

@class NSMutableArray, NSArray, UITouch, NSObject;
@protocol CCScrollLayerDelegate;

__attribute__((visibility("hidden")))
@interface CCScrollLayer : CCLayer {
	NSObject<CCScrollLayerDelegate>* delegate_;
	int currentScreen_;
	int prevScreen_;
	float startSwipe_;
	float minimumTouchLengthToSlide_;
	float minimumTouchLengthToChangePage_;
	BOOL showPagesIndicator_;
	CGPoint pagesIndicatorPosition_;
	ccColor4B pagesIndicatorSelectedColor_;
	ccColor4B pagesIndicatorNormalColor_;
	int state_;
	BOOL stealTouches_;
	UITouch* scrollTouch_;
	NSMutableArray* layers_;
	float pagesWidthOffset_;
	float marginOffset_;
}
@property(readonly, assign) NSArray* pages;
@property(assign) float pagesWidthOffset;
@property(readonly, assign) int currentScreen;
@property(readonly, assign) int totalScreens;
@property(assign) ccColor4B pagesIndicatorNormalColor;
@property(assign) ccColor4B pagesIndicatorSelectedColor;
@property(assign) CGPoint pagesIndicatorPosition;
@property(assign) BOOL showPagesIndicator;
@property(assign) BOOL stealTouches;
@property(assign) float marginOffset;
@property(assign) float minimumTouchLengthToChangePage;
@property(assign) float minimumTouchLengthToSlide;
@property(assign) NSObject<CCScrollLayerDelegate>* delegate;
+(id)nodeWithLayers:(id)layers widthOffset:(int)offset;
-(void)ccTouchEnded:(id)ended withEvent:(id)event;
-(void)ccTouchMoved:(id)moved withEvent:(id)event;
-(BOOL)ccTouchBegan:(id)began withEvent:(id)event;
-(void)ccTouchCancelled:(id)cancelled withEvent:(id)event;
-(void)claimTouch:(id)touch;
-(void)registerWithTouchDispatcher;
-(void)removePageWithNumber:(int)number;
-(void)removePage:(id)page;
-(void)addPage:(id)page withNumber:(int)number;
-(void)addPage:(id)page;
-(void)selectPage:(int)page;
-(void)moveToPage:(int)page;
-(CGPoint)positionForPageWithNumber:(int)number;
-(int)pageNumberForPosition:(CGPoint)position;
-(void)moveToPageEnded;
-(void)visit;
-(void)updatePages;
-(void)dealloc;
-(id)initWithLayers:(id)layers widthOffset:(int)offset;
@end

