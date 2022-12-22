
#include "ContainerStack.h"
#include "Container.h"

unsigned ContainerStack::getCapacity() { //how many can we put on the stack
    int getSize = this->getSize();
    if(getSize >= MAX_HEIGHT) {
        return 0;
    } else {
        int result = MAX_HEIGHT-getSize;
        return result;
    }
}

unsigned ContainerStack::getSize() { //How many containers are on the stack
    return containers.size();
}

Container& ContainerStack::at(int height) {
    if (height > getSize()) {
        Container containerSkeleton;
        return containerSkeleton;
    } else {
        return containers[height-1];
    }
}

void ContainerStack::take(Container aContainer) {
    int capacity = getCapacity();
    std::cout << capacity;
    if (capacity == 0) {
        std::cout << "Can not load more containers" << std::endl;
    } else {
        containers.push_back(aContainer);
    }
}

Container ContainerStack::give() {
    if (getSize() == 0) {
        std::cout << "Can't remove a container from an empty stack";
    } else {
        containers.pop_back();
    }
}
