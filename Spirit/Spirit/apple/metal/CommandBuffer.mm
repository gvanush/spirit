//
//  CommandBuffer.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "CommandBuffer.h"

#import <Metal/Metal.h>

namespace apple::metal {

RenderCommandEncoderRef CommandBufferRef::makeRenderCommandEncoder(const RenderPassDescriptorRef& descriptor) const {
    return RenderCommandEncoderRef { [obj<id<MTLCommandBuffer>>() renderCommandEncoderWithDescriptor: descriptor.obj<MTLRenderPassDescriptor*>()] };
}

void CommandBufferRef::present(const DrawableRef& drawableRef) {
    [obj<id<MTLCommandBuffer>>() presentDrawable: drawableRef.obj<id<MTLDrawable>>()];
}

void CommandBufferRef::commit() const {
    [obj<id<MTLCommandBuffer>>() commit];
}

}
