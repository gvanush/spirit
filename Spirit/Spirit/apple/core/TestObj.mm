//
//  TestObj.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/24/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "TestObj.h"

#import "TestObjCObject.h"

namespace apple::metal {

TestObjRef TestObj::create() {
    return TestObjRef { [[TestObjCObject alloc] init] };
}

}
