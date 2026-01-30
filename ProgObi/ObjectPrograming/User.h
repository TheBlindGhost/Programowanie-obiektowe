#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Item.h"

class User {
    int id;
    std::string name;
    std::vector<Item*> borrowed;

public:
    User(int id, const std::string& name);

    int getId() const;
    void borrowItem(Item* item);
    void returnItem(Item* item);
    void showBorrowed() const;
};

#endif
