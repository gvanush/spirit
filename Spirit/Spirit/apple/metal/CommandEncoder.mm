//
//  CommandEncoder.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "CommandEncoder.h"

#import <Metal/Metal.h>

namespace apple::metal {

void CommandEncoderRef::setLabel(const StringRef& labelRef) const {
    obj<id<MTLCommandEncoder>>().label = labelRef.obj<NSString*>();
}

StringRef CommandEncoderRef::label() const {
    return StringRef { obj<id<MTLCommandEncoder>>().label };
}

void CommandEncoderRef::endEncoding() const {
    [obj<id<MTLCommandEncoder>>() endEncoding];
}

}
