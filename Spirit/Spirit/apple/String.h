//
//  String.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/30/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "Object.h"

namespace apple {

class StringRef: public ObjectRef {
public:
    using ObjectRef::ObjectRef;
    
    const char* utf8String() const;
    
    bool isEqualToString(const StringRef& ref) const;
    
};

namespace String {
    StringRef create();
    StringRef createWithUTF8String(const char* str);
}

inline StringRef operator"" _str (const char* str, [[maybe_unused]] size_t size) {
    return String::createWithUTF8String(str);
}

}
