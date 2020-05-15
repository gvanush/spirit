//
//  Scene.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "TriangleRenderer.hpp"

#include "math/Math.hpp"

#include "../apple/metal/Metal.hpp"

namespace spirit {

class Scene {
public:
    
    Scene(apple::metal::PixelFormat colorPixelFormat);
    
    inline void setRenderPassDescriptor(const apple::metal::RenderPassDescriptorRef& ref);
    inline void setDrawable(const apple::metal::DrawableRef& ref);
    
    inline void setViewportSize(const math::Size2& size);
    
    void render() const;
    
private:
    TriangleRenderer _renderer;
};

void Scene::setRenderPassDescriptor(const apple::metal::RenderPassDescriptorRef& ref) {
    _renderer.setRenderPassDescriptor(ref);
}

void Scene::setDrawable(const apple::metal::DrawableRef& ref) {
    _renderer.setDrawable(ref);
}

void Scene::setViewportSize(const math::Size2& size) {
    _renderer.setViewportSize(size);
}

}
