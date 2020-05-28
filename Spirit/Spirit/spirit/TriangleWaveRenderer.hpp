//
//  TriangleWaveRenderer.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/11/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "Component.hpp"
#include "math/Math.hpp"
#include "_internal/Semaphore.hpp"

#include "../apple/metal/Metal.hpp"


#include <array>

namespace spirit {

class RenderingContext;

class TriangleWaveRenderer: public Component<TriangleWaveRenderer> {
public:
    
    TriangleWaveRenderer();
    
    void render(const RenderingContext* renderingContext) override;
    
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
    
    apple::metal::RenderPipelineStateRef _pipelineStateRef;
    _internal::Semaphore _inFlightSemaphore;
    math::Size2 _viewportSize;
    
};

}
