//
//  PipelineBufferDescriptor.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 5/23/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "PipelineBufferDescriptor.h"

#import <Metal/Metal.h>

namespace apple::metal {

template <typename T>
inline T to(Mutability mutability) {
    return static_cast<T>(mutability);
}

template <>
inline MTLMutability to(Mutability mutability) {
    return MTLMutability { std::underlying_type_t<Mutability>(mutability) };
}

void PipelineBufferDescriptorRef::setMutability(Mutability mutability) const {
    obj<MTLPipelineBufferDescriptor*>().mutability = to<MTLMutability>(mutability);
}

Mutability PipelineBufferDescriptorRef::mutability() const {
    return Mutability {obj<MTLPipelineBufferDescriptor*>().mutability};
}

}
