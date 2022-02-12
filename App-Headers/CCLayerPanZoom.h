/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCLayer.h"

@class CCScheduler, NSMutableArray;
@protocol CCLayerPanZoomClickDelegate;

__attribute__((visibility("hidden")))
@interface CCLayerPanZoom : CCLayer {
	float _maxScale;
	float _minScale;
	NSMutableArray* _touches;
	CGRect _panBoundsRect;
	float _touchDistance;
	float _maxTouchDistanceToClick;
	id<CCLayerPanZoomClickDelegate> _delegate;
	int _mode;
	float _minSpeed;
	float _maxSpeed;
	float _topFrameMargin;
	float _bottomFrameMargin;
	float _leftFrameMargin;
	float _rightFrameMargin;
	CGPoint _prevSingleTouchPositionInLayer;
	double _singleTouchTimestamp;
	BOOL _touchMoveBegan;
	float _rubberEffectRecoveryTime;
	float _rubberEffectRatio;
	BOOL _rubberEffectRecovering;
	BOOL _rubberEffectZooming;
	CCScheduler* _scheduler;
}
@property(assign) float rubberEffectRatio;
@property(assign) float rubberEffectRecoveryTime;
@property(assign) float rightFrameMargin;
@property(assign) float leftFrameMargin;
@property(assign) float bottomFrameMargin;
@property(assign) float topFrameMargin;
@property(assign) float minSpeed;
@property(assign) float maxSpeed;
@property(assign) int mode;
@property(assign) id<CCLayerPanZoomClickDelegate> delegate;
@property(assign) float maxTouchDistanceToClick;
@property(assign) CGRect panBoundsRect;
@property(assign) float minScale;
@property(assign) float maxScale;
@property(retain) CCScheduler* scheduler;
@property(assign) float touchDistance;
@property(retain) NSMutableArray* touches;
-(void)dealloc;
-(float)vertSpeedWithPosition:(CGPoint)position;
-(float)horSpeedWithPosition:(CGPoint)position;
-(int)frameEdgeWithPoint:(CGPoint)point;
-(float)minPossibleScale;
-(float)rightEdgeDistance;
-(float)bottomEdgeDistance;
-(float)leftEdgeDistance;
-(float)topEdgeDistance;
-(void)recoverEnded;
-(void)recoverPositionAndScale;
-(void)setScale:(float)scale;
-(void)setPosition:(CGPoint)position;
-(void)onExit;
-(void)onEnter;
-(void)update:(float)update;
-(void)ccTouchesCancelled:(id)cancelled withEvent:(id)event;
-(void)ccTouchesEnded:(id)ended withEvent:(id)event;
-(void)ccTouchesMoved:(id)moved withEvent:(id)event;
-(void)ccTouchesBegan:(id)began withEvent:(id)event;
-(id)init;
@end

