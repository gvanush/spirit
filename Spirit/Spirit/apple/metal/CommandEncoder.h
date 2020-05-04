//
//  CommandEncoder.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "../ObjectProtocol.h"
#include "../String.h"

namespace apple::metal {

class CommandEncoderRef: public ObjectProtocolRef {
public:
    
    using ObjectProtocolRef::ObjectProtocolRef;
    
    void setLabel(const StringRef& labelRef) const;
    StringRef label() const;
    
    void endEncoding() const;
    
};

}
