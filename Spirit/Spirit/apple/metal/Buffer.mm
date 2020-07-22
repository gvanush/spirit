//
//  Buffer.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/11/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Buffer.h"

#include <Metal/Metal.h>

namespace apple::metal {

void* BufferRef::contents() const {
    return obj<id<MTLBuffer>>().contents;
}

NSUInteger BufferRef::length() const {
    return obj<id<MTLBuffer>>().length;
}

}
