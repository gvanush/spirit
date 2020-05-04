//
//  Geometry.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/4/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

namespace spirit {
namespace math {

struct Size2 {
    float width;
    float height;
    
#ifdef __METAL_VERSION__
    operator float2 () constant {
        return float2(width, height);
    }
    
    operator float2 () const {
        return float2(width, height);
    }
#endif
};

}
}
