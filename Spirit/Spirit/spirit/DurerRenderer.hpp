//
//  DurerRenderer.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 6/30/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "Component.hpp"

#include "apple/metal/Metal.hpp"

#include <simd/simd.h>

namespace spirit {

class RenderingContext;

class DurerRenderer: public Component<DurerRenderer> {
public:
    
    DurerRenderer();
    
    void render(const RenderingContext* renderingContext) override;
    
private:
    apple::metal::RenderPipelineStateRef _pipelineStateRef;
    apple::metal::BufferRef _vertexBuffer;
    apple::metal::BufferRef _indexBuffer;
    simd::float2 _viewportSize;
    
};

}
