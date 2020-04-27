//
//  Device.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Device.h"

#import <Metal/Metal.h>

namespace apple::metal {

CommandQueueRef DeviceRef::makeCommandQueue() const {
    return CommandQueueRef { [obj<id<MTLDevice>>() newCommandQueue] };
}

namespace Device {

    DeviceRef createSystemDefaultDevice() {
        return DeviceRef { MTLCreateSystemDefaultDevice() };
    }

}

}
