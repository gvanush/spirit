//
//  RenderingContext.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 5/25/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#import "RenderingContext.h"

#include <memory>

@interface SPRTRenderingContext () {
    std::unique_ptr<spirit::RenderingContext> _cpp;
}

@end

@implementation SPRTRenderingContext

-(void) setDrawable: (id<MTLDrawable>) drawable {
    _cpp->setDrawable(apple::metal::DrawableRef {drawable});
}

-(id<MTLDrawable>) drawable {
    return _cpp->drawable().obj<id>();
}

-(void) setDrawableSize: (CGSize) drawableSize {
    _cpp->setDrawableSize(spirit::math::Size2 {static_cast<float>(drawableSize.width), static_cast<float>(drawableSize.height)});
}

-(CGSize) drawableSize {
    return CGSizeMake(_cpp->drawableSize().width, _cpp->drawableSize().height);
}

-(void) setRenderPassDescriptor: (MTLRenderPassDescriptor*) renderPassDescriptor {
    _cpp->setRenderpassDescriptor(apple::metal::RenderPassDescriptorRef {renderPassDescriptor});
}

-(MTLRenderPassDescriptor*) renderPassDescriptor {
    return _cpp->renderpassDescriptor().obj<id>();
}

-(instancetype) init {
    if(self = [super init]) {
        _cpp = std::make_unique<spirit::RenderingContext>();
    }
    return self;
}

+(id<MTLDevice>) device {
    return spirit::RenderingContext::device.obj<id>();
}

+(MTLPixelFormat) colorPixelFormat {
    return apple::metal::to<MTLPixelFormat>(spirit::RenderingContext::kColorPixelFormat);
}

+(NSUInteger) sampleCount {
    return spirit::RenderingContext::kSampleCount;
}

@end

@implementation SPRTRenderingContext (Cpp)

-(spirit::RenderingContext* _Nonnull) cpp {
    return _cpp.get();
}

@end
