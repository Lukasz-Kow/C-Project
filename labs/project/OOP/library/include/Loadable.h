//
// Created by Mateusz Pryl on 01/12/2022.
//

#ifndef OOPPROJECT_LOADABLE_H
#define OOPPROJECT_LOADABLE_H

#include "Container.h"

class Loadable {


public:

    virtual int getCapacity();
    virtual int getSize();
    virtual Container at(int number);
    virtual void take();
    virtual void give();

    bool canTake();
    bool canGive();
};



#endif //OOPPROJECT_LOADABLE_H
