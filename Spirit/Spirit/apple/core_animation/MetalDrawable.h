//
//  MetalDrawable.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "../core/Ref.h"
#include "../metal/Drawable.h"

namespace apple::core_animation {

class MetalDrawableRef: public core::Ref {
public:
    using Ref::Ref;
    
    operator metal::DrawableRef () const;
};

}
