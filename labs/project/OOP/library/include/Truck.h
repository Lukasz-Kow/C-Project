//
// Created by Mateusz Pryl on 01/12/2022.
//

#ifndef OOPPROJECT_TRUCK_H
#define OOPPROJECT_TRUCK_H


#include "Container.h"
#include "Loadable.h"


class Truck: public Loadable {


private:
    Container trailer[2];

};


#endif //OOPPROJECT_TRUCK_H
