//
//  RenderPassDescriptor.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/22/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "../Object.h"

#include <objc/NSObjCRuntime.h>

namespace apple::metal {

class RenderPassDescriptorRef: public ObjectRef {
public:
    
    using ObjectRef::ObjectRef;
    
    NSUInteger renderTargetWidth() const;
    NSUInteger renderTargetHeight() const;

};

namespace RenderPassDescriptor {
    RenderPassDescriptorRef create();
};

}
