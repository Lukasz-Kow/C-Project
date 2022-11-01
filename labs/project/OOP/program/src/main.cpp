#include <iostream>
#include "Container.h"

using namespace std;

void display(Container c){
    cout<<"Container Number: "<<c.getNumber()<<endl;
    cout<<"Container Tare Weight: "<<c.getTare()<<endl;
    cout<<"Container Max Weight: "<<c.getMaxWeight()<<endl;
    cout<<"Container Strength: "<<c.getStrength()<<endl;
}

void displayCargo(Container& c) {
    cout<<"Container Cargo: "<<c.getCargo()<<endl;
}

void testLocalObject () {
    Container testContainer;
    testContainer.setCargo(100);
    testContainer.setMaxWeight(1000);
    testContainer.setStrength(200);
    testContainer.setTare(400);

    display(testContainer);
    displayCargo(testContainer);
}

// task 4
void loadAndSend (Container& c, double goods) {
    displayCargo(c);
    c.loadCargo(goods);
    displayCargo(c);
}

// task 5
Container* prepare(int number, double goods) {
    // this line is rather correct
    Container* object = new Container(number);

    // loading the initial quantity of goods into the container
    object->setCargo(goods);

    return object;
}

// task 6
void display(Container* p) {
    cout<<"Container Number: "<<p->getNumber()<<endl;
    cout<<"Container Tare Weight: "<<p->getTare()<<endl;
    cout<<"Container Max Weight: "<<p->getMaxWeight()<<endl;
    cout<<"Container Strength: "<<p->getStrength()<<endl;
    cout<<"Container cargo: "<<p->getCargo()<<endl;
}


// task 7
void testDynamicObject() {
    Container* p = prepare(2, 100);
    display(p);
    delete p;
}




int main() {
    // testLocalObject();
    Container test(1);
    test.setCargo(200);

    testDynamicObject();

//    loadAndSend(test, 100);

    return 0;
}
