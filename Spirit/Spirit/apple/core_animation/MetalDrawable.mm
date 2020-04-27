//
//  MetalDrawable.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "MetalDrawable.h"

namespace apple::core_animation {

MetalDrawableRef::operator metal::DrawableRef () const {
    return metal::DrawableRef { handle() };
}

}
