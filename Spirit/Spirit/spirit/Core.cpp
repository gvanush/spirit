//
//  Core.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/28/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Core.hpp"

namespace spirit {

namespace {

std::vector<std::unique_ptr<Entity>> entities;

}

Entity* createEntity() {
    return entities.emplace_back(std::make_unique<Entity>()).get();
}

void destroyEntity(Entity* entity) {
    auto it = std::find_if(entities.begin(), entities.end(), [entity] (const auto& item) {
        return item.get() == entity;
    });
    if(it == entities.end()) {
        return;
    }
    std::iter_swap(it, std::prev(entities.end()));
    entities.pop_back();
}

void tick(float dt) {
    for(const auto& entity: entities) {
        for(const auto& item: entity->_components) {
            item.second->update(dt);
        }
    }
}

void render(const RenderingContext* renderingContext) {
    for(const auto& entity: entities) {
        for(const auto& item: entity->_components) {
            item.second->render(renderingContext);
        }
    }
}

}
