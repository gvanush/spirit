//
//  Vec2.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/28/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

namespace spirit {

struct Vec2 {
    float x;
    float y;
    
#ifdef __METAL_VERSION__
    operator float2 () constant {
        return float2(x, y);
    }
    
    operator float2 () const {
        return float2(x, y);
    }
#endif
    
};

inline Vec2 operator+ (Vec2 lhs, Vec2 rhs) {
    return Vec2 {lhs.x + rhs.x, lhs.y + rhs.y};
}

}
