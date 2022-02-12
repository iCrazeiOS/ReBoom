/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "HSIAPManagerPurchaseProtocol.h"
#import "Boom-Structs.h"
#import "HSMenuLayer.h"

@class Spinner, CCSprite, HSLabelSafeBMFont, NSString;

__attribute__((visibility("hidden")))
@interface PurchaseItem : HSMenuLayer <HSIAPManagerPurchaseProtocol> {
	CCSprite* processing;
	Spinner* spinner;
	HSLabelSafeBMFont* processingLabel;
	NSString* productId;
	BOOL hideLabel;
	id onComplete;
}
@property(copy, nonatomic) id onComplete;
@property(assign, nonatomic) BOOL hideLabel;
+(id)layerWithMenu:(id)menu product:(id)product onComplete:(id)complete;
-(void).cxx_destruct;
-(void)purchaseCallback:(BOOL)callback productIdentifier:(id)identifier;
-(BOOL)ccTouchBegan:(id)began withEvent:(id)event;
-(void)cleanup;
-(void)fakePurchaseProduct;
-(void)purchaseItem;
-(id)initWithMenu:(id)menu product:(id)product onComplete:(id)complete;
-(id)initWithMenu:(id)menu;
@end

