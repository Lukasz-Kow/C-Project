//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Library.h"

Library::Library(int id, std::string name, std::shared_ptr<LibraryUI> cli): id(id), name(name), libraryCLI(cli) {}


void Library::addBook(std::shared_ptr<Book> book) {
    books.push_back(book);
}

// Function removes the element at position i from the vector, effectively removing the book from the library.
// This will not only remove the book from the vector but also delete the memory allocated to it.
void Library::removeBook(int bookId) {
    for(int i=0; i<books.size();i++)
    {
        if(books[i]->getId() == bookId)
        {
            books.erase(books.begin()+i);
        }
    }
}

std::shared_ptr<Book> Library::getBook(unsigned int n) {
    return books[n];
}

void Library::processRequest(std::shared_ptr<Request> request) {

    if(bookExists(request->getBookName())) {

        int bookIndex = findAvailableBookIndex(request->getBookName());

        if (bookIndex >= 0) {
            if (ifClientBelongsToLibrary(request->getClientUuid())) {
                if (request->getEntity() == TEACHER && books[bookIndex]->getBookTypes() == TEACHERBOOK ||
                    books[bookIndex]->getBookTypes() == STUDENTBOOK ||
                    books[bookIndex]->getBookTypes() == ENCYCLOPEDIA)
                {
                    rentBook(bookIndex, request->getClientUuid());
                    request->setStatus(FULFILLED);
                }
                else if (request->getEntity() == STUDENT && books[bookIndex]->getBookTypes() == STUDENTBOOK ||
                         books[bookIndex]->getBookTypes() == ENCYCLOPEDIA) {
                    rentBook(bookIndex, request->getClientUuid());
                    request->setStatus(FULFILLED);
                }
                else if (request->getEntity() == GUEST && books[bookIndex]->getBookTypes() == STUDENTBOOK ||
                         books[bookIndex]->getBookTypes() == ENCYCLOPEDIA) {
                    rentBook(bookIndex, request->getClientUuid());
                    request->setStatus(FULFILLED);

                } else {
                    request->setStatus(REJECTED);
                    //            std::cerr << "Failed to rent this book" << std::endl;
                }
            } else {
                request->setStatus(REJECTED);
                std::cerr << "Client does not belong to this library" << std::endl;
            }

        } else {
            request->setStatus(REJECTED);
            std::cerr << "No available book found" << std::endl;
        }

    addRequest(request);
    }
}

//This function is creating a new request object and passing it to the processRequest function for further processing.
void Library::makeRequest(string bookName, ClientTypes entityWhoMadeTheRequest, boost::uuids::uuid uuid) {
    std::shared_ptr<Request> clientRequest = std::make_shared<Request>(getRequestNumber() + 1, "2023-12-01",
                                                                       entityWhoMadeTheRequest, uuid, bookName, PROCESSING);
    processRequest(clientRequest);
}

int Library::getRequestNumber() {
    return requests.size();
}

void Library::addRequest(std::shared_ptr<Request> request) {
    requests.push_back(request);
}

//Function takes a parameter of type string called bookName, and it iterates through the books vector,
//it checks if the title of the current book is equal to the input bookName.
// If it is, it then checks if the current book's status is true (is available). If so return index
int Library::findAvailableBookIndex(std::string bookName) {
    for(int i = 0; i < books.size(); i++) {
        if(books[i]->getTitle() == bookName) {
            if(books[i]->getStatus()){
                // Book is available
                return i;
            }
            else {
                continue;
            }
        }
    }
    return -1;
}

// Function takes a parameter of type string bookName, and it iterates through the books vector.
// Inside the loop, it checks if the title of the current book is equal to the input bookName.
// If it is, it assigns the index of the book to the variable index. Then it checks if index is greater than or equal to 0.
// If it is, the function returns true, indicating that the book exists in the library.
bool Library::bookExists(std::string bookName) {
    int index = -1;
    for(int i = 0; i < books.size(); i ++)
    {
        if(books[i]->getTitle() == bookName)
        {
            index = i;
        }
    }
    if (index >= 0) {
        return true;
    }
    return false;
}

void Library::rentBook(int bookIndex, boost::uuids::uuid clientUuid) {
    books[bookIndex]->setStatus(false);
    books[bookIndex]->setUuid(clientUuid);
}

// Function takes in a parameter of type int bookId, and it iterates through the books vector.
// Inside the loop, it checks if the id of the current book is equal to the input bookId.
// If it is, it assigns the index of the book to the variable index.
// Tt sets the status of the book at the index books[index]->setStatus(true) to true, indicating that the book is available now and clears client uuid.
void Library::finishReservation(int bookId) {
    int index = -1;

    for(int i = 0; i < books.size(); i++)
    {
        if(books[i]->getId() == bookId)
        {
            index = i;
        }
    }

    books[index]->setStatus(true);
    books[index]->setUuid(boost::uuids::nil_uuid());
}

void Library::addClient(std::shared_ptr<Client> client) {
    clients.push_back(client);
}

std::shared_ptr<Client> Library::getClient(unsigned int n) {
    return clients[n];
}

std::shared_ptr<Request> Library::getRequest(unsigned int n) {
    return requests[n];
}

std::vector<std::shared_ptr<Client>> Library::getClients() {
    return clients;
}

std::vector<std::shared_ptr<Request>> Library::getRequests() {
    return requests;
}

std::vector<std::shared_ptr<Book>> Library::getBooks() {
    return books;
}

bool Library::ifClientBelongsToLibrary(boost::uuids::uuid clientUuid) {
    try {
        getClientIndexByUUID(clientUuid);
        return true;
    } catch (std::invalid_argument &e) {
        return false;
    }
}

void Library::removeClient(boost::uuids::uuid clientUuid) {
    try {
        int index = getClientIndexByUUID(clientUuid);
        clients.erase(clients.begin() + index);
    } catch (std::invalid_argument &e) {
        std::cerr << "Failed to remove non-existent client" << std::endl;
    }

}

int Library::getClientIndexByUUID(boost::uuids::uuid clientUuid) {
    int index = -1;
    for(int i = 0; i < clients.size(); i++)
    {
        if(clients[i]->getUuid() == clientUuid)
        {
            index = i;
        }
    }
    if (index >= 0) {
        return index;
    } else {
        throw std::invalid_argument("Client not found");
    }
}


