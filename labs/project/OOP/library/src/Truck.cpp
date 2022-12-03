//
// Created by Mateusz Pryl on 01/12/2022.
//

#include "Truck.h"

unsigned Truck::getCapacity() {
    return TRAILER_CAPACITY;
}

unsigned Truck::getSize() {
    int size = 0;
    for (int i = 0; i < TRAILER_CAPACITY; i++) {
        if (trailer[i].getNumber() > 0) {
            size++;
        }
    }
    return size;
}

Container& Truck::at(int position) {
    return trailer[position - 1];
}

void Truck::take(Container aContainer) {
    if (canTake()) {
        for (int i = 0; i < TRAILER_CAPACITY; i++) {
            if (trailer[i].getNumber() <= 0) {
                trailer[i] = aContainer;
                break;
            }
        }
    } else {
        std::cerr << "Unable to take a container, trailer is full" << std::endl;
    }
}

Container Truck::give() {
    if (canGive()) {
        for (int i = TRAILER_CAPACITY - 1; i <= 0; i--) {
            if (trailer[i].getNumber() > 0) {
                Container temp = trailer[i];
                Container empty = Container();
                trailer[i] = empty;
                return temp;
            }
        }
    } else {
        std::cerr << "Unable to give a Container, trailer is empty" << std::endl;
    }
}