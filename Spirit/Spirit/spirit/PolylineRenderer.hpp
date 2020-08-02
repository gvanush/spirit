//
//  PolylineRenderer.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 8/2/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "Component.hpp"

#include "apple/metal/Metal.hpp"

#include <simd/simd.h>

namespace spirit {

class Polyline;

class RenderingContext;

class PolylineRenderer: public Component<PolylineRenderer> {
public:
    
    PolylineRenderer();
    
    inline void setPolyline(Polyline* polyline);
    
    void render(const RenderingContext* renderingContext) override;
    
private:
    apple::metal::RenderPipelineStateRef _pipelineStateRef;
    simd::float2 _viewportSize;
    Polyline* _polyline = nullptr;
};

void PolylineRenderer::setPolyline(Polyline* polyline) {
    _polyline = polyline;
}

}
