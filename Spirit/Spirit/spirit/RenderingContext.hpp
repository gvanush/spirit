//
//  RenderingContext.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 6/1/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "apple/metal/Metal.hpp"

#include <simd/simd.h>

namespace spirit {

class RenderingContext {
public:
    
    static inline auto device = apple::metal::createSystemDefaultDevice();
    static inline auto library = device.newDefaultLibrary();
    static inline auto commandQueue = device.newCommandQueue();
    static constexpr inline auto kColorPixelFormat = apple::metal::PixelFormat::bgra8Unorm;
    static constexpr inline NSUInteger kSampleCount = 1;
    
    inline void setDrawable(const apple::metal::DrawableRef& drawable);
    inline const apple::metal::DrawableRef& drawable() const;
    
    inline void setDrawableSize(const simd::float2& ds);
    inline const simd::float2& drawableSize() const;
    
    inline void setRenderpassDescriptor(const apple::metal::RenderPassDescriptorRef& rpd);
    inline const apple::metal::RenderPassDescriptorRef& renderpassDescriptor() const;
    
private:
    apple::metal::DrawableRef _drawable;
    apple::metal::RenderPassDescriptorRef _renderPassDescriptor;
    simd::float2 _drawableSize;
};

void RenderingContext::setDrawable(const apple::metal::DrawableRef& drawable) {
    _drawable = drawable;
}

const apple::metal::DrawableRef& RenderingContext::drawable() const {
    return _drawable;
}

void RenderingContext::setDrawableSize(const simd::float2& ds) {
    _drawableSize = ds;
}

const simd::float2& RenderingContext::drawableSize() const {
    return _drawableSize;
}

void RenderingContext::setRenderpassDescriptor(const apple::metal::RenderPassDescriptorRef& rpd) {
    _renderPassDescriptor = rpd;
}

const apple::metal::RenderPassDescriptorRef& RenderingContext::renderpassDescriptor() const {
    return _renderPassDescriptor;
}

}
