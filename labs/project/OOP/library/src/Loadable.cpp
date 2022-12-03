//
// Created by Mateusz Pryl on 01/12/2022.
//

#include "Loadable.h"

unsigned Loadable::getCapacity() {

}

unsigned Loadable::getSize() {

}

Container& Loadable::at(int number) {

}

void Loadable::take(Container aContainer) {

}

Container Loadable::give() {

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


