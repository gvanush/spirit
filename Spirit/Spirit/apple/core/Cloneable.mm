//
//  Cloneable.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/25/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Cloneable.h"

#import <Foundation/Foundation.h>

namespace apple::core {

CloneableRef CloneableRef::clone() const {
    return CloneableRef { [obj<id>() copy] };
}

}
