/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Boom-Structs.h"
#import <XXUnknownSuperclass.h> // Unknown library

@class NSString;

__attribute__((visibility("hidden")))
@interface CCFontDefinition : XXUnknownSuperclass {
	NSString* _fontName;
	int _fontSize;
	int _alignment;
	int _vertAlignment;
	int _lineBreakMode;
	CGSize _dimensions;
	ccColor3B _fontFillColor;
	ccFontShadow _shadow;
	ccFontStroke _stroke;
}
@property(assign, nonatomic) ccColor3B fontFillColor;
@property(assign, nonatomic) CGSize dimensions;
@property(assign, nonatomic) int lineBreakMode;
@property(assign, nonatomic) int vertAlignment;
@property(assign, nonatomic) int alignment;
@property(assign, nonatomic) int fontSize;
@property(copy, nonatomic) NSString* fontName;
-(ccColor3B)strokeColor;
-(void)setStrokeColor:(ccColor3B)color;
-(float)strokeSize;
-(void)setStrokeSize:(float)size;
-(bool)strokeEnabled;
-(void)enableStroke:(bool)stroke;
-(float)shadowBlur;
-(void)setShadowBlur:(float)blur;
-(CGSize)shadowOffset;
-(void)setShadowOffset:(CGSize)offset;
-(bool)shadowEnabled;
-(void)enableShadow:(bool)shadow;
-(void)dealloc;
-(id)initWithFontName:(id)fontName fontSize:(int)size;
-(id)init;
@end

