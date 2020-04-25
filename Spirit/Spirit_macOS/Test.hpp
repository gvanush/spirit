//
//  Test.hpp
//  Spirit_macOS
//
//  Created by Vanush Grigoryan on 4/22/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "apple/core/TestObj.h"

namespace test {

struct Test {
    
    static void run();
    
    static void methodCall(apple::metal::TestObjRef ref);
};

}
