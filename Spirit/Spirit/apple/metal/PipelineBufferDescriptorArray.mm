//
//  PipelineBufferDescriptorArray.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 5/23/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "PipelineBufferDescriptorArray.h"

#import <Metal/Metal.h>

namespace apple::metal {

void PipelineBufferDescriptorArrayRef::setObjectAtIndex (const PipelineBufferDescriptorRef& objRef, NSUInteger index) const {
    obj<MTLPipelineBufferDescriptorArray*>()[index] = objRef.obj<MTLPipelineBufferDescriptor*>();
}

PipelineBufferDescriptorRef PipelineBufferDescriptorArrayRef::objectAtIndex (NSUInteger index) const {
    return PipelineBufferDescriptorRef { obj<MTLPipelineBufferDescriptorArray*>()[index] };
}

}
