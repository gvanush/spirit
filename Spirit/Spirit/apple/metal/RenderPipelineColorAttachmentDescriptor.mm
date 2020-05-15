//
//  RenderPipelineColorAttachmentDescriptor.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 5/2/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "RenderPipelineColorAttachmentDescriptor.h"

#import <Metal/Metal.h>

namespace apple::metal {

void RenderPipelineColorAttachmentDescriptorRef::setPixelFormat(PixelFormat pixelFromat) const {
    obj<MTLRenderPipelineColorAttachmentDescriptor*>().pixelFormat = to<MTLPixelFormat>(pixelFromat);
}

PixelFormat RenderPipelineColorAttachmentDescriptorRef::pixelFormat() const {
    return PixelFormat { obj<MTLRenderPipelineColorAttachmentDescriptor*>().pixelFormat };
}

}
