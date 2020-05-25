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
    Default     = 0,
    Mutable     = 1,
    Immutable   = 2,
} API_AVAILABLE(macos(10.13), ios(11.0));

class PipelineBufferDescriptorRef: public ObjectRef {
public:
    using ObjectRef::ObjectRef;
  
    void setMutability(Mutability mutability) const;
    Mutability mutability() const;
};

}
