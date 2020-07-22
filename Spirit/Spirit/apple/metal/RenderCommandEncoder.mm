//
//  RenderCommandEncoder.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "RenderCommandEncoder.h"

#include "../../util/TypeCast.hpp"

#import <Metal/Metal.h>

#include <cstring>
#include <iostream>

template <>
inline MTLPrimitiveType to(apple::metal::PrimitiveType primitiveType) {
    return MTLPrimitiveType { std::underlying_type_t<apple::metal::PrimitiveType>(primitiveType) };
}

template <>
inline MTLIndexType to(apple::metal::IndexType primitiveType) {
    return MTLIndexType { std::underlying_type_t<apple::metal::IndexType>(primitiveType) };
}

inline MTLViewport toMTLViewport(const apple::metal::Viewport& viewport) {
    return MTLViewport {viewport.originX, viewport.originY, viewport.width, viewport.height, viewport.zNear, viewport.zFar};
}

namespace apple::metal {

void RenderCommandEncoderRef::setViewport(const Viewport& viewport) {
    [obj<id<MTLRenderCommandEncoder>>() setViewport: toMTLViewport(viewport)];
}

void RenderCommandEncoderRef::setRenderPipelineState(const RenderPipelineStateRef& stateRef) {
    [obj<id<MTLRenderCommandEncoder>>() setRenderPipelineState: stateRef.obj<id<MTLRenderPipelineState>>()];
}

void RenderCommandEncoderRef::setVertexBytes(const void* bytes, NSUInteger length, NSUInteger index) {
    [obj<id<MTLRenderCommandEncoder>>() setVertexBytes: bytes length: length atIndex: index];
}

void RenderCommandEncoderRef::setVertexBuffer(const BufferRef& buffer, NSUInteger offset, NSUInteger index) {
    [obj<id<MTLRenderCommandEncoder>>() setVertexBuffer: buffer.obj<id<MTLBuffer>>() offset: offset atIndex: index];
}

void RenderCommandEncoderRef::drawPrimitives(PrimitiveType primitiveType, NSUInteger vertexStart, NSUInteger vertexCount) {
    [obj<id<MTLRenderCommandEncoder>>() drawPrimitives: to<MTLPrimitiveType>(primitiveType) vertexStart: vertexStart vertexCount: vertexCount];
}

void RenderCommandEncoderRef::drawIndexedPrimitives(PrimitiveType primitiveType, NSUInteger indexCount, IndexType indexType, const BufferRef& indexBuffer, NSUInteger indexBufferOffset) {
    [obj<id<MTLRenderCommandEncoder>>() drawIndexedPrimitives: to<MTLPrimitiveType>(primitiveType) indexCount: indexCount indexType: to<MTLIndexType>(indexType) indexBuffer: indexBuffer.obj<id<MTLBuffer>>() indexBufferOffset: indexBufferOffset];
}

}
