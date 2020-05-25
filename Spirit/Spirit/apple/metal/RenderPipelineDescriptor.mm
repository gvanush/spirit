//
//  RenderPipelineDescriptor.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/30/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "RenderPipelineDescriptor.h"

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

namespace apple::metal {

void RenderPipelineDescriptorRef::setLabel(const StringRef& labelRef) const {
    obj<MTLRenderPipelineDescriptor*>().label = labelRef.obj<NSString*>();
}

StringRef RenderPipelineDescriptorRef::label() const {
    return StringRef { obj<MTLRenderPipelineDescriptor*>().label };
}

void RenderPipelineDescriptorRef::setVertexFunction(const FunctionRef& vertexFunctionRef) const {
    obj<MTLRenderPipelineDescriptor*>().vertexFunction = vertexFunctionRef.obj<id<MTLFunction>>();
}

FunctionRef RenderPipelineDescriptorRef::vertexFunction() const {
    return FunctionRef { obj<MTLRenderPipelineDescriptor*>().vertexFunction };
}

void RenderPipelineDescriptorRef::setFragmentFunction(const FunctionRef& fragmentFunctionRef) const {
    obj<MTLRenderPipelineDescriptor*>().fragmentFunction = fragmentFunctionRef.obj<id<MTLFunction>>();
}

FunctionRef RenderPipelineDescriptorRef::fragmentFunction() const {
    return FunctionRef { obj<MTLRenderPipelineDescriptor*>().fragmentFunction };
}

RenderPipelineColorAttachmentDescriptorArrayRef RenderPipelineDescriptorRef::colorAttachments() const {
    return RenderPipelineColorAttachmentDescriptorArrayRef { obj<MTLRenderPipelineDescriptor*>().colorAttachments };
}

void RenderPipelineDescriptorRef::setSampleCount(NSUInteger sampleCount) const {
    obj<MTLRenderPipelineDescriptor*>().sampleCount = sampleCount;
}

NSUInteger RenderPipelineDescriptorRef::sampleCount() const {
    return obj<MTLRenderPipelineDescriptor*>().sampleCount;
}

PipelineBufferDescriptorArrayRef RenderPipelineDescriptorRef::vertexBuffers() const {
    return PipelineBufferDescriptorArrayRef {obj<MTLRenderPipelineDescriptor*>().vertexBuffers};
}

namespace RenderPipelineDescriptor {

    RenderPipelineDescriptorRef create() {
        return RenderPipelineDescriptorRef { [[MTLRenderPipelineDescriptor alloc] init] };
    }

}

}
