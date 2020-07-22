//
//  Scene.cpp
//  Spirit_macOS
//
//  Created by Vanush Grigoryan on 5/2/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Scene.hpp"

#include "spirit/Spirit.hpp"

namespace spirit_test {

void Scene::load() {
    
    using namespace spirit;
    
    auto entity = createEntity();
    
    entity->addComponent<DurerRenderer>();
    
}

}
