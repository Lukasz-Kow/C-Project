//
// Created by Mateusz Pryl on 21/10/2022.
//

#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <stdlib.h>

class Container {
public:

    Container(int number);
    Container();

    int maxCargo();
    int grossWeight();

    // TODO: Add getters and setters for all properties

    void set_cargo(int c){
        cargo = c;
    }
    int get_cargo(){
        return cargo;
    }
private:

    int number;
    double tareWeight;
    double maxWeight;
    double strength;
    double cargo;
    double goods;
};


#endif //CONTAINER_H
