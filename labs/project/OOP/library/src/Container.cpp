//
// Created by Mateusz Pryl on 21/10/2022.
//

#include "Container.h"

using namespace std;

Container::Container() {
    this->number = 0;
    this->tareWeight = 0;
    this->maxWeight = 0;
    this->strength = 0;
    this->cargo = 0;
}

Container::Container(int number) {
    this->number = number;
    this->tareWeight = 0;
    this->maxWeight = 0;
    this->strength = 0;
    this->cargo = 0;
}

int Container::maxCargo(){
    return this->maxWeight - this->tareWeight;
}

int Container::grossWeight(){
    return this->tareWeight + this->cargo;
}



