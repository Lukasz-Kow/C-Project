//
// Created by Mateusz Pryl on 25/11/2022.
//

#ifndef OOPPROJECT_CRANE_H
#define OOPPROJECT_CRANE_H

#include "ContainerStack.h"
#include "Loadable.h"
#include "LoadStrategy.h"
#include "CheckFreePlaceStrategy.h"

using namespace std;


const int POSITION_PARKED = -1;
const int POSITION_OVER_STACK_OF_CONTAINERS = 0;
const int POSITION_OVER_THE_TRAILER = -2;
const unsigned MAX_STACKS = 5;

class Crane {

    ContainerStack storage[MAX_STACKS];

    int position = POSITION_PARKED;

    Container container;

    shared_ptr<LoadStrategy> strategy;



public:
    LoadStrategy loadStrategy;

    bool isParked();

    bool isLoaded();

    bool isUnloaded();

    bool isWaitingEmpty();

    bool isWaitingFull();

    void park();

    void loadFrom(Loadable& truck);

    void unloadOnto(Loadable& truck);

    void forward(int numSteps);

    void backward(int numSteps);

    void pickUp();

    void putDown();

    int getPosition();

    Container& getContainer();

    ContainerStack& stackAt(int position);

    Crane(shared_ptr<LoadStrategy> aStrategy);

    Crane()=default;

    void changeStrategy(shared_ptr<LoadStrategy> aStrategy);

    bool canPutDown(Container &container, int row);

};



#endif //OOPPROJECT_CRANE_H
