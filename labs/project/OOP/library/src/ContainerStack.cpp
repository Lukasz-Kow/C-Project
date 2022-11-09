
#include "ContainerStack.h"
#include "Container.h";

int ContainerStack::getCapacity() {
    return MAX_HEIGHT;
};

int ContainerStack::getSize() {
    return containers.size();
}

Container& ContainerStack::at (int height) {
    return containers[height-1];
}

void ContainerStack::take(Container aContainer) {
    containers.push_back(aContainer);
}

Container ContainerStack::give(){
    containers.pop_back();
}
