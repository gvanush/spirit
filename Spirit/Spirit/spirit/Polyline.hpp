//
//  Polyline.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 8/2/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#pragma once

#include <vector>
#include <simd/simd.h>
#include <cassert>

namespace spirit {

class Polyline {
public:
    
    using PointType = simd::float2;
    
    inline void addPoint(const simd::float2& p);
    inline const std::vector<simd::float2>& points() const;
    inline void clear();
    
    void close();
    inline bool isClosed() const;
    
    void subdivide();
    
private:
    void subdividePoint(const PointType& point, const PointType& prevPoint, const PointType& nextPoint, std::vector<PointType>& points);
    
    std::vector<PointType> _points;
    bool _closed = false;
};

void Polyline::addPoint(const simd::float2& p) {
    assert(!_closed);
    _points.push_back(p);
}

const std::vector<simd::float2>& Polyline::points() const {
    return _points;
}

void Polyline::clear() {
    _points.clear();
    _closed = false;
}

bool Polyline::isClosed() const {
    return _closed;
}

}
