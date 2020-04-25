//
//  Equatable.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 4/25/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "Equatable.h"

namespace apple::core {

bool EquatableRef::isEqual(const EquatableRef& eqRef) const {
    return [ptr<NSObject>() isEqual: eqRef.ptr<NSObject>()];
}

}
