#pragma once

#include "math/Math.hpp"

namespace spirit {

enum class VertexInputIndex: unsigned int {
    Vertices     = 0,
    ViewportSize = 1,
};

struct Vertex {
    math::Vec2 position;
    math::Vec4 color;
};

}
