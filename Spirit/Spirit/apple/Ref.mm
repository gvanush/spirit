//
//  Object.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/22/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Ref.h"

namespace apple {

Ref::Ref()
: _handle {nullptr} {
}

Ref::Ref(const Ref& ref) {
    _handle = ref._handle;
    safeRetain();
}

Ref::Ref(Ref&& ref) {
    _handle = ref._handle;
    ref._handle = nullptr;
}

Ref::~Ref() {
    safeRelease();
    _handle = nullptr;
}

Ref& Ref::operator=(const Ref& ref) {
    if(this != &ref) {
        safeRelease();
        _handle = ref._handle;
        safeRetain();
    }
    return *this;
}

Ref& Ref::operator=(Ref&& ref) {
    if(this != &ref) {
        safeRelease();
        _handle = ref._handle;
        ref._handle = nullptr;
    }
    return *this;
}

bool Ref::operator == (const Ref& ref) const {
    return _handle == ref._handle;
}

bool Ref::operator != (const Ref& ref) const {
    return !(*this == ref);
}

Ref::operator bool () const {
    return _handle;
}

Ref::Ref(id ptr)
: _handle {(__bridge CFTypeRef) ptr} {
    safeRetain();
}

Ref::Ref(CFTypeRef handle)
: _handle {handle} {
    safeRetain();
}

void Ref::safeRetain() {
    if(_handle) {
        CFRetain(_handle);
    }
}

void Ref::safeRelease() {
    if(_handle) {
        CFRelease(_handle);
    }
}

}
