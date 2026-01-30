#include "Item.h"
#include <stdexcept>

Item::Item(const std::string& title, int year, int copies)
    : title(title), year(year),
      totalCopies(copies), availableCopies(copies) {}

std::string Item::getTitle() const {
    return title;
}

bool Item::isAvailable() const {
    return availableCopies > 0;
}

void Item::borrow() {
    if (!isAvailable())
        throw std::runtime_error("Brak dostepnych egzemplarzy");
    availableCopies--;
}

void Item::returnItem() {
    if (availableCopies < totalCopies)
        availableCopies++;
}
