//
//  PolylineRenderer.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 8/2/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "PolylineRenderer.hpp"
#include "ShaderTypes.h"
#include "RenderingContext.hpp"
#include "Polyline.hpp"

namespace spirit {

PolylineRenderer::PolylineRenderer() {
    using namespace apple;
    
    const auto& device = RenderingContext::device;
    
    const auto& library = RenderingContext::library;
    
    const auto vertexFunctionRef = library.newFunction(u8"vertexShader_P"_str);
    assert(vertexFunctionRef);
    const auto fragmentFunctionRef = library.newFunction(u8"fragmentShaderUniform"_str);
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

void PolylineRenderer::render(const RenderingContext* renderingContext) {
    
    using namespace apple;
    using namespace apple::metal;

    auto commandBufferRef = RenderingContext::commandQueue.newCommandBuffer();
    assert(commandBufferRef);
    commandBufferRef.setLabel(String::createWithUTF8String(u8"MyCommandBuffer"));
    
    auto commandEncoderRef = commandBufferRef.newRenderCommandEncoder(renderingContext->renderpassDescriptor());
    assert(commandEncoderRef);
    commandEncoderRef.setLabel(String::createWithUTF8String(u8"MyRenderEncoder"));
    
    _viewportSize = renderingContext->drawableSize();
    commandEncoderRef.setViewport(Viewport {0.0, 0.0, _viewportSize.x, _viewportSize.y, 0.0, 1.0});
    
    if(_polyline && _polyline->points().size() > 1) {
        
        commandEncoderRef.setRenderPipelineState(_pipelineStateRef);
        
        commandEncoderRef.setVertexBytes(_polyline->points().data(), _polyline->points().size() * sizeof(Polyline::PointType), kVertexInputIndexVertices);
        
        commandEncoderRef.setVertexBytes(&_viewportSize, sizeof(_viewportSize), kVertexInputIndexViewportSize);

        constexpr simd::float4 kColor = {1.f, 0.f, 0.f, 1.f};
        commandEncoderRef.setFragmentBytes(&kColor, sizeof(kColor), kFragmentInputIndexColor);
        
        commandEncoderRef.drawPrimitives(PrimitiveType::lineStrip, 0, _polyline->points().size());
    
    }
    
    commandEncoderRef.endEncoding();
    
    commandBufferRef.present(renderingContext->drawable());
    
    commandBufferRef.commit();
      
}

}
