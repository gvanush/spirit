//
//  ResourceOptions.h
//  Spirit
//
//  Created by Vanush Grigoryan on 5/12/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "EnumBitMaskOperators.hpp"

#include <objc/NSObjCRuntime.h>
#include <os/availability.h>

namespace apple::metal {

enum class CPUCacheMode: NSUInteger {
    defaultCache = 0,
    writeCombined = 1,
} API_AVAILABLE(macos(10.11), ios(8.0));

enum class StorageMode: NSUInteger {
    shared  = 0,
    managed API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 1,
    private_ = 2,
    memoryless API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(macos, macCatalyst) = 3,
} API_AVAILABLE(macos(10.11), ios(9.0));

enum class HazardTrackingMode: NSUInteger {
    default_ = 0,
    untracked = 1,
    tracked = 2,
} API_AVAILABLE(macos(10.15), ios(13.0));

constexpr NSUInteger kResourceCPUCacheModeShift = 0;
constexpr NSUInteger kResourceCPUCacheModeMask = (0xfUL << kResourceCPUCacheModeShift);

constexpr NSUInteger kResourceStorageModeShift = 4;
constexpr NSUInteger kResourceStorageModeMask = (0xfUL << kResourceStorageModeShift);

constexpr NSUInteger kResourceHazardTrackingModeShift = 8;
constexpr NSUInteger kResourceHazardTrackingModeMask = (0x3UL << kResourceHazardTrackingModeShift);

enum class ResourceOptions: NSUInteger {
    cpuCacheModeDefaultCache  = static_cast<std::underlying_type_t<ResourceOptions>>(CPUCacheMode::defaultCache)  << kResourceCPUCacheModeShift,
    cpuCacheModeWriteCombined = static_cast<std::underlying_type_t<ResourceOptions>>(CPUCacheMode::writeCombined) << kResourceCPUCacheModeShift,

    storageModeShared     API_AVAILABLE(macos(10.11), ios(9.0))  = static_cast<std::underlying_type_t<ResourceOptions>>(StorageMode::shared)     << kResourceStorageModeShift,
    storageModeManaged    API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios)   = static_cast<std::underlying_type_t<ResourceOptions>>(StorageMode::managed)    << kResourceStorageModeShift,
    storageModePrivate    API_AVAILABLE(macos(10.11), ios(9.0))  = static_cast<std::underlying_type_t<ResourceOptions>>(StorageMode::private_)    << kResourceStorageModeShift,
    storageModeMemoryless API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(macos, macCatalyst) = static_cast<std::underlying_type_t<ResourceOptions>>(StorageMode::memoryless) << kResourceStorageModeShift,
    
    hazardTrackingModeDefault API_AVAILABLE(macos(10.13), ios(10.0)) = static_cast<std::underlying_type_t<ResourceOptions>>(HazardTrackingMode::default_) << kResourceHazardTrackingModeShift,
    hazardTrackingModeUntracked API_AVAILABLE(macos(10.13), ios(10.0)) = static_cast<std::underlying_type_t<ResourceOptions>>(HazardTrackingMode::untracked) << kResourceHazardTrackingModeShift,
    hazardTrackingModeTracked API_AVAILABLE(macos(10.15), ios(13.0)) = static_cast<std::underlying_type_t<ResourceOptions>>(HazardTrackingMode::tracked) << kResourceHazardTrackingModeShift,
    
    // Deprecated spellings
    OptionCPUCacheModeDefault       = cpuCacheModeDefaultCache,
    OptionCPUCacheModeWriteCombined = cpuCacheModeWriteCombined,
} API_AVAILABLE(macos(10.11), ios(8.0));

template<>
inline constexpr bool IsEnumBitmasklOperatorsEnabled<metal::ResourceOptions> = true;

}


#ifdef __OBJC__

#include "../../util/TypeCast.hpp"

#import <Metal/MTLResource.h>

template <>
inline MTLResourceOptions to(apple::metal::ResourceOptions resourceOptions) {
    return MTLResourceOptions { std::underlying_type_t<apple::metal::ResourceOptions>(resourceOptions) };
}

#endif
