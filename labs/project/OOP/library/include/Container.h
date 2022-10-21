//
// Created by Mateusz Pryl on 21/10/2022.
//

#ifndef CONTAINER_H
#define CONTAINER_H

#include <stdlib.h>

class Container {
public:

    Container(int number);
    Container();

    int maxCargo();
    int grossWeight();

private:

    int number;
    double tareWeight;
    double maxWeight;
    double strength;
    double cargo;

};


#endif //CONTAINER_H
