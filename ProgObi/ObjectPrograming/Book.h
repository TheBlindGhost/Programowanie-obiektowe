#ifndef BOOK_H
#define BOOK_H

#include "Item.h"

class Book : public Item {
    std::string author;

public:
    Book(const std::string& title, int year,
         const std::string& author, int copies);

    void displayInfo() const override;
    std::string serialize() const override;
};

#endif
