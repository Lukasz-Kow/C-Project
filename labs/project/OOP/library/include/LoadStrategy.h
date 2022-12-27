//
// Created by student on 12/27/22.
//

#ifndef OOPPROJECT_LOADSTRATEGY_H
#define OOPPROJECT_LOADSTRATEGY_H

#include "Loadable.h"
#include "Container.h"

class LoadStrategy{
public:
    virtual bool canPutDown(Container& container, Loadable& loadable);

};


#endif //OOPPROJECT_LOADSTRATEGY_H
