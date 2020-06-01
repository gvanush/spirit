//
//  TriangleWaveRenderer.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/11/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "TriangleWaveRenderer.hpp"
#include "ShaderTypes.h"
#include "RenderingContext.hpp"

namespace spirit {

namespace {

constexpr int kTriangleVertexCount = 3;

}

TriangleWaveRenderer::TriangleWaveRenderer()
: _wavePosition {0.f}
, _currentBufferIndex {0}
, _inFlightSemaphore {kMaxFramesInFlight} {
    
    using namespace apple;
    
    const auto& library = RenderingContext::library;
    
    const auto vertexFunctionRef = library.newFunction(u8"vertexShader"_str);
    assert(vertexFunctionRef);
    const auto fragmentFunctionRef = library.newFunction(u8"fragmentShader"_str);
    assert(fragmentFunctionRef);
    
    const auto pipelineStateDescriptorRef = metal::RenderPipelineDescriptor::create();
    pipelineStateDescriptorRef.setLabel(u8"Simple Pipeline"_str);
    pipelineStateDescriptorRef.setVertexFunction(vertexFunctionRef);
    pipelineStateDescriptorRef.setFragmentFunction(fragmentFunctionRef);
    pipelineStateDescriptorRef.setSampleCount(RenderingContext::kSampleCount);
    pipelineStateDescriptorRef.colorAttachments().objectAtIndex(0).setPixelFormat(RenderingContext::kColorPixelFormat);
    pipelineStateDescriptorRef.vertexBuffers().objectAtIndex(kVertexInputIndexVertices).setMutability(metal::Mutability::Immutable);
    
    const auto& device = RenderingContext::device;
    
    ErrorRef errorRef;
    _pipelineStateRef = device.newRenderPipelineState(pipelineStateDescriptorRef, &errorRef);
    assert(!errorRef);
    
    generateTriangles();
    
    constexpr NSInteger kVertexBufferSize = kTriangleCount * kTriangleVertexCount * sizeof(Vertex);
    for(auto& buffer: _vertexBuffers) {
        buffer = device.newBufferWithLength(kVertexBufferSize, metal::ResourceOptions::StorageModeShared);
    }
}

void TriangleWaveRenderer::render(const RenderingContext* renderingContext) {
    
    using namespace apple;
    
    _inFlightSemaphore.wait();
    
    _currentBufferIndex = (_currentBufferIndex + 1) % kMaxFramesInFlight;
    
    updateState();
    
    auto commandBufferRef = RenderingContext::commandQueue.newCommandBuffer();
    assert(commandBufferRef);
    commandBufferRef.setLabel(String::createWithUTF8String(u8"MyCommandBuffer"));
    
    auto commandEncoderRef = commandBufferRef.newRenderCommandEncoder(renderingContext->renderpassDescriptor());
    assert(commandEncoderRef);
    commandEncoderRef.setLabel(String::createWithUTF8String(u8"MyRenderEncoder"));
    
    _viewportSize = renderingContext->drawableSize();
    commandEncoderRef.setViewport(metal::Viewport {0.0, 0.0, _viewportSize.width, _viewportSize.height, 0.0, 1.0});
    
    commandEncoderRef.setRenderPipelineState(_pipelineStateRef);
    
    commandEncoderRef.setVertexBuffer(_vertexBuffers[_currentBufferIndex], 0, kVertexInputIndexVertices);
    
    commandEncoderRef.setVertexBytes(&_viewportSize, sizeof(_viewportSize), kVertexInputIndexViewportSize);
    
    commandEncoderRef.drawPrimitives(metal::PrimitiveType::Triangle, 0, kTriangleCount * kTriangleVertexCount);
    
    commandEncoderRef.endEncoding();
    
    commandBufferRef.present(renderingContext->drawable());
    
    commandBufferRef.addCompletedHandler([this] (metal::CommandBufferRef commandBuffer) {
        _inFlightSemaphore.notify();
    });
    
    commandBufferRef.commit();
    
}

void TriangleWaveRenderer::updateState() {
    // Simplified wave properties.
    constexpr float waveMagnitude = 128.0;  // Vertical displacement.
    constexpr float waveSpeed     = 0.05;   // Displacement change from the previous frame.

    // Increment wave position from the previous frame
    _wavePosition += waveSpeed;

    constexpr float kTriangleSize = 700;
    constexpr std::array<Vertex, kTriangleVertexCount> kTriangleVertices = {{
        // Pixel Positions,                          RGBA colors.
        { { -0.5*kTriangleSize, -0.5*kTriangleSize },  { 1., 1., 1., 1. } },
        { {  0.0*kTriangleSize, +0.5*kTriangleSize },  { 1., 1., 1., 1. } },
        { { +0.5*kTriangleSize, -0.5*kTriangleSize },  { 1., 1., 1., 1. } }
    }};

    // Vertex data for the current triangles.
    auto currentTriangleVertices = static_cast<Vertex*>(_vertexBuffers[_currentBufferIndex].contents());

    // Update each triangle.
    for(NSUInteger triangle = 0; triangle < kTriangleCount; triangle++) {
        auto trianglePosition = _triangles[triangle].position;

        // Displace the y-position of the triangle using a sine wave.
        trianglePosition.y = (sin(trianglePosition.x / waveMagnitude + _wavePosition) * waveMagnitude);

        // Update the position of the triangle.
        _triangles[triangle].position = trianglePosition;

        // Update the vertices of the current vertex buffer with the triangle's new position.
        for(NSUInteger vi = 0; vi < kTriangleVertexCount; vi++) {
            NSUInteger bufferVI = vi + (triangle * kTriangleVertexCount);
            currentTriangleVertices[bufferVI].position = kTriangleVertices[vi].position + _triangles[triangle].position;
            currentTriangleVertices[bufferVI].color = _triangles[triangle].color;
        }
    }
}

void TriangleWaveRenderer::generateTriangles() {
    
    constexpr std::array<math::Vec4, 6> Colors = {{
        { 1.0, 0.0, 0.0, 1.0 },  // Red
        { 0.0, 1.0, 0.0, 1.0 },  // Green
        { 0.0, 0.0, 1.0, 1.0 },  // Blue
        { 1.0, 0.0, 1.0, 1.0 },  // Magenta
        { 0.0, 1.0, 1.0, 1.0 },  // Cyan
        { 1.0, 1.0, 0.0, 1.0 },  // Yellow
    }};
    
    constexpr float HorizontalSpacing = 0.7f;
    
    // Initialize each triangle.
    for(size_t t = 0; t < _triangles.size(); t++) {
        // Determine the starting position of the triangle in a horizontal line.
        _triangles[t].position.x = (-static_cast<float>(_triangles.size()) / 2.0 + t) * HorizontalSpacing;
        _triangles[t].position.y = 0.0;
        _triangles[t].color = Colors[t % Colors.size()];
    }
}

}
