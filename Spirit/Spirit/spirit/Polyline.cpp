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
    
}

void Polyline::close() {
    _closed = true;
    if(!_points.empty()) {
        _points.push_back(_points[0]);
    }
}

}
