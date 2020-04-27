//
//  CommandBuffer.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "../core/Ref.h"
#include "RenderCommandEncoder.h"
#include "RenderPassDescriptor.h"
#include "Drawable.h"

namespace apple::metal {

class CommandBufferRef: public core::Ref {
public:
    using Ref::Ref;
    
    RenderCommandEncoderRef makeRenderCommandEncoder(const RenderPassDescriptorRef& descriptor) const;
    void present(const DrawableRef& drawableRef);
    void commit() const;
    
};

}
