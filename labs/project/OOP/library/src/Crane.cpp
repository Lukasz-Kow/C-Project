//
// Created by Mateusz Pryl on 25/11/2022.
//

#include "Crane.h"

bool Crane::isParked() {
    if (position == POSITION_PARKED)
    {
        return true;
    }
    return false;
}

bool Crane::isLoaded() {
    if (container.getNumber() && position == POSITION_OVER_THE_TRAILER) {
        return true;
    }
    return false;
}

bool Crane::isUnloaded() {
    if (position == POSITION_OVER_THE_TRAILER  && !container.getNumber()) {
        return true;
    }
    return false;
}

bool Crane::isWaitingEmpty() {
    if (position >= POSITION_OVER_STACK_OF_CONTAINERS && !container.getNumber()) {
        return true;
    }
    return false;
}

bool Crane::isWaitingFull() {
    if (position >= POSITION_OVER_STACK_OF_CONTAINERS && container.getNumber()) {
        return true;
    }
    return false;
}

void Crane::park() {
    if (isUnloaded() || isWaitingEmpty()) {
        position = POSITION_PARKED;
    }
}

void Crane::load(Container container) {
    if (isUnloaded())
    {
        this->container = container;
    }
}


