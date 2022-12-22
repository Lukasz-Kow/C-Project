#ifndef OOPPROJECT_CONTAINERSTACK_H
#define OOPPROJECT_CONTAINERSTACK_H

#endif //OOPPROJECT_CONTAINERSTACK_H
#include <iostream>
#include "Container.h"
#include <vector>
#include "Loadable.h"

class ContainerStack: public Loadable {
public:

    unsigned getCapacity() override;

    unsigned getSize() override;

    Container& at(int height) override;

    void take(Container aContainer) override;

    Container give() override;

private:
    const unsigned MAX_HEIGHT = 10;
    std::vector<Container> containers = {};
};