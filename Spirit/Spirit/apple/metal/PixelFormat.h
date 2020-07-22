//
//  PixelFormat.h
//  Spirit
//
//  Created by Vanush Grigoryan on 5/2/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include <objc/NSObjCRuntime.h>
#include <os/availability.h>

namespace apple::metal {

enum class PixelFormat: NSUInteger
{
    invalid = 0,

    /* Normal 8 bit formats */
    
    a8Unorm      = 1,
    
    r8Unorm                            = 10,
    r8Unorm_sRGB API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 11,

    r8Snorm      = 12,
    r8Uint       = 13,
    r8Sint       = 14,
    
    /* Normal 16 bit formats */

    r16Unorm     = 20,
    r16Snorm     = 22,
    r16Uint      = 23,
    r16Sint      = 24,
    r16Float     = 25,

    rg8Unorm                            = 30,
    rg8Unorm_sRGB API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 31,
    rg8Snorm                            = 32,
    rg8Uint                             = 33,
    rg8Sint                             = 34,

    /* Packed 16 bit formats */
    
    b5G6R5Unorm API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 40,
    a1BGR5Unorm API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 41,
    aBGR4Unorm  API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 42,
    bgr5A1Unorm API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 43,

    /* Normal 32 bit formats */

    r32Uint  = 53,
    r32Sint  = 54,
    r32Float = 55,

    rg16Unorm  = 60,
    rg16Snorm  = 62,
    rg16Uint   = 63,
    rg16Sint   = 64,
    rg16Float  = 65,

    rgba8Unorm      = 70,
    rgba8Unorm_sRGB = 71,
    rgba8Snorm      = 72,
    rgba8Uint       = 73,
    rgba8Sint       = 74,
    
    bgra8Unorm      = 80,
    bgra8Unorm_sRGB = 81,

    /* Packed 32 bit formats */

    rgb10A2Unorm = 90,
    rgb10A2Uint  = 91,

    rg11B10Float = 92,
    rgb9E5Float = 93,

    bgr10A2Unorm  API_AVAILABLE(macos(10.13), ios(11.0)) = 94,

    bgr10_XR      API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(macos, macCatalyst) = 554,
    bgr10_XR_sRGB API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(macos, macCatalyst) = 555,

    /* Normal 64 bit formats */

    rg32Uint  = 103,
    rg32Sint  = 104,
    rg32Float = 105,

    rgba16Unorm  = 110,
    rgba16Snorm  = 112,
    rgba16Uint   = 113,
    rgba16Sint   = 114,
    rgba16Float  = 115,

    bgra10_XR      API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(macos, macCatalyst) = 552,
    bgra10_XR_sRGB API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(macos, macCatalyst) = 553,

    /* Normal 128 bit formats */

    rgba32Uint  = 123,
    rgba32Sint  = 124,
    rgba32Float = 125,

    /* Compressed formats. */

    /* S3TC/DXT */
    bc1_RGBA              API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 130,
    bc1_RGBA_sRGB         API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 131,
    bc2_RGBA              API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 132,
    bc2_RGBA_sRGB         API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 133,
    bc3_RGBA              API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 134,
    bc3_RGBA_sRGB         API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 135,

    /* RGTC */
    bc4_RUnorm            API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 140,
    bc4_RSnorm            API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 141,
    bc5_RGUnorm           API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 142,
    bc5_RGSnorm           API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 143,

    /* BPTC */
    bc6H_RGBFloat         API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 150,
    bc6H_RGBUfloat        API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 151,
    bc7_RGBAUnorm         API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 152,
    bc7_RGBAUnorm_sRGB    API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 153,

    /* PVRTC */
    pvrtc_RGB_2BPP        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 160,
    pvrtc_RGB_2BPP_sRGB   API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 161,
    pvrtc_RGB_4BPP        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 162,
    pvrtc_RGB_4BPP_sRGB   API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 163,
    pvrtc_RGBA_2BPP       API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 164,
    pvrtc_RGBA_2BPP_sRGB  API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 165,
    pvrtc_RGBA_4BPP       API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 166,
    pvrtc_RGBA_4BPP_sRGB  API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 167,

    /* ETC2 */
    eac_R11Unorm          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 170,
    eac_R11Snorm          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 172,
    eac_RG11Unorm         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 174,
    eac_RG11Snorm         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 176,
    eac_RGBA8             API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 178,
    eac_RGBA8_sRGB        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 179,

    etc2_RGB8             API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 180,
    etc2_RGB8_sRGB        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 181,
    etc2_RGB8A1           API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 182,
    etc2_RGB8A1_sRGB      API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 183,

    /* ASTC */
    astc_4x4_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 186,
    astc_5x4_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 187,
    astc_5x5_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 188,
    astc_6x5_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 189,
    astc_6x6_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 190,
    astc_8x5_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 192,
    astc_8x6_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 193,
    astc_8x8_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 194,
    astc_10x5_sRGB        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 195,
    astc_10x6_sRGB        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 196,
    astc_10x8_sRGB        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 197,
    astc_10x10_sRGB       API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 198,
    astc_12x10_sRGB       API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 199,
    astc_12x12_sRGB       API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 200,

    astc_4x4_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 204,
    astc_5x4_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 205,
    astc_5x5_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 206,
    astc_6x5_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 207,
    astc_6x6_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 208,
    astc_8x5_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 210,
    astc_8x6_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 211,
    astc_8x8_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 212,
    astc_10x5_LDR         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 213,
    astc_10x6_LDR         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 214,
    astc_10x8_LDR         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 215,
    astc_10x10_LDR        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 216,
    astc_12x10_LDR        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 217,
    astc_12x12_LDR        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 218,
    
    
    /*!
     @constant GBGR422
     @abstract A pixel format where the red and green channels are subsampled horizontally.  Two pixels are stored in 32 bits, with shared red and blue values, and unique green values.
     @discussion This format is equivalent to YUY2, YUYV, yuvs, or GL_RGB_422_APPLE/GL_UNSIGNED_SHORT_8_8_REV_APPLE.   The component order, from lowest addressed byte to highest, is Y0, Cb, Y1, Cr.  There is no implicit colorspace conversion from YUV to RGB, the shader will receive (Cr, Y, Cb, 1).  422 textures must have a width that is a multiple of 2, and can only be used for 2D non-mipmap textures.  When sampling, ClampToEdge is the only usable wrap mode.
     */
    gbgr422 = 240,

    /*!
     @constant BGRG422
     @abstract A pixel format where the red and green channels are subsampled horizontally.  Two pixels are stored in 32 bits, with shared red and blue values, and unique green values.
     @discussion This format is equivalent to UYVY, 2vuy, or GL_RGB_422_APPLE/GL_UNSIGNED_SHORT_8_8_APPLE. The component order, from lowest addressed byte to highest, is Cb, Y0, Cr, Y1.  There is no implicit colorspace conversion from YUV to RGB, the shader will receive (Cr, Y, Cb, 1).  422 textures must have a width that is a multiple of 2, and can only be used for 2D non-mipmap textures.  When sampling, ClampToEdge is the only usable wrap mode.
     */
    bgrg422 = 241,

    /* Depth */

    depth16Unorm          API_AVAILABLE(macos(10.12), ios(13.0)) = 250,
    depth32Float  = 252,

    /* Stencil */

    stencil8        = 253,

    /* Depth Stencil */
    
    depth24Unorm_Stencil8  API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 255,
    depth32Float_Stencil8  API_AVAILABLE(macos(10.11), ios(9.0)) = 260,

    x32_Stencil8  API_AVAILABLE(macos(10.12), ios(10.0)) = 261,
    x24_Stencil8  API_AVAILABLE(macos(10.12), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 262,

} API_AVAILABLE(macos(10.11), ios(8.0));

}

#ifdef __OBJC__

#include "../../util/TypeCast.hpp"

#import <Metal/MTLPixelFormat.h>

template <>
inline MTLPixelFormat to(apple::metal::PixelFormat pixelFormat) {
    return MTLPixelFormat { std::underlying_type_t<apple::metal::PixelFormat>(pixelFormat) };
}

#endif
