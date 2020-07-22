//
//  DurerRenderer.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 6/30/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "DurerRenderer.hpp"
#include "ShaderTypes.h"
#include "RenderingContext.hpp"

#include <array>
#include <vector>
#include <algorithm>

namespace spirit {

namespace {

constexpr NSUInteger kCubeVertexCount = 8;
constexpr NSUInteger kCubeEdgeCount = 12;
constexpr NSUInteger kCubeEdgeIndexCount = 2 * kCubeEdgeCount;
constexpr NSUInteger kCubeFaceCount = 6;
constexpr NSUInteger kCubeFaceIndexCount = 4 * kCubeFaceCount;

}

DurerRenderer::DurerRenderer() {
    
    using namespace apple;
    
    const auto& device = RenderingContext::device;
    
    const auto& library = RenderingContext::library;
    
    const auto vertexFunctionRef = library.newFunction(u8"durerVertexShader"_str);
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
    
    constexpr simd::float4 kColor {0.f, 0.f, 0.f, 1.f};
    constexpr float kHalfSize = 10;
    constexpr simd::float3 kPos {-18.f, -13.f, 41.f};
    std::array<Vertex3d, 8> cubeVertices = {{
        {kPos + simd::float3 {-kHalfSize, -kHalfSize, -kHalfSize} , kColor},
        {kPos + simd::float3 {kHalfSize, -kHalfSize, -kHalfSize} , kColor},
        {kPos + simd::float3 {kHalfSize, kHalfSize, -kHalfSize} , kColor},
        {kPos + simd::float3 {-kHalfSize, kHalfSize, -kHalfSize} , kColor},
        {kPos + simd::float3 {-kHalfSize, -kHalfSize, kHalfSize} , kColor},
        {kPos + simd::float3 {kHalfSize, -kHalfSize, kHalfSize} , kColor},
        {kPos + simd::float3 {kHalfSize, kHalfSize, kHalfSize} , kColor},
        {kPos + simd::float3 {-kHalfSize, kHalfSize, kHalfSize} , kColor},
    }};
    
    _vertexBuffer = device.newBufferWithBytes(cubeVertices.data(), sizeof(cubeVertices), metal::ResourceOptions::storageModeShared | metal::ResourceOptions::hazardTrackingModeDefault | metal::ResourceOptions::cpuCacheModeDefaultCache);
    
    
    constexpr bool kFaceCullingEnabled = true;
    
    if(kFaceCullingEnabled) {
        constexpr std::array<uint16_t, kCubeFaceIndexCount> kCubeFaceIndices = {
            0, 3, 2, 1, // front
            4, 5, 6, 7, // back
            4, 7, 3, 0, // left
            1, 2, 6, 5, // right
            0, 1, 5, 4, // bottom
            3, 7, 6, 2, // top
        };
        
        using Edge = std::pair<uint16_t, uint16_t>;
        
        std::vector<Edge> cubeEdgeIndices;
        
        for(int i = 0; i < kCubeFaceIndices.size(); i += 4) {
            const auto& p0 = cubeVertices[kCubeFaceIndices[i]].position;
            const auto& p1 = cubeVertices[kCubeFaceIndices[i + 1]].position;
            const auto& p2 = cubeVertices[kCubeFaceIndices[i + 2]].position;
            
            auto v0 = p1 - p0;
            auto v1 = p2 - p1;
            
            auto faceNorm = simd::cross(v0, v1);
            auto eyeVec = p0; // eye is at (0, 0, 0)
            
            if(simd::dot(faceNorm, eyeVec) <= 0.f) {
                for(int j = i; j < i + 4; ++j) {
                    auto ei0 = kCubeFaceIndices[j];
                    auto ei1 = kCubeFaceIndices[i];
                    if(j < i + 3) {
                        ei1 = kCubeFaceIndices[j + 1];
                    }
                    
                    auto it = std::find_if(cubeEdgeIndices.begin(), cubeEdgeIndices.end(), [ei0, ei1] (const auto& elem) {
                        return (elem.first == ei0 && elem.second == ei1) || (elem.first == ei1 && elem.second == ei0);
                    });
                    if(it == cubeEdgeIndices.end()) {
                        cubeEdgeIndices.emplace_back(ei0, ei1);
                    }
                }
            }
            
            _indexBuffer = device.newBufferWithBytes(cubeEdgeIndices.data(), sizeof(Edge) * cubeEdgeIndices.size(), metal::ResourceOptions::storageModeShared | metal::ResourceOptions::hazardTrackingModeDefault | metal::ResourceOptions::cpuCacheModeDefaultCache);
            
        }
        
    } else {
        
        constexpr std::array<uint16_t, kCubeEdgeIndexCount> kCubeEdgeIndices = {
            0, 1,
            1, 2,
            2, 3,
            3, 0,
            
            4, 5,
            5, 6,
            6, 7,
            7, 4,
            
            0, 4,
            1, 5,
            2, 6,
            3, 7,
        };
        
        _indexBuffer = device.newBufferWithBytes(kCubeEdgeIndices.data(), sizeof(kCubeEdgeIndices), metal::ResourceOptions::storageModeShared | metal::ResourceOptions::hazardTrackingModeDefault | metal::ResourceOptions::cpuCacheModeDefaultCache);
        
    }
    
}

void DurerRenderer::render(const RenderingContext* renderingContext) {
    
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
    
    commandEncoderRef.setRenderPipelineState(_pipelineStateRef);
    
    commandEncoderRef.setVertexBuffer(_vertexBuffer, 0, kVertexInputIndexVertices);
    commandEncoderRef.setVertexBytes(&_viewportSize, sizeof(_viewportSize), kVertexInputIndexViewportSize);
    
    commandEncoderRef.drawIndexedPrimitives(PrimitiveType::line, _indexBuffer.length() / sizeof(uint16_t), IndexType::uInt16, _indexBuffer, 0);
    
//    commandEncoderRef.drawPrimitives(PrimitiveType::point, 0, kCubeVertexCount);
    
    commandEncoderRef.endEncoding();
    
    commandBufferRef.present(renderingContext->drawable());
    
    commandBufferRef.commit();
      
}

}
