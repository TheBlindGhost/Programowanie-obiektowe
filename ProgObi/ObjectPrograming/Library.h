#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include "Item.h"
#include "User.h"

class Library {
    std::vector<std::unique_ptr<Item>> items;
    std::vector<User> users;

public:
    void addItem(std::unique_ptr<Item> item);
    void addUser(const User& user);

    Item* findItem(const std::string& title);
    User* findUser(int id);

    void showItems() const;
    void saveToFile(const std::string& filename) const;
};

#endif
