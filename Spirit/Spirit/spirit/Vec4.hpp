//
//  Vec4.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/28/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

namespace spirit {

struct Vec4 {
    float x;
    float y;
    float z;
    float w;
    
#ifdef __METAL_VERSION__
    operator float4 () constant {
        return float4(x, y, z, w);
    }
    
    operator float4 () const {
        return float4(x, y, z, w);
    }
#endif
    
};

}
