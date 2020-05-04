//
//  Scene.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Scene.hpp"

#include "ShaderTypes.h"

namespace spirit {

Scene::Scene(apple::metal::PixelFormat colorPixelFormat) {
    using namespace apple;
    
    _deviceRef = metal::createSystemDefaultDevice();
    _libraryRef = _deviceRef.newDefaultLibrary();
    assert(_libraryRef);
    
    const auto vertexFunctionRef = _libraryRef.makeFunction(String::createWithUTF8String(u8"vertexShader"));
    const auto fragmentFunctionRef = _libraryRef.makeFunction(String::createWithUTF8String(u8"fragmentShader"));
    
    const auto pipelineStateDescriptorRef = metal::RenderPipelineDescriptor::create();
    pipelineStateDescriptorRef.setLabel(String::createWithUTF8String(u8"Simple Pipeline"));
    pipelineStateDescriptorRef.setVertexFunction(vertexFunctionRef);
    pipelineStateDescriptorRef.setFragmentFunction(fragmentFunctionRef);
    pipelineStateDescriptorRef.colorAttachments().objectAtIndex(0).setPixelFormat(colorPixelFormat);
    
    ErrorRef errorRef;
    _pipelineStateRef = _deviceRef.newRenderPipelineStateWithDescriptor(pipelineStateDescriptorRef, &errorRef);
    assert(!errorRef);
    
    _commandQueueRef = _deviceRef.newCommandQueue();
}

void Scene::render() const {
    
    assert(_drawableRef);
    assert(_renderPassDescriptorRef);
    
    using namespace apple;
    using namespace apple::metal;

    auto commandBufferRef = _commandQueueRef.newCommandBuffer();
    assert(commandBufferRef);
    commandBufferRef.setLabel(String::createWithUTF8String(u8"MyLabel"));
    
    auto commandEncoderRef = commandBufferRef.newRenderCommandEncoder(_renderPassDescriptorRef);
    assert(commandEncoderRef);
    commandEncoderRef.setLabel(String::createWithUTF8String(u8"MyRenderEncoder"));
    
    commandEncoderRef.setViewport(Viewport {0.0, 0.0, _viewportSize.width, _viewportSize.height, 0.0, 1.0});
    
    commandEncoderRef.setRenderPipelineState(_pipelineStateRef);
    
    constexpr float size = 200;
    constexpr Vertex triangleVertices[] = {
        { {  size,  -size }, { 1, 0, 0, 1 } },
        { { -size,  -size }, { 0, 1, 0, 1 } },
        { {    0,   size }, { 0, 0, 1, 1 } },
    };
    
    commandEncoderRef.setVertexBytes(triangleVertices, sizeof(triangleVertices), static_cast<NSUInteger>(VertexInputIndex::Vertices));
    
    commandEncoderRef.setVertexBytes(&_viewportSize, sizeof(_viewportSize), static_cast<NSUInteger>(VertexInputIndex::ViewportSize));

    commandEncoderRef.drawPrimitives(PrimitiveType::Triangle, 0, 3);
    
    commandEncoderRef.endEncoding();
    
    commandBufferRef.present(_drawableRef);
    
    commandBufferRef.commit();
      
}

}
