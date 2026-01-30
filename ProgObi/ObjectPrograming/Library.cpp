#include "Library.h"
#include <iostream>
#include <fstream>

void Library::addItem(std::unique_ptr<Item> item) {
    items.push_back(std::move(item));
}

void Library::addUser(const User& user) {
    users.push_back(user);
}

Item* Library::findItem(const std::string& title) {
    for (auto& item : items)
        if (item->getTitle() == title)
            return item.get();
    return nullptr;
}

User* Library::findUser(int id) {
    for (auto& user : users)
        if (user.getId() == id)
            return &user;
    return nullptr;
}

void Library::showItems() const {
    for (const auto& item : items)
        item->displayInfo();
}

void Library::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& item : items)
        file << item->serialize() << std::endl;
}
