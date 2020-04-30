#include "album.h"
#include <iostream>

Album::Album(std::string a) : Item("Album", "brak danych", "brak danych", 0, 0), author(a){
}

Album::~Album(){
}

void Album::display_data() const {
    Item::display_data();
    std::cout << "Autor: " << author << std::endl;
    std::cout << std::endl;
}

void Album::write_data(){
    Item::write_data();
    std::cout << "Podaj autora: ";
    std::cin.get();
    getline(std::cin, author);
    std::cout << std::endl;
}
