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

Container Crane::unload() {
    if (isLoaded())
    {
        Container temp = container;
        container = Container();
        return temp;
    }
}

void Crane::forward(int numSteps) {
    if (position+numSteps<=(MAX_STACKS-1) && numSteps > 0 ) {
        position+=numSteps;
    }
}

void Crane::backward(int numSteps) {
    if (position - numSteps >= POSITION_OVER_THE_TRAILER && numSteps > 0) {
        position -= numSteps;
    }
}

void Crane::pickUp() {
    if (isWaitingEmpty() && storage[position].getSize()) {
        container = storage[position].give();
    }
}

void Crane::putDown() {
    if (isWaitingFull() && storage[position].getSize() + 1 <= storage[position].getCapacity()) {
        storage[position].take(container);
        container = Container();
    }
}

int Crane::getPosition() {
    return position;
}



