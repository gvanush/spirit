#pragma once

#include "math/Math.hpp"

namespace spirit {

enum VertexInputIndex: unsigned int {
    kVertexInputIndexVertices     = 0,
    kVertexInputIndexViewportSize = 1,
};

struct Vertex {
    math::Vec2 position;
    math::Vec4 color;
};

}
