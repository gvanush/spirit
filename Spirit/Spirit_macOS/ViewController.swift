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
    var spirit: Spirit!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        mtkView = MTKView(frame: self.view.bounds, device: MTLCreateSystemDefaultDevice())
        mtkView.autoresizingMask = [.width, .height]
        mtkView.clearColor = MTLClearColorMake(0.5, 0.5, 1.0, 1.0);
        self.view.addSubview(mtkView)
        
        mtkView.delegate = self
        
        spirit = Spirit()
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }

    func mtkView(_ view: MTKView, drawableSizeWillChange size: CGSize) {
        print("drawableSizeWillChange")
    }
    
    func draw(in view: MTKView) {
        
        spirit.renderPassDescriptor = mtkView.currentRenderPassDescriptor
        spirit.drawable = mtkView.currentDrawable
        
        spirit.render()
    }

}

