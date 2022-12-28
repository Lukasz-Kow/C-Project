//
// Created by student on 12/27/22.
//

#ifndef OOPPROJECT_CHECKPLACEANDWEIGHTSTRATEGY_H
#define OOPPROJECT_CHECKPLACEANDWEIGHTSTRATEGY_H

#include "Loadable.h"
#include "Container.h"
#include "LoadStrategy.h"

class CheckPlaceAndWeightStrategy : public LoadStrategy{
public:
    bool canPutDown(Container& container, Loadable& loadable) override;

};
#endif //OOPPROJECT_CHECKPLACEANDWEIGHTSTRATEGY_H
