//
//  SPRTCore.m
//  Spirit
//
//  Created by Vanush Grigoryan on 4/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#import "SPRTCore.h"
#import "SPRTRenderingContext.h"

#include "Core.hpp"

@implementation SPRTCore

+(void) tick: (float) dt {
    spirit::tick(dt);
}

+(void) render: (SPRTRenderingContext*) rc {
    spirit::render(rc.cpp);
}


@end
