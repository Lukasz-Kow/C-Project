//
// Created by Mateusz Pryl on 21/10/2022.
//

#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <stdlib.h>

class Container {
public:

    Container();
    Container(int number);

    int maxCargo();

    int grossWeight();

    int getCargo();

    void setCargo(int cargo);

    int getNumber();

    double getTare();

    void setTare(double tareWeight);

    double getMaxWeight();

    void setMaxWeight(double maxWeight);

    double getStrength();

    void setStrength(double strength);

    double getGrossWeight();

    double getNetWeight();

    void loadCargo(double amount);

    void unloadCargo(double amount);

private:

    int number;
    double tareWeight;
    double maxWeight;
    double strength;
    double cargo;
    double goods;
};


#endif //CONTAINER_H
