//
//  ResourceOptions.h
//  Spirit
//
//  Created by Vanush Grigoryan on 5/12/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include "../../util/EnumBitMaskOperators.hpp"

#include <objc/NSObjCRuntime.h>
#include <os/availability.h>

#ifdef __OBJC__

#import <Metal/MTLResource.h>

#endif

namespace apple::metal {

enum class CPUCacheMode: NSUInteger {
    DefaultCache = 0,
    WriteCombined = 1,
} API_AVAILABLE(macos(10.11), ios(8.0));

enum class StorageMode: NSUInteger {
    Shared  = 0,
    Managed API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios) = 1,
    Private = 2,
    Memoryless API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(macos, macCatalyst) = 3,
} API_AVAILABLE(macos(10.11), ios(9.0));

enum class HazardTrackingMode: NSUInteger {
    Default = 0,
    Untracked = 1,
    Tracked = 2,
} API_AVAILABLE(macos(10.15), ios(13.0));

constexpr NSUInteger ResourceCPUCacheModeShift = 0;
constexpr NSUInteger ResourceCPUCacheModeMask = (0xfUL << ResourceCPUCacheModeShift);

constexpr NSUInteger ResourceStorageModeShift = 4;
constexpr NSUInteger ResourceStorageModeMask = (0xfUL << ResourceStorageModeShift);

constexpr NSUInteger ResourceHazardTrackingModeShift = 8;
constexpr NSUInteger ResourceHazardTrackingModeMask = (0x3UL << ResourceHazardTrackingModeShift);

enum class ResourceOptions: NSUInteger
{
    CPUCacheModeDefaultCache  = static_cast<std::underlying_type_t<ResourceOptions>>(CPUCacheMode::DefaultCache)  << ResourceCPUCacheModeShift,
    CPUCacheModeWriteCombined = static_cast<std::underlying_type_t<ResourceOptions>>(CPUCacheMode::WriteCombined) << ResourceCPUCacheModeShift,

    StorageModeShared     API_AVAILABLE(macos(10.11), ios(9.0))  = static_cast<std::underlying_type_t<ResourceOptions>>(StorageMode::Shared)     << ResourceStorageModeShift,
    StorageModeManaged    API_AVAILABLE(macos(10.11), macCatalyst(13.0)) API_UNAVAILABLE(ios)   = static_cast<std::underlying_type_t<ResourceOptions>>(StorageMode::Managed)    << ResourceStorageModeShift,
    StorageModePrivate    API_AVAILABLE(macos(10.11), ios(9.0))  = static_cast<std::underlying_type_t<ResourceOptions>>(StorageMode::Private)    << ResourceStorageModeShift,
    StorageModeMemoryless API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(macos, macCatalyst) = static_cast<std::underlying_type_t<ResourceOptions>>(StorageMode::Memoryless) << ResourceStorageModeShift,
    
    HazardTrackingModeDefault API_AVAILABLE(macos(10.13), ios(10.0)) = static_cast<std::underlying_type_t<ResourceOptions>>(HazardTrackingMode::Default) << ResourceHazardTrackingModeShift,
    HazardTrackingModeUntracked API_AVAILABLE(macos(10.13), ios(10.0)) = static_cast<std::underlying_type_t<ResourceOptions>>(HazardTrackingMode::Untracked) << ResourceHazardTrackingModeShift,
    HazardTrackingModeTracked API_AVAILABLE(macos(10.15), ios(13.0)) = static_cast<std::underlying_type_t<ResourceOptions>>(HazardTrackingMode::Tracked) << ResourceHazardTrackingModeShift,
    
    // Deprecated spellings
    OptionCPUCacheModeDefault       = CPUCacheModeDefaultCache,
    OptionCPUCacheModeWriteCombined = CPUCacheModeWriteCombined,
} API_AVAILABLE(macos(10.11), ios(8.0));

using namespace util::enum_bitmask_operators;

#ifdef __OBJC__

template <typename T>
inline T to(ResourceOptions resourceOptions) {
    return static_cast<T>(resourceOptions);
}

template <>
inline MTLResourceOptions to(ResourceOptions resourceOptions) {
    return MTLResourceOptions { std::underlying_type_t<ResourceOptions>(resourceOptions) };
}

#endif

}

namespace util::enum_bitmask_operators {

template<>
inline constexpr bool IsEnumBitmasklOperatorsEnabled<apple::metal::ResourceOptions> = true;

}

