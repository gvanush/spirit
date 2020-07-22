//
//  PipelineBufferDescriptor.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 5/23/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "PipelineBufferDescriptor.h"

#include "../../util/TypeCast.hpp"

#import <Metal/Metal.h>

template <>
inline MTLMutability to(apple::metal::Mutability mutability) {
    return MTLMutability { std::underlying_type_t<apple::metal::Mutability>(mutability) };
}

namespace apple::metal {

void PipelineBufferDescriptorRef::setMutability(Mutability mutability) const {
    obj<MTLPipelineBufferDescriptor*>().mutability = to<MTLMutability>(mutability);
}

Mutability PipelineBufferDescriptorRef::mutability() const {
    return Mutability {obj<MTLPipelineBufferDescriptor*>().mutability};
}

}
