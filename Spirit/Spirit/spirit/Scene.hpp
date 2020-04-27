//
//  Scene.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "../apple/Metal.hpp"

namespace spirit {

class Scene {
public:
    
    Scene();
    
    inline void setRenderPassDescriptor(const apple::metal::RenderPassDescriptorRef& ref);
    inline void setDrawable(const apple::metal::DrawableRef& ref);
    
    void render() const;
    
private:
    apple::metal::DeviceRef _deviceRef;
    apple::metal::CommandQueueRef _commandQueueRef;
    apple::metal::RenderPassDescriptorRef _renderPassDescriptorRef;
    apple::metal::DrawableRef _drawableRef;
};

void Scene::setRenderPassDescriptor(const apple::metal::RenderPassDescriptorRef& ref) {
    _renderPassDescriptorRef = ref;
}

void Scene::setDrawable(const apple::metal::DrawableRef& ref) {
    _drawableRef = ref;
}

}
