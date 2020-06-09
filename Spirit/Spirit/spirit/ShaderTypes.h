#pragma once

#include <simd/simd.h>

namespace spirit {

enum VertexInputIndex: unsigned int {
    kVertexInputIndexVertices     = 0,
    kVertexInputIndexViewportSize = 1,
};

struct Vertex {
    simd::float2 position;
    simd::float4 color;
};

}
