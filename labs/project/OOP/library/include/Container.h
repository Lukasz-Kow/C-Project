//
// Created by Mateusz Pryl on 21/10/2022.
//

#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <stdlib.h>

class Container {
public:

    Container(int number);
    Container();

    int maxCargo();
    int grossWeight();

    void loadCargo(double goods);
//#1
    void display();
//#3
    void displayCargo(Container);
//#4
    void loadAndSend(double goods);
//5
    Container* prepare(int number, double goods);
//6
    void display(Container* p);
//#7
    void testDynamicObject();

    void set_cargo(int c){
        cargo = c;
    }
    int get_cargo(){
        return cargo;
    }
private:

    int number;
    double tareWeight;
    double maxWeight;
    double strength;
    double cargo;
    double goods;
};


#endif //CONTAINER_H
