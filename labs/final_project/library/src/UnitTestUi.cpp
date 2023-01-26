//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "UnitTestUi.h"


UnitTestUi::UnitTestUi() {

}

void UnitTestUi::displayBooks(std::vector<std::shared_ptr<Book>> books) {
    std::cout << "SUCCESS" << std::endl;
}

void UnitTestUi::displayClients(std::vector<std::shared_ptr<Client>> clients) {
    std::cout << "SUCCESS" << std::endl;
}

void UnitTestUi::displayRequests(std::vector<std::shared_ptr<Request>> requests) {
    std::cout << "SUCCESS" << std::endl;
}
