//
//  Scene.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "RenderingContext.h"
#include "TriangleRenderer.hpp"
#include "TriangleWaveRenderer.hpp"

#include "math/Math.hpp"

#include "../apple/metal/Metal.hpp"

namespace spirit {

class Scene {
public:
    
    void render(const RenderingContext* renderingContext);
    
private:
//    TriangleRenderer _renderer;
    TriangleWaveRenderer _renderer;
};

}
