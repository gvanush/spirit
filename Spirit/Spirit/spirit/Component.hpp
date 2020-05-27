//
//  Component.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

namespace spirit {

class Component {
public:
    
    Component(const Component&) = delete;
    Component& operator= (const Component&) = delete;
    
    Component(Component&&) = delete;
    Component& operator= (Component&&) = delete;
    
    virtual ~Component() = default;
    
    virtual void update() {}
    
protected:
    Component() = default;
    
};

}
