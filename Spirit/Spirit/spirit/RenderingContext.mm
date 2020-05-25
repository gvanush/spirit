//
//  RenderingContext.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 5/25/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#import "RenderingContext.h"

#include <memory>

@interface SPRTRenderingContext () {
    std::unique_ptr<spirit::RenderingContext> _cpp;
}

@end

@implementation SPRTRenderingContext

-(instancetype) init {
    if(self = [super init]) {
        _cpp = std::make_unique<spirit::RenderingContext>();
    }
    return self;
}

-(void) setDrawable: (id<MTLDrawable>) drawable {
    _cpp->setDrawable(apple::metal::DrawableRef {drawable});
}

-(id<MTLDrawable>) drawable {
    return _cpp->drawable().obj<id>();
}

-(void) setRenderPassDescriptor: (MTLRenderPassDescriptor*) renderPassDescriptor {
    _cpp->setRenderpassDescriptor(apple::metal::RenderPassDescriptorRef {renderPassDescriptor});
}

-(MTLRenderPassDescriptor*) renderPassDescriptor {
    return _cpp->renderpassDescriptor().obj<id>();
}

@end

@implementation SPRTRenderingContext (Cpp)

-(spirit::RenderingContext* _Nonnull) cpp {
    return _cpp.get();
}

@end
