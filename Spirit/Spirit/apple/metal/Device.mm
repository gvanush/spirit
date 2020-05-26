//
//  Device.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Device.h"

#import <Metal/Metal.h>

namespace apple::metal {

CommandQueueRef DeviceRef::newCommandQueue() const {
    return CommandQueueRef { [obj<id<MTLDevice>>() newCommandQueue] };
}

LibraryRef DeviceRef::newDefaultLibrary() const {
    return LibraryRef { [obj<id<MTLDevice>>() newDefaultLibrary] };
}

RenderPipelineStateRef DeviceRef::newRenderPipelineState(const RenderPipelineDescriptorRef& descriptorRef, ErrorRef* errorRefPtr) const {
    if(errorRefPtr) {
        NSError* error = errorRefPtr->obj<NSError*>();
        id<MTLRenderPipelineState> renderPipelineState = [obj<id<MTLDevice>>() newRenderPipelineStateWithDescriptor: descriptorRef.obj<MTLRenderPipelineDescriptor*>() error: &error];
        *errorRefPtr = ErrorRef { error };
        return RenderPipelineStateRef { renderPipelineState };
    } else {
        return RenderPipelineStateRef { [obj<id<MTLDevice>>() newRenderPipelineStateWithDescriptor: descriptorRef.obj<MTLRenderPipelineDescriptor*>() error: nil] };
    }
}

BufferRef DeviceRef::newBufferWithLength(NSUInteger length, ResourceOptions options) const {
    return BufferRef { [obj<id<MTLDevice>>() newBufferWithLength: length options: to<MTLResourceOptions>(options)] };
}

DeviceRef createSystemDefaultDevice() {
    return DeviceRef { MTLCreateSystemDefaultDevice() };
}

}
