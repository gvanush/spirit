//
//  Device.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "../core/Ref.h"
#include "CommandQueue.h"

namespace apple::metal {

class DeviceRef: public core::Ref {
public:
    using Ref::Ref;
    
    CommandQueueRef makeCommandQueue() const;
};

namespace Device {
    DeviceRef createSystemDefaultDevice();
};

}
