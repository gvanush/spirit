//
//  TestObj.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 4/24/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "Ref.h"

namespace apple::metal {

class TestObjRef: public core::Ref {
public:
    
    using Ref::Ref;
    friend class TestObj;
    
};

struct TestObj {
    TestObj() = delete;
    
    static TestObjRef create();
};

}
