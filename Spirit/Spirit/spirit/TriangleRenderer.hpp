//
//  TriangleRenderer.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/11/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "RenderingContext.h"
#include "math/Math.hpp"

#include "../apple/metal/Metal.hpp"

namespace spirit {

class TriangleRenderer {
public:
    
    TriangleRenderer(apple::metal::PixelFormat colorPixelFormat);
    
    inline void setViewportSize(const math::Size2& size);
    
    void render(const RenderingContext* renderingContext) const;
    
private:
    apple::metal::DeviceRef _deviceRef;
    apple::metal::CommandQueueRef _commandQueueRef;
    apple::metal::LibraryRef _libraryRef;
    apple::metal::RenderPipelineStateRef _pipelineStateRef;
    
    math::Size2 _viewportSize;
};

void TriangleRenderer::setViewportSize(const math::Size2& size) {
    _viewportSize = size;
}

}
