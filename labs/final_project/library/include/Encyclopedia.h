//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_ENCYCLOPEDIA_H
#define OOPPROJECT_ENCYCLOPEDIA_H

#include "Book.h"
#include "BookTypes.h"

class Encyclopedia : public Book {
private:

    string theme;

public:

    Encyclopedia(int id, std::string title, std::string author, int pageNumber, std::string theme);

    std::string getUniqueTrait() override;

    std::string display() override;

};


#endif //OOPPROJECT_ENCYCLOPEDIA_H
