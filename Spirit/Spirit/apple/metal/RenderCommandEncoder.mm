//
//  RenderCommandEncoder.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "RenderCommandEncoder.h"

#import <Metal/Metal.h>

namespace apple::metal {

void RenderCommandEncoderRef::endEncoding() const {
    [obj<id<MTLRenderCommandEncoder>>() endEncoding];
}

RenderCommandEncoderRef::operator CommandEncoderRef () const {
    return CommandEncoderRef { handle() };
}

}
