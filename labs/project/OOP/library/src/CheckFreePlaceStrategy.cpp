//
// Created by student on 12/27/22.
//

#include <CheckFreePlaceStrategy.h>

bool CheckFreePlaceStrategy::canPutDown(Container &container, Loadable &loadable) {
    return loadable.canTake();
}

