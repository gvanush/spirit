//
//  Polyline.cpp
//  Spirit
//
//  Created by Vanush Grigoryan on 8/2/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Polyline.hpp"

namespace spirit {

void Polyline::subdivide() {
    if(_closed) {
        if(_points.size() < 4) {
            return;
        }
    } else {
        if(_points.size() < 3) {
            return;
        }
    }
    
    std::vector<PointType> newPoints;
    for(int i = 0; i < _points.size(); ++i) {
        
        if(_closed) {
            if(i == 0) {
                subdividePoint(_points[i], _points[_points.size() - 2], _points[i + 1], newPoints);
                continue;
            }
            if(i == _points.size() - 1) {
                // close in the end
                newPoints.push_back(newPoints[0]);
                continue;
            }
        } else {
            if(i == 0 || i == _points.size() - 1) {
                newPoints.push_back(_points[i]);
                continue;
            }
        }
        
        subdividePoint(_points[i], _points[i - 1], _points[i + 1], newPoints);
        
    }
    
    _points = std::move(newPoints);
}

void Polyline::close() {
    _closed = true;
    if(!_points.empty()) {
        _points.push_back(_points[0]);
    }
}

void Polyline::subdividePoint(const PointType& point, const PointType& prevPoint, const PointType& nextPoint, std::vector<PointType>& points) {
    points.push_back(prevPoint / 3.f + 2.f * point / 3.f);
    points.push_back(nextPoint / 3.f + 2.f * point / 3.f);
}

}
