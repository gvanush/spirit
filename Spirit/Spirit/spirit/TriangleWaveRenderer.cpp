//
//  TriangleWaveRenderer.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/11/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "TriangleWaveRenderer.hpp"
#include "ShaderTypes.h"

namespace spirit {

void TriangleWaveRenderer::generateTriangles() {
    
    constexpr float TriangleSize = 50;
    constexpr std::array<Vertex, 3> TriangleVertices = {{
        // Pixel Positions,                          RGBA colors.
        { { -0.5*TriangleSize, -0.5*TriangleSize },  { 1., 1., 1., 1. } },
        { {  0.0*TriangleSize, +0.5*TriangleSize },  { 1., 1., 1., 1. } },
        { { +0.5*TriangleSize, -0.5*TriangleSize },  { 1., 1., 1., 1. } }
    }};
    
    constexpr std::array<math::Vec4, 6> Colors = {{
        { 1.0, 0.0, 0.0, 1.0 },  // Red
        { 0.0, 1.0, 0.0, 1.0 },  // Green
        { 0.0, 0.0, 1.0, 1.0 },  // Blue
        { 1.0, 0.0, 1.0, 1.0 },  // Magenta
        { 0.0, 1.0, 1.0, 1.0 },  // Cyan
        { 1.0, 1.0, 0.0, 1.0 },  // Yellow
    }};
    
    constexpr float HorizontalSpacing = 16.f;
    
    // Initialize each triangle.
    for(size_t t = 0; t < _triangles.size(); t++) {
        // Determine the starting position of the triangle in a horizontal line.
        _triangles[t].position.x = (-static_cast<float>(_triangles.size()) / 2.0 + t) * HorizontalSpacing;
        _triangles[t].position.y = 0.0;
        _triangles[t].color = Colors[t % Colors.size()];
    }
}

}
