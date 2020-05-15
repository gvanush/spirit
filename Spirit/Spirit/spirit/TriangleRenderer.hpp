//
//  TriangleRenderer.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/11/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "math/Math.hpp"

#include "../apple/metal/Metal.hpp"

namespace spirit {

class TriangleRenderer {
public:
    
    TriangleRenderer(apple::metal::PixelFormat colorPixelFormat);
    
    inline void setRenderPassDescriptor(const apple::metal::RenderPassDescriptorRef& ref);
    inline void setDrawable(const apple::metal::DrawableRef& ref);
    
    inline void setViewportSize(const math::Size2& size);
    
    void render() const;
    
private:
    apple::metal::DeviceRef _deviceRef;
    apple::metal::CommandQueueRef _commandQueueRef;
    apple::metal::LibraryRef _libraryRef;
    apple::metal::RenderPipelineStateRef _pipelineStateRef;
    apple::metal::RenderPassDescriptorRef _renderPassDescriptorRef;
    apple::metal::DrawableRef _drawableRef;
    
    math::Size2 _viewportSize;
};

void TriangleRenderer::setRenderPassDescriptor(const apple::metal::RenderPassDescriptorRef& ref) {
    _renderPassDescriptorRef = ref;
}

void TriangleRenderer::setDrawable(const apple::metal::DrawableRef& ref) {
    _drawableRef = ref;
}

void TriangleRenderer::setViewportSize(const math::Size2& size) {
    _viewportSize = size;
}

}
