//
//  Renderer.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/25/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

namespace spirit {

class Renderer {
public:
    
    virtual void render() = 0;
    
    virtual ~Renderer() {}
};

}
