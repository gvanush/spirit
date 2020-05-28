//
//  Core.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/28/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "Entity.hpp"

#include <vector>
#include <memory>

namespace spirit {

class RenderingContext;

Entity* createEntity();
void destroyEntity(Entity* entity);

void tick(float dt);

void render(const RenderingContext* renderingContext);

}
