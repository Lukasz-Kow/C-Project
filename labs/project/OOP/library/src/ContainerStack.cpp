
#include "ContainerStack.h"
#include "Container.h"

int ContainerStack::getCapacity() { //how many can we put on the stack
    int getSize = this->getSize();
    if(getSize >= MAX_HEIGHT) {
        return 0;
    } else {
        int result = MAX_HEIGHT-getSize;
        return result;
    }
}

int ContainerStack::getSize() { //How many containers are on the stack
    return containers.size();
}

Container& ContainerStack::at(int height) {
    return containers[height-1];
}

void ContainerStack::take(Container aContainer) {
    containers.push_back(aContainer);
}

Container ContainerStack::give(){
    containers.pop_back();
}
