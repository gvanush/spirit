//
//  Spirit.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

@interface Spirit : NSObject

@property (nonatomic, strong) MTLRenderPassDescriptor* _Nullable renderPassDescriptor;
@property (nonatomic, strong) id<MTLDrawable> _Nullable drawable;

-(instancetype _Nonnull ) initWithColorPixelFormat: (MTLPixelFormat) colorPixelFormat;

-(void) onDrawableSizeChange: (CGSize) drawableSize;
-(void) onDraw;

@end
