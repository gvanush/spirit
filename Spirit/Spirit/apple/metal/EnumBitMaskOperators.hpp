//
//  EnumBitMaskOperators.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/12/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include <type_traits>

namespace apple::metal {

template<typename ET>
inline constexpr bool IsEnumBitmasklOperatorsEnabled = false;

template<typename ET>
std::enable_if_t<(std::is_enum_v<ET> && IsEnumBitmasklOperatorsEnabled<ET>), ET>
operator& (ET lhs, ET rhs) {
    using UT = std::underlying_type_t<ET>;
    return static_cast<ET> (static_cast<UT>(lhs) & static_cast<UT>(rhs));
}

template<typename ET>
std::enable_if_t<(std::is_enum_v<ET> && IsEnumBitmasklOperatorsEnabled<ET>), ET>
operator| (ET lhs, ET rhs) {
    using UT = std::underlying_type_t<ET>;
    return static_cast<ET> (static_cast<UT>(lhs) | static_cast<UT>(rhs));
}

template<typename ET>
std::enable_if_t<(std::is_enum_v<ET> && IsEnumBitmasklOperatorsEnabled<ET>), ET>
operator^ (ET lhs, ET rhs) {
    using UT = std::underlying_type_t<ET>;
    return static_cast<ET> (static_cast<UT>(lhs) ^ static_cast<UT>(rhs));
}

template<typename ET>
std::enable_if_t<(std::is_enum_v<ET> && IsEnumBitmasklOperatorsEnabled<ET>), ET>
operator~ (ET rhs) {
    using UT = std::underlying_type_t<ET>;
    return static_cast<ET> (~static_cast<UT>(rhs));
}

template<typename ET>
std::enable_if_t<(std::is_enum_v<ET> && IsEnumBitmasklOperatorsEnabled<ET>)>
operator|= (ET& lhs, ET rhs) {
    using UT = std::underlying_type_t<ET>;
    lhs = static_cast<ET> (static_cast<UT>(lhs) | static_cast<UT>(rhs));
}

template<typename ET>
std::enable_if_t<(std::is_enum_v<ET> && IsEnumBitmasklOperatorsEnabled<ET>)>
operator&= (ET& lhs, ET rhs) {
    using UT = std::underlying_type_t<ET>;
    lhs = static_cast<ET> (static_cast<UT>(lhs) & static_cast<UT>(rhs));
}

template<typename ET>
std::enable_if_t<(std::is_enum_v<ET> && IsEnumBitmasklOperatorsEnabled<ET>)>
operator^= (ET& lhs, ET rhs) {
    using UT = std::underlying_type_t<ET>;
    lhs = static_cast<ET> (static_cast<UT>(lhs) ^ static_cast<UT>(rhs));
}

}
