//
//  Semaphore.hpp
//  Spirit
//
//  Created by Vanush Grigoryan on 5/24/20.
//  Copyright © 2020 Vanush Grigoryan. All rights reserved.
//

#include <mutex>
#include <condition_variable>

namespace spirit::_internal {

class Semaphore {
public:
    Semaphore (int count)
    : _count(count) {
    }

    inline void notify() {
        std::unique_lock<std::mutex> lock(_mtx);
        _count++;
        _cv.notify_one();
    }

    inline void wait() {
        std::unique_lock<std::mutex> lock(_mtx);
        _cv.wait(lock, [this] () { return _count > 0; });
        _count--;
    }

private:
    std::mutex _mtx;
    std::condition_variable _cv;
    int _count;
};

}
