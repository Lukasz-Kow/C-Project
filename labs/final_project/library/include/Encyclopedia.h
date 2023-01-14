//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_ENCYCLOPEDIA_H
#define OOPPROJECT_ENCYCLOPEDIA_H

#include "Book.h"

class Encyclopedia : public Book {
private:

    string theme;

public:

    Encyclopedia(int id, string title, string author, int pageNumber, string theme);

    string getUniqueTrait() override;

    string display() override;

};


#endif //OOPPROJECT_ENCYCLOPEDIA_H
