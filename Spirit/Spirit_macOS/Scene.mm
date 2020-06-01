//
//  Scene.m
//  Spirit_macOS
//
//  Created by Vanush Grigoryan on 6/1/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#import "Scene.h"
#include "Scene.hpp"

#include <memory>

@interface Scene () {
    std::unique_ptr<spirit_test::Scene> _cpp;
}


@end

@implementation Scene

-(instancetype) init {
    if(self = [super init]) {
        _cpp = std::make_unique<spirit_test::Scene>();
    }
    return self;
}

-(void) load {
    _cpp->load();
}

@end
