/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import "CCNode.h"
#import "CCTextureProtocol.h"

@class CCParticleBatchNode, NSString, CCTexture2D;

__attribute__((visibility("hidden")))
@interface CCParticleSystem : CCNode <CCTextureProtocol> {
	BOOL active;
	float duration;
	float elapsed;
	CGPoint sourcePosition;
	CGPoint posVar;
	float angle;
	float angleVar;
	int emitterMode_;
	union {
		struct {
			CGPoint gravity;
			float speed;
			float speedVar;
			float tangentialAccel;
			float tangentialAccelVar;
			float radialAccel;
			float radialAccelVar;
		} A;
		CGAffineTransform B;
	} mode;
	float startSize;
	float startSizeVar;
	float endSize;
	float endSizeVar;
	float life;
	float lifeVar;
	ccColor4F startColor;
	ccColor4F startColorVar;
	ccColor4F endColor;
	ccColor4F endColorVar;
	float startSpin;
	float startSpinVar;
	float endSpin;
	float endSpinVar;
	sCCParticle* particles;
	unsigned totalParticles;
	unsigned particleCount;
	unsigned allocatedParticles;
	float emissionRate;
	float emitCounter;
	CCTexture2D* texture_;
	ccBlendFunc blendFunc_;
	BOOL opacityModifyRGB_;
	int positionType_;
	BOOL autoRemoveOnFinish_;
	unsigned particleIdx;
	/*function-pointer*/ void* updateParticleImp;
	SEL updateParticleSel;
	CCParticleBatchNode* batchNode_;
	unsigned atlasIndex_;
	BOOL transformSystemDirty_;
}
@property(readonly, copy) NSString* debugDescription;
@property(readonly, copy) NSString* description;
@property(readonly, assign) Class superclass;
@property(readonly, assign) unsigned hash;
@property(assign, nonatomic) unsigned atlasIndex;
@property(assign, nonatomic) CCParticleBatchNode* batchNode;
@property(assign, nonatomic) int emitterMode;
@property(assign, nonatomic) BOOL autoRemoveOnFinish;
@property(assign, nonatomic) int positionType;
@property(assign, nonatomic) BOOL blendAdditive;
@property(assign, nonatomic, getter=doesOpacityModifyRGB) BOOL opacityModifyRGB;
@property(assign, nonatomic) ccBlendFunc blendFunc;
@property(retain, nonatomic) CCTexture2D* texture;
@property(assign, nonatomic) unsigned totalParticles;
@property(assign, nonatomic) float emissionRate;
@property(assign, nonatomic) float endSpinVar;
@property(assign, nonatomic) float endSpin;
@property(assign, nonatomic) float startSpinVar;
@property(assign, nonatomic) float startSpin;
@property(assign, nonatomic) ccColor4F endColorVar;
@property(assign, nonatomic) ccColor4F endColor;
@property(assign, nonatomic) ccColor4F startColorVar;
@property(assign, nonatomic) ccColor4F startColor;
@property(assign, nonatomic) float endSizeVar;
@property(assign, nonatomic) float endSize;
@property(assign, nonatomic) float startSizeVar;
@property(assign, nonatomic) float startSize;
@property(assign, nonatomic) float rotatePerSecondVar;
@property(assign, nonatomic) float rotatePerSecond;
@property(assign, nonatomic) float endRadiusVar;
@property(assign, nonatomic) float endRadius;
@property(assign, nonatomic) float startRadiusVar;
@property(assign, nonatomic) float startRadius;
@property(assign, nonatomic) float radialAccelVar;
@property(assign, nonatomic) float radialAccel;
@property(assign, nonatomic) float tangentialAccelVar;
@property(assign, nonatomic) float tangentialAccel;
@property(assign, nonatomic) float speedVar;
@property(assign, nonatomic) float speed;
@property(assign, nonatomic) CGPoint gravity;
@property(assign, nonatomic) float angleVar;
@property(assign, nonatomic) float angle;
@property(assign, nonatomic) float lifeVar;
@property(assign, nonatomic) float life;
@property(assign, nonatomic) CGPoint posVar;
@property(assign, nonatomic) CGPoint sourcePosition;
@property(assign, nonatomic) float duration;
@property(readonly, assign, nonatomic) unsigned particleCount;
@property(readonly, assign, nonatomic) BOOL active;
+(id)particleWithFile:(id)file;
-(void)updateBlendFunc;
-(void)setScaleY:(float)y;
-(void)setScaleX:(float)x;
-(void)setRotation:(float)rotation;
-(void)setScale:(float)scale;
-(void)postStep;
-(void)updateQuadWithParticle:(sCCParticle*)particle newPosition:(CGPoint)position;
-(void)updateWithNoTime;
-(void)update:(float)update;
-(BOOL)isFull;
-(void)resetSystem;
-(void)stopSystem;
-(BOOL)addParticle;
-(void)initParticle:(sCCParticle*)particle;
-(void)dealloc;
-(id)initWithTotalParticles:(unsigned)totalParticles;
-(id)initWithDictionary:(id)dictionary;
-(id)initWithFile:(id)file;
-(id)init;
@end
