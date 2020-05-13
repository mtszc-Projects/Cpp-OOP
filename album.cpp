#include "album.h"
#include <iostream>
#include <iomanip>

Album::Album(std::string a, int l) : Item("Album", "brak danych", "brak danych", 0, 0), author(a), length(l){
}

Album::Album(const Album & album) : Item(album){
    author = album.author;
    length = album.length;
}

Album::~Album(){
}

void Album::display_data() const {
    Item::display_data();
    std::cout << "Autor: " << author << std::endl;
    std::cout << "Dlugosc albumu: " << length << " minut" << std::endl;
    std::cout << std::endl;
}

void Album::write_data(){
    Item::write_data();
    std::cout << "Podaj autora: ";
    std::cin.get();
    getline(std::cin, author);
    std::cout << "Podaj dlugosc albumu w minutach: ";
    while(!(std::cin >> length)){
        std::cout << "Dlugosc musi byc liczba. Podaj poprawna dlugosc albumu: ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    std::cout << std::endl;
}

Album & Album::operator=(const Album & album){
	if(&album == this) return *this;
	Item::operator=(album);
    author = album.author;
    length = album.length;
    return *this;
}
