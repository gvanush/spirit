//
//  RenderCommandEncoder.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "RenderCommandEncoder.h"

#import <Metal/Metal.h>

#include <cstring>
#include <iostream>

namespace apple::metal {

namespace {

inline MTLViewport toMTLViewport(const Viewport& viewport) {
    MTLViewport result;
    std::memcpy(&result, &viewport, sizeof(Viewport));
    return result;
}

inline MTLPrimitiveType toMTLPrimitiveType(PrimitiveType primitiveType) {
    return MTLPrimitiveType { std::underlying_type_t<PrimitiveType>(primitiveType) };
}

}

// Check 'MTLViewport' and 'apple::metal::Viewport' are identical
static_assert(sizeof(Viewport) == sizeof(MTLViewport));
static_assert(offsetof(Viewport, originX) == offsetof(MTLViewport, originX));
static_assert(offsetof(Viewport, originY) == offsetof(MTLViewport, originY));
static_assert(offsetof(Viewport, width) == offsetof(MTLViewport, width));
static_assert(offsetof(Viewport, height) == offsetof(MTLViewport, height));
static_assert(offsetof(Viewport, zNear) == offsetof(MTLViewport, znear));
static_assert(offsetof(Viewport, zFar) == offsetof(MTLViewport, zfar));
static_assert(std::is_same<decltype(Viewport::originX), decltype(MTLViewport::originX)>::value);
static_assert(std::is_same<decltype(Viewport::originY), decltype(MTLViewport::originY)>::value);
static_assert(std::is_same<decltype(Viewport::width), decltype(MTLViewport::width)>::value);
static_assert(std::is_same<decltype(Viewport::height), decltype(MTLViewport::height)>::value);
static_assert(std::is_same<decltype(Viewport::zNear), decltype(MTLViewport::znear)>::value);
static_assert(std::is_same<decltype(Viewport::zFar), decltype(MTLViewport::zfar)>::value);

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
    [obj<id<MTLRenderCommandEncoder>>() drawPrimitives: toMTLPrimitiveType(primitiveType) vertexStart: vertexStart vertexCount: vertexCount];
}

}
