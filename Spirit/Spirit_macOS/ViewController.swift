//
//  ViewController.swift
//  Spirit_macOS
//
//  Created by Vanush Grigoryan on 4/20/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

import Cocoa
import MetalKit

class ViewController: NSViewController, MTKViewDelegate {
    
    var mtkView: MTKView!
    var renderingContext: SPRTRenderingContext!
    var scene = Scene()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        mtkView = MTKView(frame: self.view.bounds, device: SPRTRenderingContext.device())
        mtkView.autoresizingMask = [.width, .height]
        mtkView.clearColor = MTLClearColorMake(0.5, 0.5, 1.0, 1.0);
        mtkView.colorPixelFormat = SPRTRenderingContext.colorPixelFormat()
        mtkView.sampleCount = Int(SPRTRenderingContext.sampleCount())
        self.view.addSubview(mtkView)
        
        mtkView.delegate = self
        
        renderingContext = SPRTRenderingContext()
        
        scene.load()
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }

    func mtkView(_ view: MTKView, drawableSizeWillChange size: CGSize) {
        renderingContext.drawableSize = size
    }
    
    func draw(in view: MTKView) {
        
        guard let drawable = mtkView.currentDrawable, let renderPassDescriptor = mtkView.currentRenderPassDescriptor else {
            return
        }
        
        renderingContext.renderPassDescriptor = renderPassDescriptor
        renderingContext.drawable = drawable
        
        SPRTCore.tick(1.0 / 60.0)
            
        SPRTCore.render(renderingContext)
    }

}

