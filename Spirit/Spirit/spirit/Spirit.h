//
//  Spirit.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#import "RenderingContext.h"

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

@interface Spirit : NSObject

-(instancetype _Nonnull ) initWithColorPixelFormat: (MTLPixelFormat) colorPixelFormat sampleCount: (NSUInteger) sampleCount;

-(void) onDrawableSizeChange: (CGSize) drawableSize;
-(void) onDraw: (SPRTRenderingContext*) renderingContext;

@end

NS_ASSUME_NONNULL_END
