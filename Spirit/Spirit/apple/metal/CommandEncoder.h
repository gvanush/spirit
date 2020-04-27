//
//  CommandEncoder.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/26/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "../core/Ref.h"

namespace apple::metal {

class CommandEncoderRef: public core::Ref {
public:
    
    using Ref::Ref;
    
    void endEncoding() const;
    
};

}
