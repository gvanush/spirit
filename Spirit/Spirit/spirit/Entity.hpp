//
//  Entity.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/28/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include <unordered_map>
#include <memory>
#include <cassert>

#include "Component.hpp"

namespace spirit {

class RenderingContext;

class Entity {
public:
    
    Entity() = default;
    ~Entity() = default;
    
    Entity(const Entity&) = delete;
    Entity& operator= (const Entity&) = delete;
    
    Entity(Entity&&) = delete;
    Entity& operator= (Entity&&) = delete;
    
    template <class CT>
    CT* addComponent() {
        static_assert(std::is_base_of_v<Component<CT>, CT>, "Each component type 'CT' must inherit from 'spirit::Component<CT>' type");
        const auto& res = _components.try_emplace(CT::typeId, std::make_unique<CT>());
        assert(res.second); // Entity already has a component with type 'CT'
        return static_cast<CT*>(res.first->second.get());
    }
    
    template <class CT>
    CT* getComponent() const {
        static_assert(std::is_base_of_v<Component<CT>, CT>, "Each component type 'CT' must inherit from 'spirit::Component<CT>' type");
        auto it = _components.find(CT::typeId);
        return (it == _components.end() ? nullptr : static_cast<CT*>(it->second.get()));
    }
    
    template <class CT>
    void removeComponent() {
        static_assert(std::is_base_of_v<Component<CT>, CT>, "Each component type 'CT' must inherit from 'spirit::Component<CT>' type");
        _components.erase(CT::typeId);
    }
    
    friend void tick(float);
    friend void render(const RenderingContext*);
    
private:
    std::unordered_map<ComponentTypeId, std::unique_ptr<BaseComponent>> _components;
};

}
