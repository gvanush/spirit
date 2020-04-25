//
//  Equatable.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/25/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "Ref.h"

namespace apple::core {

class EquatableRef: Ref {
public:
    
    using Ref::Ref;
    
    bool isEqual(const EquatableRef& eqRef) const;
    
};

}
