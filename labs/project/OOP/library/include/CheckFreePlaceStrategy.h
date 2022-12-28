//
// Created by student on 12/27/22.
//

#ifndef OOPPROJECT_CHECKFREEPLACESTRATEGY_H
#define OOPPROJECT_CHECKFREEPLACESTRATEGY_H

#include "Loadable.h"
#include "Container.h"
#include "LoadStrategy.h"

class CheckFreePlaceStrategy : public LoadStrategy {
public:
    bool canPutDown(Container& container, Loadable& loadable) override;
};

#endif //OOPPROJECT_CHECKFREEPLACESTRATEGY_H
