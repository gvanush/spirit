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

#ifdef __OBJC__

#import <Metal/MTLPixelFormat.h>

#endif

namespace apple::metal {

enum class PixelFormat: NSUInteger
{
    Invalid = 0,

    /* Normal 8 bit formats */
    
    A8Unorm      = 1,
    
    R8Unorm                            = 10,
    R8Unorm_sRGB API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 11,

    R8Snorm      = 12,
    R8Uint       = 13,
    R8Sint       = 14,
    
    /* Normal 16 bit formats */

    R16Unorm     = 20,
    R16Snorm     = 22,
    R16Uint      = 23,
    R16Sint      = 24,
    R16Float     = 25,

    RG8Unorm                            = 30,
    RG8Unorm_sRGB API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 31,
    RG8Snorm                            = 32,
    RG8Uint                             = 33,
    RG8Sint                             = 34,

    /* Packed 16 bit formats */
    
    B5G6R5Unorm API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 40,
    A1BGR5Unorm API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 41,
    ABGR4Unorm  API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 42,
    BGR5A1Unorm API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 43,

    /* Normal 32 bit formats */

    R32Uint  = 53,
    R32Sint  = 54,
    R32Float = 55,

    RG16Unorm  = 60,
    RG16Snorm  = 62,
    RG16Uint   = 63,
    RG16Sint   = 64,
    RG16Float  = 65,

    RGBA8Unorm      = 70,
    RGBA8Unorm_sRGB = 71,
    RGBA8Snorm      = 72,
    RGBA8Uint       = 73,
    RGBA8Sint       = 74,
    
    BGRA8Unorm      = 80,
    BGRA8Unorm_sRGB = 81,

    /* Packed 32 bit formats */

    RGB10A2Unorm = 90,
    RGB10A2Uint  = 91,

    RG11B10Float = 92,
    RGB9E5Float = 93,

    BGR10A2Unorm  API_AVAILABLE(macos(10.13), ios(11.0)) = 94,

    BGR10_XR      API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(macos, macCatalyst) = 554,
    BGR10_XR_sRGB API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(macos, macCatalyst) = 555,

    /* Normal 64 bit formats */

    RG32Uint  = 103,
    RG32Sint  = 104,
    RG32Float = 105,

    RGBA16Unorm  = 110,
    RGBA16Snorm  = 112,
    RGBA16Uint   = 113,
    RGBA16Sint   = 114,
    RGBA16Float  = 115,

    BGRA10_XR      API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(macos, macCatalyst) = 552,
    BGRA10_XR_sRGB API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(macos, macCatalyst) = 553,

    /* Normal 128 bit formats */

    RGBA32Uint  = 123,
    RGBA32Sint  = 124,
    RGBA32Float = 125,

    /* Compressed formats. */

    /* S3TC/DXT */
    BC1_RGBA              API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 130,
    BC1_RGBA_sRGB         API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 131,
    BC2_RGBA              API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 132,
    BC2_RGBA_sRGB         API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 133,
    BC3_RGBA              API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 134,
    BC3_RGBA_sRGB         API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 135,

    /* RGTC */
    BC4_RUnorm            API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 140,
    BC4_RSnorm            API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 141,
    BC5_RGUnorm           API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 142,
    BC5_RGSnorm           API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 143,

    /* BPTC */
    BC6H_RGBFloat         API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 150,
    BC6H_RGBUfloat        API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 151,
    BC7_RGBAUnorm         API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 152,
    BC7_RGBAUnorm_sRGB    API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 153,

    /* PVRTC */
    PVRTC_RGB_2BPP        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 160,
    PVRTC_RGB_2BPP_sRGB   API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 161,
    PVRTC_RGB_4BPP        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 162,
    PVRTC_RGB_4BPP_sRGB   API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 163,
    PVRTC_RGBA_2BPP       API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 164,
    PVRTC_RGBA_2BPP_sRGB  API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 165,
    PVRTC_RGBA_4BPP       API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 166,
    PVRTC_RGBA_4BPP_sRGB  API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 167,

    /* ETC2 */
    EAC_R11Unorm          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 170,
    EAC_R11Snorm          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 172,
    EAC_RG11Unorm         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 174,
    EAC_RG11Snorm         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 176,
    EAC_RGBA8             API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 178,
    EAC_RGBA8_sRGB        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 179,

    ETC2_RGB8             API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 180,
    ETC2_RGB8_sRGB        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 181,
    ETC2_RGB8A1           API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 182,
    ETC2_RGB8A1_sRGB      API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 183,

    /* ASTC */
    ASTC_4x4_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 186,
    ASTC_5x4_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 187,
    ASTC_5x5_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 188,
    ASTC_6x5_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 189,
    ASTC_6x6_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 190,
    ASTC_8x5_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 192,
    ASTC_8x6_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 193,
    ASTC_8x8_sRGB         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 194,
    ASTC_10x5_sRGB        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 195,
    ASTC_10x6_sRGB        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 196,
    ASTC_10x8_sRGB        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 197,
    ASTC_10x10_sRGB       API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 198,
    ASTC_12x10_sRGB       API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 199,
    ASTC_12x12_sRGB       API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 200,

    ASTC_4x4_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 204,
    ASTC_5x4_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 205,
    ASTC_5x5_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 206,
    ASTC_6x5_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 207,
    ASTC_6x6_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 208,
    ASTC_8x5_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 210,
    ASTC_8x6_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 211,
    ASTC_8x8_LDR          API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 212,
    ASTC_10x5_LDR         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 213,
    ASTC_10x6_LDR         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 214,
    ASTC_10x8_LDR         API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 215,
    ASTC_10x10_LDR        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 216,
    ASTC_12x10_LDR        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 217,
    ASTC_12x12_LDR        API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) = 218,
    
    
    /*!
     @constant GBGR422
     @abstract A pixel format where the red and green channels are subsampled horizontally.  Two pixels are stored in 32 bits, with shared red and blue values, and unique green values.
     @discussion This format is equivalent to YUY2, YUYV, yuvs, or GL_RGB_422_APPLE/GL_UNSIGNED_SHORT_8_8_REV_APPLE.   The component order, from lowest addressed byte to highest, is Y0, Cb, Y1, Cr.  There is no implicit colorspace conversion from YUV to RGB, the shader will receive (Cr, Y, Cb, 1).  422 textures must have a width that is a multiple of 2, and can only be used for 2D non-mipmap textures.  When sampling, ClampToEdge is the only usable wrap mode.
     */
    GBGR422 = 240,

    /*!
     @constant BGRG422
     @abstract A pixel format where the red and green channels are subsampled horizontally.  Two pixels are stored in 32 bits, with shared red and blue values, and unique green values.
     @discussion This format is equivalent to UYVY, 2vuy, or GL_RGB_422_APPLE/GL_UNSIGNED_SHORT_8_8_APPLE. The component order, from lowest addressed byte to highest, is Cb, Y0, Cr, Y1.  There is no implicit colorspace conversion from YUV to RGB, the shader will receive (Cr, Y, Cb, 1).  422 textures must have a width that is a multiple of 2, and can only be used for 2D non-mipmap textures.  When sampling, ClampToEdge is the only usable wrap mode.
     */
    BGRG422 = 241,

    /* Depth */

    Depth16Unorm          API_AVAILABLE(macos(10.12), ios(13.0)) = 250,
    Depth32Float  = 252,

    /* Stencil */

    Stencil8        = 253,

    /* Depth Stencil */
    
    Depth24Unorm_Stencil8  API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 255,
    Depth32Float_Stencil8  API_AVAILABLE(macos(10.11), ios(9.0)) = 260,

    X32_Stencil8  API_AVAILABLE(macos(10.12), ios(10.0)) = 261,
    X24_Stencil8  API_AVAILABLE(macos(10.12), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 262,

} API_AVAILABLE(macos(10.11), ios(8.0));

#ifdef __OBJC__

inline MTLPixelFormat toMTLPixelFormat(PixelFormat pixelFormat) {
    return MTLPixelFormat { std::underlying_type_t<PixelFormat>(pixelFormat) };
}

#endif

}
