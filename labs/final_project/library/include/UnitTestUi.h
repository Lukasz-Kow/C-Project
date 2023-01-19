//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_UNITTESTUI_H
#define OOPPROJECT_UNITTESTUI_H

#include "LibraryUI.h"

class UnitTestUi: public LibraryUI {
    UnitTestUi();

    void displayBooks();
    void displayClients();
    void displayRequests();
};


#endif //OOPPROJECT_UNITTESTUI_H
