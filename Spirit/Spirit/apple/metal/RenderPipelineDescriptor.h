//
//  RenderPipelineDescriptor.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/30/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//
#pragma once

#include "Function.h"
#include "RenderPipelineColorAttachmentDescriptorArray.h"
#include "PipelineBufferDescriptorArray.h"

#include "../Object.h"
#include "../String.h"

namespace apple::metal {

class RenderPipelineDescriptorRef: public ObjectRef {
public:
    using ObjectRef::ObjectRef;
    
    void setLabel(const StringRef& labelRef) const;
    StringRef label() const;
    
    void setVertexFunction(const FunctionRef& vertexFunctionRef) const;
    FunctionRef vertexFunction() const;
    
    void setFragmentFunction(const FunctionRef& fragmentFunctionRef) const;
    FunctionRef fragmentFunction() const;
    
    RenderPipelineColorAttachmentDescriptorArrayRef colorAttachments() const;
    
    void setSampleCount(NSUInteger sampleCount) const;
    NSUInteger sampleCount() const;
    
    PipelineBufferDescriptorArrayRef vertexBuffers() const;

};

namespace RenderPipelineDescriptor {
    RenderPipelineDescriptorRef create();
}

}
