//
//  CommandBuffer.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "RenderCommandEncoder.h"
#include "RenderPassDescriptor.h"
#include "Drawable.h"

#include "../ObjectProtocol.h"
#include "../String.h"

#include <functional>

namespace apple::metal {

class CommandBufferRef;

using CommandBufferHandler = std::function<void (CommandBufferRef)>;

class CommandBufferRef: public ObjectProtocolRef {
public:
    using ObjectProtocolRef::ObjectProtocolRef;
    
    void setLabel(const StringRef& labelRef) const;
    StringRef label() const;
    
    RenderCommandEncoderRef newRenderCommandEncoder(const RenderPassDescriptorRef& descriptorRef) const;
    
    void present(const DrawableRef& drawableRef);
    
    void addCompletedHandler(CommandBufferHandler handler);
    
    void commit() const;
    
};

}
