//
//  ViewController.m
//  TestBed
//
//  Created by Vanush Grigoryan on 8/2/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#import "ViewController.h"

#include "spirit/Spirit.hpp"
#include "spirit/Polyline.hpp"
#include "spirit/PolylineRenderer.hpp"

#import <MetalKit/MetalKit.h>

#include <memory>

@interface ViewController () <MTKViewDelegate> {
    std::unique_ptr<spirit::RenderingContext> _renderingContext;
    spirit::Polyline _polyline;
}

@property (nonatomic, readwrite) MTKView* mtkView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _renderingContext = std::make_unique<spirit::RenderingContext>();
    
    self.mtkView = [[MTKView alloc] initWithFrame: self.view.bounds device: spirit::RenderingContext::device.obj<id>()];
    self.mtkView.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable;
    self.mtkView.clearColor = MTLClearColorMake(0.3, 0.3, 0.3, 1.0);
    self.mtkView.colorPixelFormat = to<MTLPixelFormat>(spirit::RenderingContext::kColorPixelFormat);
    self.mtkView.sampleCount = spirit::RenderingContext::kSampleCount;
    [self.view addSubview: self.mtkView];
    [self.view addSubview: self.mtkView positioned: NSWindowBelow relativeTo: nil];
    
    self.mtkView.delegate = self;
    
    [self setupScene];

    // Do any additional setup after loading the view.
}

-(void) setupScene {
    using namespace spirit;
    
    auto entity = createEntity();
    
    auto polylineRenderer = entity->addComponent<PolylineRenderer>();
    polylineRenderer->setPolyline(&_polyline);
}

-(void) mouseUp: (NSEvent*) event {
    
    if(_polyline.isClosed()) {
        return;
    }
    
    float backingScaleFactor = [NSScreen mainScreen].backingScaleFactor;
    NSPoint point = [self.mtkView convertPoint: event.locationInWindow fromView: nil];
    _polyline.addPoint(simd::float2 {static_cast<float>(point.x) * backingScaleFactor, static_cast<float>(point.y) * backingScaleFactor});
    
//    NSLog(@"%f, %f", (point.x * backingScaleFactor) / _renderingContext->drawableSize().x, (point.y * backingScaleFactor) / _renderingContext->drawableSize().y);
}

-(void)rightMouseUp:(NSEvent *)event {
    if(!_polyline.isClosed() && _polyline.points().size() > 1) {
        _polyline.close();
    }
}

-(IBAction) subdivide:(NSButton *)sender {
    // TODO
}

-(IBAction) clear: (NSButton *)sender {
    _polyline.clear();
}


-(void) drawInMTKView:(nonnull MTKView *)view {
    
    id<MTLDrawable> drawable = self.mtkView.currentDrawable;
    MTLRenderPassDescriptor* renderPassDescriptor = self.mtkView.currentRenderPassDescriptor;
    if(drawable == nil || renderPassDescriptor == nil) {
        return;
    }
    
    _renderingContext->setRenderpassDescriptor(apple::metal::RenderPassDescriptorRef {renderPassDescriptor});
    _renderingContext->setDrawable(apple::metal::DrawableRef {drawable});
    
    spirit::tick(1.0 / 60.0);
    
    spirit::render(_renderingContext.get());
}

- (void)mtkView:(nonnull MTKView *)view drawableSizeWillChange:(CGSize)size {
    _renderingContext->setDrawableSize(simd::float2 {static_cast<float>(size.width), static_cast<float>(size.height)});
}

@end
