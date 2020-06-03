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
#include "Buffer.h"

#include <objc/NSObjCRuntime.h>

namespace apple::metal {

enum class PrimitiveType: NSUInteger {
    point = 0,
    line = 1,
    lineStrip = 2,
    triangle = 3,
    triangleStrip = 4,
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
    
    void setVertexBuffer(const BufferRef& buffer, NSUInteger offset, NSUInteger index);
    
    void drawPrimitives(PrimitiveType primitiveType, NSUInteger vertexStart, NSUInteger vertexCount);
    
    
};

}
