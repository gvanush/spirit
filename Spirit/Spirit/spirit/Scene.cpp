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

Scene::Scene(apple::metal::PixelFormat colorPixelFormat)
: _renderer(colorPixelFormat)
{
}

void Scene::render() const {
    _renderer.render();
}

}
