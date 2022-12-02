//
// Created by Mateusz Pryl on 01/12/2022.
//

#include "Loadable.h"

int Loadable::getCapacity() {

}

int Loadable::getSize() {}



Container Loadable::at(int number) {

}

void Loadable::take() {

}

void Loadable::give() {

}

bool Loadable::canTake() {
    if (getCapacity() > getSize()) {
        return true;
    }
    return false;
}

bool Loadable::canGive() {
    if (getSize() >= 1) {
        return true;
    }
    return false;

}


