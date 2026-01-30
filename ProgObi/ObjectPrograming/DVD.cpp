#include "DVD.h"
#include <iostream>

DVD::DVD(const std::string& title, int year,
         int duration, int copies)
    : Item(title, year, copies), duration(duration) {}

void DVD::displayInfo() const {
    std::cout << "[DVD] " << title
              << " | Czas: " << duration << " min"
              << " | Rok: " << year
              << " | Dostepne: " << availableCopies
              << "/" << totalCopies << std::endl;
}

std::string DVD::serialize() const {
    return "DVD;" + title + ";" +
           std::to_string(duration) + ";" +
           std::to_string(year) + ";" +
           std::to_string(totalCopies) + ";" +
           std::to_string(availableCopies);
}
