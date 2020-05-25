//
//  Spirit.m
//  Spirit
//
//  Created by Vanush Grigoryan on 4/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#import "Spirit.h"
#include "Scene.hpp"

#include "Metal.hpp"

#include <memory>

@interface Spirit () {
    std::unique_ptr<spirit::Scene> scene;
}

@end

@implementation Spirit

-(instancetype) initWithColorPixelFormat: (MTLPixelFormat) colorPixelFormat sampleCount: (NSUInteger) sampleCount {
    if(self = [super init]) {
        scene = std::make_unique<spirit::Scene>(apple::metal::PixelFormat {colorPixelFormat}, sampleCount);
    }
    return self;
}

-(void) onDraw: (SPRTRenderingContext*) renderingContext {
    scene->render(renderingContext.cpp);
}


@end
