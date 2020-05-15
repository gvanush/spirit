//
//  TriangleWaveRenderer.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/11/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "math/Math.hpp"

#include "../apple/metal/Metal.hpp"

#include <array>

namespace spirit {

class TriangleWaveRenderer {
public:
    
private:
    void generateTriangles();
    
    struct Triangle {
        math::Vec2 position;
        math::Vec4 color;
    };
    
    static constexpr int TriangleCount = 50;
    static constexpr size_t MaxFramesInFlight = 3;
    
    std::array<Triangle, TriangleCount> _triangles;
    std::array<apple::metal::BufferRef, MaxFramesInFlight> _vertexBuffers;
};

}
