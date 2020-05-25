//
//  TriangleWaveRenderer.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/11/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "math/Math.hpp"
#include "_internal/Semaphore.hpp"

#include "../apple/metal/Metal.hpp"


#include <array>

namespace spirit {

class TriangleWaveRenderer {
public:
    
    TriangleWaveRenderer(apple::metal::PixelFormat colorPixelFormat, NSUInteger sampleCount);
    
    inline void setViewportSize(const math::Size2& size);
    inline void setDrawable(const apple::metal::DrawableRef& ref);
    inline void setRenderPassDescriptor(const apple::metal::RenderPassDescriptorRef& ref);
    
    void render();
    
private:
    void updateState();
    void generateTriangles();
    
    struct Triangle {
        math::Vec2 position;
        math::Vec4 color;
    };
    
    static constexpr int kTriangleCount = 1000;
    static constexpr size_t kMaxFramesInFlight = 1;
    
    std::array<Triangle, kTriangleCount> _triangles;
    std::array<apple::metal::BufferRef, kMaxFramesInFlight> _vertexBuffers;
    float _wavePosition;
    NSUInteger _currentBufferIndex;
    
    apple::metal::DeviceRef _deviceRef;
    apple::metal::LibraryRef _libraryRef;
    apple::metal::RenderPipelineStateRef _pipelineStateRef;
    apple::metal::CommandQueueRef _commandQueueRef;
    apple::metal::RenderPassDescriptorRef _renderPassDescriptorRef;
    apple::metal::DrawableRef _drawableRef;
    _internal::Semaphore _inFlightSemaphore;
    math::Size2 _viewportSize;
    
};

void TriangleWaveRenderer::setRenderPassDescriptor(const apple::metal::RenderPassDescriptorRef& ref) {
    _renderPassDescriptorRef = ref;
}

void TriangleWaveRenderer::setDrawable(const apple::metal::DrawableRef& ref) {
    _drawableRef = ref;
}

void TriangleWaveRenderer::setViewportSize(const math::Size2& size) {
    _viewportSize = size;
}

}
