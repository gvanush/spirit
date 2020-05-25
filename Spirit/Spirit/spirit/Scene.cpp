//
//  Scene.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Scene.hpp"

#include "ShaderTypes.h"

namespace spirit {

Scene::Scene(apple::metal::PixelFormat colorPixelFormat, NSUInteger sampleCount)
: _renderer(colorPixelFormat, sampleCount)
{
}

void Scene::render() {
    _renderer.render();
}

}
