//
//  RenderPassDescriptor.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/22/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "../core/Ref.h"
#include "../core/Equatable.h"
#include "../core/Cloneable.h"

#include <objc/NSObjCRuntime.h>

namespace apple::metal {

class RenderPassDescriptorRef: public core::Ref {
public:
    
    using Ref::Ref;
    
    // Equatable
    bool isEqual(RenderPassDescriptorRef ref) const;
    operator core::EquatableRef () const;
    
    // Cloneable
    RenderPassDescriptorRef clone() const;
    operator core::CloneableRef () const;
    
    // RenderPassDescriptor
    NSUInteger renderTargetWidth() const;
    NSUInteger renderTargetHeight() const;
    
};

namespace RenderPassDescriptor {
    RenderPassDescriptorRef create();
};

}
