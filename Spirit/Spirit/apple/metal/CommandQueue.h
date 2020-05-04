//
//  CommandQueue.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "CommandBuffer.h"

#include "../ObjectProtocol.h"

namespace apple::metal {

class CommandQueueRef: public ObjectProtocolRef {
public:
    using ObjectProtocolRef::ObjectProtocolRef;
    
    CommandBufferRef newCommandBuffer() const;
    
};

}
