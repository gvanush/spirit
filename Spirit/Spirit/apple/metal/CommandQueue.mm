//
//  CommandQueue.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "CommandQueue.h"

#import <Metal/Metal.h>

namespace apple::metal {

CommandBufferRef CommandQueueRef::makeCommandBuffer() const {
    return CommandBufferRef { [obj<id<MTLCommandQueue>>() commandBuffer] };
}

}
