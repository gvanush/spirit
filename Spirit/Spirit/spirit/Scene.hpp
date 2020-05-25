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
    
    Scene(apple::metal::PixelFormat colorPixelFormat, NSUInteger sampleCount);
    
    inline void setViewportSize(const math::Size2& size);
    
    void render(const RenderingContext* renderingContext);
    
private:
//    TriangleRenderer _renderer;
    TriangleWaveRenderer _renderer;
};

void Scene::setViewportSize(const math::Size2& size) {
    _renderer.setViewportSize(size);
}

}
