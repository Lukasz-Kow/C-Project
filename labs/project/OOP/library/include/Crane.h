//
// Created by Mateusz Pryl on 25/11/2022.
//

#ifndef OOPPROJECT_CRANE_H
#define OOPPROJECT_CRANE_H

#include "ContainerStack.h"
const int POSITION_PARKED = -1;
const int POSITION_OVER_STACK_OF_CONTAINERS = 0;
const int POSITION_OVER_THE_TRAILER = -2;
const unsigned MAX_STACKS = 5;

class Crane {

    ContainerStack storage[MAX_STACKS];

    int position = POSITION_PARKED;

    Container container;

public:
    bool isParked();

    bool isLoaded();

    bool isUnloaded();

    bool isWaitingEmpty();

    bool isWaitingFull();

    void park();

    void load(Container container);

    Container unload();

    void forward(int numSteps);

    void backward(int numSteps);

    void pickUp();

    void putDown();

    int getPosition();

    Container& getContainer();

    ContainerStack& stackAt(int position);

    bool canPutDown();
};



#endif //OOPPROJECT_CRANE_H
