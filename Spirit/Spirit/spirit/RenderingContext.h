//
//  RenderingContext.h
//  Spirit
//
//  Created by Vanush Grigoryan on 5/25/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#ifdef __OBJC__

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

@interface SPRTRenderingContext : NSObject

@property (nonatomic, strong) id<MTLDrawable> drawable;
@property (nonatomic) CGSize drawableSize;
@property (nonatomic, strong) MTLRenderPassDescriptor* renderPassDescriptor;

-(instancetype) init;

@end

NS_ASSUME_NONNULL_END

#endif



#ifdef __cplusplus

#pragma once

#include "math/Math.hpp"

#include "../apple/metal/Metal.hpp"

namespace spirit {

class RenderingContext {
public:
    
    inline void setDrawable(const apple::metal::DrawableRef& drawable);
    inline const apple::metal::DrawableRef& drawable() const;
    
    inline void setDrawableSize(const math::Size2& ds);
    inline const math::Size2& drawableSize() const;
    
    inline void setRenderpassDescriptor(const apple::metal::RenderPassDescriptorRef& rpd);
    inline const apple::metal::RenderPassDescriptorRef& renderpassDescriptor() const;
    
private:
    apple::metal::DrawableRef _drawable;
    apple::metal::RenderPassDescriptorRef _renderPassDescriptor;
    math::Size2 _drawableSize;
};

void RenderingContext::setDrawable(const apple::metal::DrawableRef& drawable) {
    _drawable = drawable;
}

const apple::metal::DrawableRef& RenderingContext::drawable() const {
    return _drawable;
}

void RenderingContext::setDrawableSize(const math::Size2& ds) {
    _drawableSize = ds;
}

const math::Size2& RenderingContext::drawableSize() const {
    return _drawableSize;
}

void RenderingContext::setRenderpassDescriptor(const apple::metal::RenderPassDescriptorRef& rpd) {
    _renderPassDescriptor = rpd;
}

const apple::metal::RenderPassDescriptorRef& RenderingContext::renderpassDescriptor() const {
    return _renderPassDescriptor;
}

}

#endif



#if defined(__OBJC__) && defined(__cplusplus)

@interface SPRTRenderingContext (Cpp)

-(spirit::RenderingContext* _Nonnull) cpp;

@end

#endif
