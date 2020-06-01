//
//  SPRTCore.h
//  Spirit
//
//  Created by Vanush Grigoryan on 4/27/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SPRTRenderingContext;

NS_ASSUME_NONNULL_BEGIN

@interface SPRTCore : NSObject

+(void) tick: (float) dt;
+(void) render: (SPRTRenderingContext*) rc;

@end

NS_ASSUME_NONNULL_END
