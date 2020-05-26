//
//  TriangleRenderer.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/11/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "TriangleRenderer.hpp"
#include "ShaderTypes.h"
#include "RenderingContext.h"

namespace spirit {

TriangleRenderer::TriangleRenderer() {
    using namespace apple;
    
    const auto& device = RenderingContext::device;
    
    const auto& library = RenderingContext::library;
    
    const auto vertexFunctionRef = library.newFunction(u8"vertexShader"_str);
    assert(vertexFunctionRef);
    const auto fragmentFunctionRef = library.newFunction(u8"fragmentShader"_str);
    assert(fragmentFunctionRef);
    
    const auto pipelineStateDescriptorRef = metal::RenderPipelineDescriptor::create();
    pipelineStateDescriptorRef.setLabel(u8"Simple Pipeline"_str);
    pipelineStateDescriptorRef.setVertexFunction(vertexFunctionRef);
    pipelineStateDescriptorRef.setFragmentFunction(fragmentFunctionRef);
    pipelineStateDescriptorRef.colorAttachments().objectAtIndex(0).setPixelFormat(RenderingContext::kColorPixelFormat);
    
    ErrorRef errorRef;
    _pipelineStateRef = device.newRenderPipelineState(pipelineStateDescriptorRef, &errorRef);
    assert(!errorRef);
    
}

void TriangleRenderer::render(const RenderingContext* renderingContext) {
    
    using namespace apple;
    using namespace apple::metal;

    auto commandBufferRef = RenderingContext::commandQueue.newCommandBuffer();
    assert(commandBufferRef);
    commandBufferRef.setLabel(String::createWithUTF8String(u8"MyCommandBuffer"));
    
    auto commandEncoderRef = commandBufferRef.newRenderCommandEncoder(renderingContext->renderpassDescriptor());
    assert(commandEncoderRef);
    commandEncoderRef.setLabel(String::createWithUTF8String(u8"MyRenderEncoder"));
    
    _viewportSize = renderingContext->drawableSize();
    commandEncoderRef.setViewport(Viewport {0.0, 0.0, _viewportSize.width, _viewportSize.height, 0.0, 1.0});
    
    commandEncoderRef.setRenderPipelineState(_pipelineStateRef);
    
    constexpr float size = 200;
    constexpr Vertex triangleVertices[] = {
        { {  size,  -size }, { 1, 0, 0, 1 } },
        { { -size,  -size }, { 0, 1, 0, 1 } },
        { {    0,   size }, { 0, 0, 1, 1 } },
    };
    
    commandEncoderRef.setVertexBytes(triangleVertices, sizeof(triangleVertices), kVertexInputIndexVertices);
    
    commandEncoderRef.setVertexBytes(&_viewportSize, sizeof(_viewportSize), kVertexInputIndexViewportSize);

    commandEncoderRef.drawPrimitives(PrimitiveType::Triangle, 0, 3);
    
    commandEncoderRef.endEncoding();
    
    commandBufferRef.present(renderingContext->drawable());
    
    commandBufferRef.commit();
      
}

}
