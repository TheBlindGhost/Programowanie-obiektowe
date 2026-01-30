# 📚 System zarządzania biblioteką (C++ – OOP)

## 1. Opis projektu
Projekt jest konsolowym systemem zarządzania biblioteką napisanym w języku **C++**, którego celem jest demonstracja podstawowych oraz zaawansowanych założeń **programowania obiektowego**.

Aplikacja umożliwia zarządzanie zasobami biblioteki (książki, płyty DVD), obsługę użytkowników oraz realizację procesu wypożyczania i zwrotu pozycji.

Projekt został przygotowany jako **projekt zaliczeniowy**.

---

## 2. Zastosowane założenia programowania obiektowego
W projekcie wykorzystano następujące koncepcje OOP:

- **Abstrakcja** – klasa abstrakcyjna `Item`
- **Dziedziczenie** – klasy `Book`, `DVD`
- **Polimorfizm** – wirtualna metoda `displayInfo()`
- **Enkapsulacja** – prywatne pola klas, dostęp przez metody
- **Kompozycja** – klasa `Library` przechowuje kolekcje obiektów
- **Nowoczesny C++** – `std::unique_ptr`, `enum class`, wyjątki

---

## 3. Funkcjonalności programu
- wyświetlanie zasobów biblioteki
- wypożyczanie i zwracanie pozycji
- kontrola dostępnych egzemplarzy
- obsługa wielu typów zasobów
- obsługa wyjątków
- zapis stanu biblioteki do pliku
- menu tekstowe

---

## 4. Struktura projektu
```
LibraryProject/
│── main.cpp
│── Item.h / Item.cpp
│── Book.h / Book.cpp
│── DVD.h / DVD.cpp
│── User.h / User.cpp
│── Library.h / Library.cpp
```

---

## 5. Opis klas

### `Item` (klasa abstrakcyjna)
Reprezentuje element biblioteki.
- tytuł
- rok wydania
- liczba egzemplarzy
- metody wirtualne

### `Book`
Dziedziczy po `Item`.
- autor książki

### `DVD`
Dziedziczy po `Item`.
- czas trwania filmu

### `User`
Reprezentuje użytkownika biblioteki.
- ID
- imię i nazwisko
- lista wypożyczonych pozycji

### `Library`
Zarządza całością systemu.
- lista zasobów
- lista użytkowników
- wyszukiwanie, zapis do pliku

--- 

## 6. Diagram UML

```
                <<abstract>>
+--------------------------------+
|             Item               |
+--------------------------------+
| - title : string               |
| - year : int                   |
| - totalCopies : int            |
| - availableCopies : int        |
+--------------------------------+
| + getTitle() : string          |
| + isAvailable() : bool         |
| + borrow() : void              |
| + returnItem() : void          |
| + displayInfo() : void         |
| + serialize() : string         |
+--------------------------------+
               ^
               |
      ---------------------
      |                   |
+-------------+   +----------------+
|    Book     |   |      DVD       |
+-------------+   +----------------+
| - author    |   | - duration:int |
+-------------+   +----------------+
| + displayInfo()| | + displayInfo()|
| + serialize() | | + serialize() |
+-------------+   +----------------+


+--------------------------------+
|              User              |
+--------------------------------+
| - id : int                     |
| - name : string                |
| - borrowed : vector<Item*>     |
+--------------------------------+
| + getId() : int                |
| + borrowItem(Item*) : void     |
| + returnItem(Item*) : void     |
| + showBorrowed() : void        |
+--------------------------------+


+----------------------------------------------+
|                  Library                     |
+----------------------------------------------+
| - items : vector<unique_ptr<Item>>           |
| - users : vector<User>                       |
+----------------------------------------------+
| + addItem(unique_ptr<Item>) : void           |
| + addUser(User) : void                       |
| + findItem(string) : Item*                  |
| + findUser(int) : User*                     |
| + showItems() : void                        |
| + saveToFile(string) : void                 |
+----------------------------------------------+
```
---

## 7. Podsumowanie
Projekt spełnia wymagania projektu zaliczeniowego, prezentując praktyczne zastosowanie zasad programowania obiektowego w języku C++. Struktura kodu umożliwia łatwą rozbudowę systemu o kolejne funkcjonalności.

---

Autor: Mateusz Pietrusa


