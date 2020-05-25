//
//  Buffer.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/11/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "Resource.h"

namespace apple::metal {

class BufferRef: public ResourceRef {
public:
    using ResourceRef::ResourceRef;
    
    void* contents() const;
};

}
