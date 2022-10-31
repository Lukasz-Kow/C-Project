#include <iostream>
#include "Container.h"

using namespace std;

// TODO: Correct when getters and setters are ready

void displayCargo(Container& c) {
    cout<<"Container Cargo: "<<c.cargo<<endl;
}

void display(Container c){
    cout<<"Container Number: "<<c.number<<endl;
    cout<<"Container Tare Weight: "<<c.tareWeight<<endl;
    cout<<"Container Max Weight: "<<c.maxWeight<<endl;
    cout<<"Container Strength: "<<c.strength<<endl;
}

void loadAndSend (Container& c, double goods) {
    displayCargo(c);
    c->cargo

}



void display(Container* p) {
    Container *p; //tworzymy pointer i object c. Pointerowi p przypisany zostaje adres objektu c.
    Container c;
    p = & c;
    p->display(); //i chyba jest wyswietlane details tego co bylo pod adresem c.
}

//task 7
void testDynamicObject() {
    // liczby z głowy
    Container *anotherObject = prepare(5, 3.14);

    // display info about the container? // tu jest jakis problem z "<<"
    cout << anotherObject->display();

    // free memory
    delete anotherObject;
}
//task4
void loadAndSend(double goods) {

}
//task5
Container* prepare(int number, double goods) {
    // this line is rather correct
    Container* object = new Container(number);

    // loading the initial quantity of goods into the container, returning the created object by the pointer
    object->cargo = goods;

    // no clue about this function
    return object;
}


int main() {
    Container red;
    red.display();
    red.displayCargo(red);

    return 0;
}
