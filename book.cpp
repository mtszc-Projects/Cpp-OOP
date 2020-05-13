#include "book.h"
#include <iostream>
#include <iomanip>

Book::Book(std::string a, int p): Item("Ksiazka", "brak danych", "brak danych", 0, 0), author(a), pages(p){
}

Book::Book(const Book & book) : Item(book){
    author = book.author;
    pages = book.pages;
}

Book::~Book(){
}

void Book::display_data() const {
    Item::display_data();
    std::cout << "Autor: " << author << std::endl;
    std::cout << "Liczba stron: " << pages << std::endl;
    std::cout << std::endl;
}

void Book::write_data(){
    Item::write_data();
    std::cout << "Podaj autora: ";
    std::cin.get();
    getline(std::cin, author);
    std::cout << "Podaj liczbe stron: ";
    while(!(std::cin >> pages)){
        std::cout << "Liczba stron musi byc liczba. Podaj poprawna liczbe stron: ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    std::cout << std::endl;
}

Book & Book::operator=(const Book & book){
	if(&book == this) return *this;
	Item::operator=(book);
    author = book.author;
    pages = book.pages;
    return *this;
}
