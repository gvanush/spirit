//
//  SPRTRenderingContext.h
//  Spirit
//
//  Created by Vanush Grigoryan on 5/25/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

@interface SPRTRenderingContext : NSObject

@property (nonatomic, strong) id<MTLDrawable> drawable;
@property (nonatomic) CGSize drawableSize;
@property (nonatomic, strong) MTLRenderPassDescriptor* renderPassDescriptor;

-(instancetype) init;

+(id<MTLDevice>) device;
+(MTLPixelFormat) colorPixelFormat;
+(NSUInteger) sampleCount;

@end

NS_ASSUME_NONNULL_END



#if defined(__cplusplus)

namespace spirit {

class RenderingContext;

}

@interface SPRTRenderingContext (Cpp)

-(spirit::RenderingContext* _Nonnull) cpp;

@end

#endif
