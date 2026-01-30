#include "User.h"
#include <iostream>

User::User(int id, const std::string& name)
    : id(id), name(name) {}

int User::getId() const {
    return id;
}

void User::borrowItem(Item* item) {
    item->borrow();
    borrowed.push_back(item);
}

void User::returnItem(Item* item) {
    item->returnItem();
}

void User::showBorrowed() const {
    std::cout << "Wypozyczone przez " << name << ":\n";
    for (auto item : borrowed)
        item->displayInfo();
}
