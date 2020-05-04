//
//  CommandBuffer.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "CommandBuffer.h"

#import <Metal/Metal.h>

#include <iostream>

namespace apple::metal {

void CommandBufferRef::setLabel(const StringRef& labelRef) const {
    obj<id<MTLCommandBuffer>>().label = labelRef.obj<NSString*>();
}

StringRef CommandBufferRef::label() const {
    return StringRef { obj<id<MTLCommandBuffer>>().label };
}

RenderCommandEncoderRef CommandBufferRef::newRenderCommandEncoder(const RenderPassDescriptorRef& descriptorRef) const {
    return RenderCommandEncoderRef { [obj<id<MTLCommandBuffer>>() renderCommandEncoderWithDescriptor: descriptorRef.obj<MTLRenderPassDescriptor*>()] };
}

void CommandBufferRef::present(const DrawableRef& drawableRef) {
    [obj<id<MTLCommandBuffer>>() presentDrawable: drawableRef.obj<id<MTLDrawable>>()];
}

void CommandBufferRef::commit() const {
    [obj<id<MTLCommandBuffer>>() commit];
}

}
