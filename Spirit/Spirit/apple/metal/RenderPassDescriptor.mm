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
    return [ptr<MTLRenderPassDescriptor>() isEqual: ref.ptr<MTLRenderPassDescriptor>()];
}

RenderPassDescriptorRef::operator core::EquatableRef () const {
    return core::EquatableRef { handle() };
}

RenderPassDescriptorRef RenderPassDescriptorRef::clone() const {
    return RenderPassDescriptorRef { [ptr<MTLRenderPassDescriptor>() copy] };
}

RenderPassDescriptorRef::operator core::CloneableRef () const {
    return core::CloneableRef { handle() };
}


NSUInteger RenderPassDescriptorRef::renderTargetWidth() const {
    return [ptr<MTLRenderPassDescriptor>() renderTargetWidth];
}

NSUInteger RenderPassDescriptorRef::renderTargetHeight() const {
    return [ptr<MTLRenderPassDescriptor>() renderTargetHeight];
}

namespace RenderPassDescriptor {

    RenderPassDescriptorRef create() {
        return RenderPassDescriptorRef { [[MTLRenderPassDescriptor alloc] init] };
    }

}

}
