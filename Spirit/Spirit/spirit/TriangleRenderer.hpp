//
//  TriangleRenderer.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/11/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "Renderer.hpp"
#include "math/Math.hpp"

#include "../apple/metal/Metal.hpp"

namespace spirit {

class RenderingContext;

class TriangleRenderer: public Renderer {
public:
    
    TriangleRenderer();
    
    void render(const RenderingContext* renderingContext) override;
    
private:
    apple::metal::RenderPipelineStateRef _pipelineStateRef;
    math::Size2 _viewportSize;
};

}
