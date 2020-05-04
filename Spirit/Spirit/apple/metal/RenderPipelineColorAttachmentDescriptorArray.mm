//
//  RenderPipelineColorAttachmentDescriptorArray.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 5/1/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "RenderPipelineColorAttachmentDescriptorArray.h"

#import <Metal/Metal.h>

namespace apple::metal {

void RenderPipelineColorAttachmentDescriptorArrayRef::setObjectAtIndex (const RenderPipelineColorAttachmentDescriptorRef& objRef, NSUInteger index) const {
    obj<MTLRenderPipelineColorAttachmentDescriptorArray*>()[index] = objRef.obj<MTLRenderPipelineColorAttachmentDescriptor*>();
}

RenderPipelineColorAttachmentDescriptorRef RenderPipelineColorAttachmentDescriptorArrayRef::objectAtIndex (NSUInteger index) const {
    return RenderPipelineColorAttachmentDescriptorRef { obj<MTLRenderPipelineColorAttachmentDescriptorArray*>()[index] };
}

}
