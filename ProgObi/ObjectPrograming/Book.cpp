#include "Book.h"
#include <iostream>

Book::Book(const std::string& title, int year,
           const std::string& author, int copies)
    : Item(title, year, copies), author(author) {}

void Book::displayInfo() const {
    std::cout << "[Ksiazka] " << title
              << " | Autor: " << author
              << " | Rok: " << year
              << " | Dostepne: " << availableCopies
              << "/" << totalCopies << std::endl;
}

std::string Book::serialize() const {
    return "BOOK;" + title + ";" + author + ";" +
           std::to_string(year) + ";" +
           std::to_string(totalCopies) + ";" +
           std::to_string(availableCopies);
}
