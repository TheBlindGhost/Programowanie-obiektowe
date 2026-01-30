#ifndef DVD_H
#define DVD_H

#include "Item.h"

class DVD : public Item {
    int duration;

public:
    DVD(const std::string& title, int year,
        int duration, int copies);

    void displayInfo() const override;
    std::string serialize() const override;
};

#endif
