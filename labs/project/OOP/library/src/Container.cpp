//
// Created by Mateusz Pryl on 21/10/2022.
//

#include "Container.h"

using namespace std;

Container::Container() {
    this->number = 0;
    this->tareWeight = 0;
    this->maxWeight = 0;
    this->strength = 0;
    this->cargo = 0;
}

Container::Container(int number) {
    this->number = number;
    this->tareWeight = 0;
    this->maxWeight = 0;
    this->strength = 0;
    this->cargo = 0;
}

int Container::maxCargo(){
    return this->maxWeight - this->tareWeight;
}

int Container::grossWeight(){
    return this->tareWeight + this->cargo;
}

void Container::displayCargo(Container) {
    std::cout<<"Container Cargo: "<<cargo<<std::endl;
}

void Container::display(){
    std::cout<<"Container Number: "<<number<<std::endl;
    std::cout<<"Container Tare Weight: "<<tareWeight<<std::endl;
    std::cout<<"Container Max Weight: "<<maxWeight<<std::endl;
    std::cout<<"Container Strength: "<<strength<<std::endl;
}
void Container::loadCargo(double goods){
    cin>>goods;
    return this->cargo =+ this->goods;

}


//task 6
void Container::display(Container* p) { //przerobione z neta
    Container *p; //tworzymy pointer i object c. Pointerowi p przypisany zostaje adres objektu c.
    Container c;
    p = & c;
    p->display(); //i chyba jest wyswietlane details tego co bylo pod adresem c.
}
//task 7
void Container::testDynamicObject() {
    Container *anotherObject = prepare(5, 3.14); //liczby z głowy
    cout << anotherObject->display(); //display info about the container? // tu jest jakis problem z "<<"
    delete anotherObject; //free memory
}
//task4
void Container::loadAndSend(double goods) {

}
//task5
Container* prepare(int number, double goods) {
    Container* object = new Container(); //this line is rather correct
    object-> cargo = goods; //loading the initial quantity of goods into the container, returning the created object by the pointer
    return object; //no clue about this function
}


