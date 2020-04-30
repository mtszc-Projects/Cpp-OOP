#include "book.h"
#include <iostream>

Book::Book(std::string a): Item("Ksiazka", "brak danych", "brak danych", 0, 0), author(a){
}

Book::~Book(){
}

void Book::display_data() const {
    Item::display_data();
    std::cout << "Autor: " << author << std::endl;
    std::cout << std::endl;
}

void Book::write_data(){
    Item::write_data();
    std::cout << "Podaj autora: ";
    std::cin.get();
    getline(std::cin, author);
    std::cout << std::endl;
}
