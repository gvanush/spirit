//
//  Object.h
//  Spirit
//
//  Created by Vanush Grigoryan on 5/1/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "ObjectProtocol.h"

namespace apple {

class ObjectRef: public ObjectProtocolRef {
public:
    
    using ObjectProtocolRef::ObjectProtocolRef;
    
    ObjectRef copy() const;
    
};

}
