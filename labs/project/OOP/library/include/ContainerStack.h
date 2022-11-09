//
// Created by student on 11/4/22.
//

#ifndef OOPPROJECT_CONTAINERSTACK_H
#define OOPPROJECT_CONTAINERSTACK_H

#endif //OOPPROJECT_CONTAINERSTACK_H
#include <iostream>
#include "Container.h"
#include <vector>

class ContainerStack {
public:



    int getCapacity();

    int getSize();

    Container& at(int height);

    void take(Container aContainer);

    Container give();

private:
    const unsigned MAX_HEIGHT = 10;
    std::vector<Container> containers = {};
};