//
//  ObjectProtocol.h
//  Spirit
//
//  Created by Vanush Grigoryan on 5/2/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "Ref.h"

namespace apple {

class ObjectProtocolRef: public Ref {
public:
    
    using Ref::Ref;
    
    bool isEqual(const Ref& ref) const;
    
};

}
