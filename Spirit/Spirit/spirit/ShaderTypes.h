#pragma once

#include "Math.hpp"

namespace spirit {

enum VertexInputIndex: unsigned int {
    kVertexInputIndexVertices     = 0,
    kVertexInputIndexViewportSize = 1,
};

struct Vertex {
    Vec2 position;
    Vec4 color;
};

}
