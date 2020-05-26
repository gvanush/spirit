//
//  Library.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/30/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Library.h"

#import <Metal/Metal.h>

namespace apple::metal {

FunctionRef LibraryRef::newFunction(const StringRef& name) const {
    return FunctionRef { [obj<id<MTLLibrary>>() newFunctionWithName: name.obj<NSString*>()] };
}

}
