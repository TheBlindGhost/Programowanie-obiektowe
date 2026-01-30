#include <iostream>
#include <limits>
#include "Library.h"
#include "Book.h"
#include "DVD.h"

void showMenu() {
    std::cout << "\n===== MENU BIBLIOTEKI =====\n";
    std::cout << "1. Wyswietl zasoby biblioteki\n";
    std::cout << "2. Wypozycz pozycje\n";
    std::cout << "3. Zwroc pozycje\n";
    std::cout << "4. Wyswietl wypozyczone pozycje uzytkownika\n";
    std::cout << "5. Zapisz stan biblioteki do pliku\n";
    std::cout << "0. Wyjscie\n";
    std::cout << "Wybor: ";
}

int main() {
    Library library;

    // Dane startowe
    library.addItem(std::make_unique<Book>(
        "Wladca Pierscieni", 1954, "J.R.R. Tolkien", 3));
    library.addItem(std::make_unique<Book>(
        "Pan Tadeusz", 1834, "Adam Mickiewicz", 2));
    library.addItem(std::make_unique<DVD>(
        "Incepcja", 2010, 148, 2));

    library.addUser(User(1, "Jan Kowalski"));
    library.addUser(User(2, "Anna Nowak"));

    int choice;
    do {
        showMenu();
        std::cin >> choice;

        // zabezpieczenie na zle dane
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Niepoprawny wybor.\n";
            continue;
        }

        try {
            if (choice == 1) {
                library.showItems();
            }
            else if (choice == 2) {
                int userId;
                std::string title;

                std::cout << "ID uzytkownika: ";
                std::cin >> userId;
                std::cin.ignore();

                std::cout << "Tytul pozycji: ";
                std::getline(std::cin, title);

                User* user = library.findUser(userId);
                Item* item = library.findItem(title);

                if (!user || !item)
                    throw std::runtime_error("Nie znaleziono uzytkownika lub pozycji.");

                user->borrowItem(item);
                std::cout << "Pozycja wypozyczona.\n";
            }
            else if (choice == 3) {
                int userId;
                std::string title;

                std::cout << "ID uzytkownika: ";
                std::cin >> userId;
                std::cin.ignore();

                std::cout << "Tytul pozycji: ";
                std::getline(std::cin, title);

                User* user = library.findUser(userId);
                Item* item = library.findItem(title);

                if (!user || !item)
                    throw std::runtime_error("Nie znaleziono danych.");

                user->returnItem(item);
                std::cout << "Pozycja zwrocona.\n";
            }
            else if (choice == 4) {
                int userId;
                std::cout << "ID uzytkownika: ";
                std::cin >> userId;

                User* user = library.findUser(userId);
                if (!user)
                    throw std::runtime_error("Nie znaleziono uzytkownika.");

                user->showBorrowed();
            }
            else if (choice == 5) {
                library.saveToFile("library.txt");
                std::cout << "Zapisano do pliku library.txt\n";
            }
            else if (choice != 0) {
                std::cout << "Nieznana opcja.\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Blad: " << e.what() << std::endl;
        }

    } while (choice != 0);

    std::cout << "Zamykanie programu...\n";
    return 0;
}
