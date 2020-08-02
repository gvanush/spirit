#pragma once

#include <simd/simd.h>

namespace spirit {

enum VertexInputIndex: unsigned int {
    kVertexInputIndexVertices     = 0,
    kVertexInputIndexViewportSize = 1,
};

enum FragmentInputIndex: unsigned int {
    kFragmentInputIndexColor = 0,
};

struct Vertex_P {
    simd::float2 position;
};

struct Vertex {
    simd::float2 position;
    simd::float4 color;
};

struct Vertex3d {
    simd::float3 position;
    simd::float4 color;
};

}
