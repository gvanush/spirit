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
    spirit::Scene scene;
}

@end

@implementation Spirit

-(instancetype) init {
    if (self = [super init]) {
    }
    return self;
}

-(void) setRenderPassDescriptor: (MTLRenderPassDescriptor*) renderPassDescriptor {
    _renderPassDescriptor = renderPassDescriptor;
    scene.setRenderPassDescriptor(apple::metal::RenderPassDescriptorRef {_renderPassDescriptor});
}

-(void) setDrawable: (id<MTLDrawable>) drawable {
    _drawable = drawable;
    scene.setDrawable(apple::metal::DrawableRef {_drawable});
}

-(void) render {
    scene.render();
}


@end
