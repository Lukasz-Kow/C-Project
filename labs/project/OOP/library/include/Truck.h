//
// Created by Mateusz Pryl on 01/12/2022.
//

#ifndef OOPPROJECT_TRUCK_H
#define OOPPROJECT_TRUCK_H


#include "Container.h"
#include "Loadable.h"

const int TRAILER_CAPACITY = 2;

class Truck: public Loadable {


private:
    Container trailer[TRAILER_CAPACITY];


public:
    virtual unsigned getCapacity() override;
    virtual unsigned getSize() override;
    virtual Container& at(int position) override;
    virtual void take(Container aContainer) override;
    virtual Container give() override;
};


#endif //OOPPROJECT_TRUCK_H
