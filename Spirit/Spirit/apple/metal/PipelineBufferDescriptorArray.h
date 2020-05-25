//
//  PipelineBufferDescriptorArray.h
//  Spirit
//
//  Created by Vanush Grigoryan on 5/23/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "PipelineBufferDescriptor.h"

#include "../Object.h"

namespace apple::metal {

class PipelineBufferDescriptorArrayRef: public ObjectRef {
public:
    using ObjectRef::ObjectRef;
    
    void setObjectAtIndex (const PipelineBufferDescriptorRef& objRef, NSUInteger index) const;
    PipelineBufferDescriptorRef objectAtIndex (NSUInteger index) const;
    
};

}
