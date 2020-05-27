//
//  Renderer.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/25/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "Component.hpp"

namespace spirit {

class RenderingContext;

class Renderer: public Component {
public:
    
    Renderer(const Renderer&) = delete;
    Renderer& operator= (const Renderer&) = delete;
    
    Renderer(Renderer&&) = delete;
    Renderer& operator= (Renderer&&) = delete;
    
    virtual ~Renderer() = default;
    
    virtual void render(const RenderingContext* renderingContext) = 0;
    
protected:
    Renderer() = default;
    
};

}
