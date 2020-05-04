//
//  RenderPipelineColorAttachmentDescriptorArray.h
//  Spirit
//
//  Created by Vanush Grigoryan on 5/1/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "RenderPipelineColorAttachmentDescriptor.h"

#include "../Object.h"

namespace apple::metal {

class RenderPipelineColorAttachmentDescriptorArrayRef: public ObjectRef {
public:
    using ObjectRef::ObjectRef;
    
    void setObjectAtIndex (const RenderPipelineColorAttachmentDescriptorRef& objRef, NSUInteger index) const;
    RenderPipelineColorAttachmentDescriptorRef objectAtIndex (NSUInteger index) const;
    
};

}
