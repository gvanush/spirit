//
//  Scene.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Scene.hpp"



namespace spirit {

Scene::Scene() {
    _deviceRef = apple::metal::Device::createSystemDefaultDevice();
    _commandQueueRef = _deviceRef.makeCommandQueue();
}

void Scene::render() const {
    
    assert(_drawableRef);
    assert(_renderPassDescriptorRef);
    
    using namespace apple::metal;

    auto commandBufferRef = _commandQueueRef.makeCommandBuffer();
    assert(commandBufferRef);
    
    auto commandEncoderRef = commandBufferRef.makeRenderCommandEncoder(_renderPassDescriptorRef);
    assert(commandEncoderRef);
    
    commandEncoderRef.endEncoding();
    
    commandBufferRef.present(_drawableRef);
    
    commandBufferRef.commit();
      
}

}
