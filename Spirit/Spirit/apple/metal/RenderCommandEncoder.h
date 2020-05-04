//
//  RenderCommandEncoder.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "CommandEncoder.h"
#include "RenderPipelineState.h"

#include <objc/NSObjCRuntime.h>

namespace apple::metal {

enum class PrimitiveType: NSUInteger {
    Point = 0,
    Line = 1,
    LineStrip = 2,
    Triangle = 3,
    TriangleStrip = 4,
} API_AVAILABLE(macos(10.11), ios(8.0));

struct Viewport {
    double originX, originY, width, height, zNear, zFar;
};

class RenderCommandEncoderRef: public CommandEncoderRef {
public:
    
    using CommandEncoderRef::CommandEncoderRef;
    
    void setViewport(const Viewport& viewport);
    
    void setRenderPipelineState(const RenderPipelineStateRef& stateRef);
    
    void setVertexBytes(const void* bytes, NSUInteger length, NSUInteger index);
    
    void drawPrimitives(PrimitiveType primitiveType, NSUInteger vertexStart, NSUInteger vertexCount);
    
    
};

}
