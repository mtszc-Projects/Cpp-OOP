#include "book.h"
#include <iostream>

Book::Book(std::string a): Item("Ksiazka", "brak danych", "brak danych", 0, 0), author(a){
}

Book::Book(const Book & book) : Item(book){
    author = book.author;
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

Book & Book::operator=(const Book & book){
	if(&book == this) return *this;
	Item::operator=(book);
    author = book.author;
    return *this;
}
