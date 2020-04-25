//
//  Cloneable.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/25/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "Ref.h"

namespace apple::core {

class CloneableRef: Ref {
public:
    
    using Ref::Ref;
    
    CloneableRef clone() const;
    
};

}
