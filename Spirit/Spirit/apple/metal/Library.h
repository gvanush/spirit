//
//  Library.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/30/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "Function.h"

#include "../ObjectProtocol.h"
#include "../String.h"

namespace apple::metal {

class LibraryRef: public ObjectProtocolRef {
public:
    using ObjectProtocolRef::ObjectProtocolRef;
    
    FunctionRef makeFunction(const StringRef& strRef) const;
};

}
