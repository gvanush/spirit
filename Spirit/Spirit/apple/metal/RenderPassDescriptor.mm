//
//  RenderPassDescriptor.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/22/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "RenderPassDescriptor.h"

#import <Metal/Metal.h>

namespace apple::metal {

bool RenderPassDescriptorRef::isEqual(RenderPassDescriptorRef ref) const {
    return [obj<MTLRenderPassDescriptor*>() isEqual: ref.obj<MTLRenderPassDescriptor*>()];
}

RenderPassDescriptorRef::operator core::EquatableRef () const {
    return core::EquatableRef { handle() };
}

RenderPassDescriptorRef RenderPassDescriptorRef::clone() const {
    return RenderPassDescriptorRef { [obj<MTLRenderPassDescriptor*>() copy] };
}

RenderPassDescriptorRef::operator core::CloneableRef () const {
    return core::CloneableRef { handle() };
}


NSUInteger RenderPassDescriptorRef::renderTargetWidth() const {
    return [obj<MTLRenderPassDescriptor*>() renderTargetWidth];
}

NSUInteger RenderPassDescriptorRef::renderTargetHeight() const {
    return [obj<MTLRenderPassDescriptor*>() renderTargetHeight];
}

namespace RenderPassDescriptor {

    RenderPassDescriptorRef create() {
        return RenderPassDescriptorRef { [[MTLRenderPassDescriptor alloc] init] };
    }

}

}
