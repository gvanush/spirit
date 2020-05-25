//
//  Resource.h
//  Spirit
//
//  Created by Vanush Grigoryan on 5/11/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "ResourceOptions.h"

#include "../ObjectProtocol.h"
#include "../String.h"

namespace apple::metal {

class ResourceRef: public ObjectProtocolRef {
public:
    using ObjectProtocolRef::ObjectProtocolRef;
    
    void setLabel(const StringRef& labelRef) const;
    StringRef label() const;
    
};

}


