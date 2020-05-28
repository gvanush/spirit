//
//  Component.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

namespace spirit {

using ComponentTypeId = unsigned int;

namespace _internal {

inline ComponentTypeId createComponentTypeId() {
    static ComponentTypeId typeId = 0;
    return ++typeId;
}

}

class RenderingContext;

class BaseComponent {
public:
    
    BaseComponent(const BaseComponent&) = delete;
    BaseComponent& operator= (const BaseComponent&) = delete;
    
    BaseComponent(BaseComponent&&) = delete;
    BaseComponent& operator= (BaseComponent&&) = delete;
    
    virtual ~BaseComponent() = default;
    
    virtual void update([[maybe_unused]] float dt) {}
    
    virtual void render(const RenderingContext* renderingContext) {}
    
protected:
    BaseComponent() = default;
};

template <typename CT>
class Component: public BaseComponent {
public:
    static inline ComponentTypeId typeId = _internal::createComponentTypeId();
};

}
