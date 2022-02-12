/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCNode.h"

@class NSMutableArray, LHSprite, NSString;

__attribute__((visibility("hidden")))
@interface LHPathNode : CCNode {
	LHSprite* ccsprite;
	b2Body* body;
	NSString* uniqueName;
	NSMutableArray* pathPoints;
	float speed;
	double interval;
	bool startAtEndPoint;
	bool isCyclic;
	bool restartOtherEnd;
	int axisOrientation;
	bool flipX;
	bool flipY;
	int currentPoint;
	double elapsed;
	bool paused;
	float initialAngle;
	CGPoint prevPathPosition;
	double time;
	bool isLine;
	id pathNotifierId;
	SEL pathNotifierSel;
}
@property(assign) bool flipY;
@property(assign) bool flipX;
@property(assign) bool isLine;
@property(assign) bool paused;
@property(assign) int axisOrientation;
@property(assign) bool restartOtherEnd;
@property(assign) bool isCyclic;
+(float)rotationDegreeFromPoint:(CGPoint)point toPoint:(CGPoint)point2;
+(id)nodePathWithPoints:(id)points;
-(void).cxx_destruct;
-(void)setPathNotifierSelector:(SEL)selector;
-(void)setPathNotifierObject:(id)object;
-(bool)startAtEndPoint;
-(void)setStartAtEndPoint:(bool)endPoint;
-(float)speed;
-(void)setSpeed:(float)speed;
-(void)setBody:(b2Body*)body;
-(id)sprite;
-(void)setSprite:(id)sprite;
-(void)setUniqueName:(id)name;
-(void)visit;
-(id)initPathWithPoints:(id)points;
-(void)dealloc;
@end

