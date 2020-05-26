//
//  Device.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "CommandQueue.h"
#include "Library.h"
#include "RenderPipelineState.h"
#include "RenderPipelineDescriptor.h"
#include "Resource.h"
#include "Buffer.h"

#include "../ObjectProtocol.h"
#include "../Error.h"

namespace apple::metal {

class DeviceRef: public ObjectProtocolRef {
public:
    using ObjectProtocolRef::ObjectProtocolRef;
    
    CommandQueueRef newCommandQueue() const;
    
    LibraryRef newDefaultLibrary() const;
    
    RenderPipelineStateRef newRenderPipelineState(const RenderPipelineDescriptorRef& descriptorRef, ErrorRef* errorRefPtr) const;
    
    BufferRef newBufferWithLength(NSUInteger length, ResourceOptions options) const;
    
};

DeviceRef createSystemDefaultDevice();

}
