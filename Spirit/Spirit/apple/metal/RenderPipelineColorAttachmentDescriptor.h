//
//  RenderPipelineColorAttachmentDescriptor.h
//  Spirit
//
//  Created by Vanush Grigoryan on 5/2/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "PixelFormat.h"

#include "../Object.h"

namespace apple::metal {

class RenderPipelineColorAttachmentDescriptorRef: public ObjectRef {
public:
    using ObjectRef::ObjectRef;
    
    void setPixelFormat(PixelFormat pixelFromat) const;
    PixelFormat pixelFormat() const;
    
};

}
