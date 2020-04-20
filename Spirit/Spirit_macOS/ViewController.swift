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
    
    var device: MTLDevice!
    var commandQueue: MTLCommandQueue!
    var mtkView: MTKView!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        device = MTLCreateSystemDefaultDevice()
        commandQueue = device.makeCommandQueue()
        
        mtkView = MTKView(frame: self.view.bounds, device: device)
        mtkView.autoresizingMask = [.width, .height]
        mtkView.clearColor = MTLClearColorMake(0.5, 0.5, 1.0, 1.0);
        self.view.addSubview(mtkView)
        
        mtkView.delegate = self
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
        guard let renderPassDescriptor = mtkView.currentRenderPassDescriptor else {
            return
        }
        
        let commandBuffer = commandQueue.makeCommandBuffer()!
        let commandEncoder = commandBuffer.makeRenderCommandEncoder(descriptor: renderPassDescriptor)!
        
        commandEncoder.endEncoding()
        
        commandBuffer.present(mtkView.currentDrawable!)
        
        commandBuffer.commit()
    }

}

