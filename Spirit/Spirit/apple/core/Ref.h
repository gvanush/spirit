//
//  Object.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/22/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include <CoreFoundation/CoreFoundation.h>

namespace apple::core {

class Ref {
public:
    Ref();
    Ref(const Ref& objRef);
    Ref(Ref&& objRef);
    ~Ref();
    
    Ref& operator=(const Ref& ref);
    Ref& operator=(Ref&& ref);
    
    bool operator == (const Ref& ref) const;
    bool operator != (const Ref& ref) const;
    
    operator bool () const;
        
#ifdef __OBJC__
    explicit Ref(id ptr);
    explicit Ref(CFTypeRef handle);
    
    template <typename T>
    T obj() const {
        return (__bridge T) _handle;
    }
    
    CFTypeRef handle() const {
        return _handle;
    }
    
#endif
    
private:
    void safeRetain();
    void safeRelease();
    
    CFTypeRef _handle;
};

}
