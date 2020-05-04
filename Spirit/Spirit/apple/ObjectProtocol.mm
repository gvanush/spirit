//
//  ObjectProtocol.mm
//  Spirit
//
//  Created by Vanush Grigoryan on 5/2/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include "ObjectProtocol.h"

namespace apple {

bool ObjectProtocolRef::isEqual(const Ref& ref) const {
    return [obj<id<NSObject>>() isEqual: ref.obj<id>()];
}

}
