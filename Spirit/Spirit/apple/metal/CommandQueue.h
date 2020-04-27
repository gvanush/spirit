//
//  CommandQueue.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "../core/Ref.h"
#include "CommandBuffer.h"

namespace apple::metal {

class CommandQueueRef: public core::Ref {
public:
    using Ref::Ref;
    
    CommandBufferRef makeCommandBuffer() const;
    
};

}
