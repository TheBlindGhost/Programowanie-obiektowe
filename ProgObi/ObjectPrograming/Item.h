#ifndef ITEM_H
#define ITEM_H

#include <string>

enum class ItemStatus {
    Available,
    Borrowed
};

class Item {
protected:
    std::string title;
    int year;
    int totalCopies;
    int availableCopies;

public:
    Item(const std::string& title, int year, int copies);
    virtual ~Item() = default;

    std::string getTitle() const;
    bool isAvailable() const;

    void borrow();
    void returnItem();

    virtual void displayInfo() const = 0;
    virtual std::string serialize() const = 0;
};

#endif
