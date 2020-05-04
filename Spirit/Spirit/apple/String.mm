//
//  String.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/30/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "String.h"

#import <Foundation/Foundation.h>

namespace apple {

const char* StringRef::utf8String() const {
    return [obj<NSString*>() UTF8String];
}

bool StringRef::isEqualToString(const StringRef& ref) const {
    return [obj<NSString*>() isEqualToString: ref.obj<NSString*>()];
}

namespace String {

    StringRef create() {
        return StringRef { [[NSString alloc] init] };
    }

    StringRef createWithUTF8String(const char* str) {
        return StringRef { [[NSString alloc] initWithUTF8String: str] };
    }

}

}
