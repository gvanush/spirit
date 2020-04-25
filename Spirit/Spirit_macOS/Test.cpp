//
//  Test.cpp
//  Spirit_macOS
//
//  Created by Vanush Grigoryan on 4/22/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Test.hpp"

#include <iostream>
#include <chrono>

namespace test {

void Test::run() {
    using namespace apple::metal;
    
    using nano = std::chrono::nanoseconds;
    auto start = std::chrono::high_resolution_clock::now();
    
    auto ref = TestObj::create();
    
    auto ref2 = TestObj::create();
    
    ref = ref2;
    
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "methodCall() took "
              << std::chrono::duration_cast<nano>(finish - start).count()
              << " nanoseconds\n";
}

void Test::methodCall(apple::metal::TestObjRef ref) {
    
}

}
