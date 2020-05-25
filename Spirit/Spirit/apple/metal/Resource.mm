//
//  Resource.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 5/11/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Resource.h"

#import <Metal/Metal.h>

namespace apple::metal {

void ResourceRef::setLabel(const StringRef& labelRef) const {
    obj<id<MTLResource>>().label = labelRef.obj<NSString*>();
}

StringRef ResourceRef::label() const {
    return StringRef { obj<id<MTLResource>>().label };
}

}
