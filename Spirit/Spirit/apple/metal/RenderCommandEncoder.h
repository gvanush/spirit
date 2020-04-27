//
//  RenderCommandEncoder.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "../core/Ref.h"
#include "CommandEncoder.h"

namespace apple::metal {

class RenderCommandEncoderRef: public core::Ref {
public:
    
    using Ref::Ref;
    
    // CommandEncoderRef
    void endEncoding() const;
    operator CommandEncoderRef () const;
};

}
