//
//  Object.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 5/1/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Object.h"

#import <Foundation/Foundation.h>

namespace apple {

ObjectRef ObjectRef::copy() const {
    return ObjectRef { [obj<NSObject*>() copy] };
}

}
