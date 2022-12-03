//
// Created by Mateusz Pryl on 01/12/2022.
//

#ifndef OOPPROJECT_LOADABLE_H
#define OOPPROJECT_LOADABLE_H

#include "Container.h"

class Loadable {


public:

    virtual unsigned getCapacity();
    virtual unsigned getSize();
    virtual Container& at(int number);
    virtual void take(Container aContainer);
    virtual Container give();

    bool canTake();
    bool canGive();
};



#endif //OOPPROJECT_LOADABLE_H
