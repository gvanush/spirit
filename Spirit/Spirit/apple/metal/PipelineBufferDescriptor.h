//
//  PipelineBufferDescriptor.h
//  Spirit
//
//  Created by Vanush Grigoryan on 5/23/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "../Object.h"

namespace apple::metal {

enum class Mutability: NSUInteger {
    default_     = 0,
    mutable_     = 1,
    immutable   = 2,
} API_AVAILABLE(macos(10.13), ios(11.0));

class PipelineBufferDescriptorRef: public ObjectRef {
public:
    using ObjectRef::ObjectRef;
  
    void setMutability(Mutability mutability) const;
    Mutability mutability() const;
};

}
