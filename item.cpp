#include "item.h"
#include <iostream>
#include <string>
#include <iomanip>

Item::Item(std::string it, std::string t, std::string g, int y, int p) : item_type(it), title(t), genre(g), year(y), price(p){
}

Item::Item(const Item & item){
    item_type = item.item_type;
    title = item.title;
    genre = item.genre;
    year = item.year;
    price = item.price;
}

Item::~Item(){
}

void Item::display_data() const {
    std::cout << "Typ przedmiotu w kolekcji: " << item_type << std::endl;
    std::cout << "Tytul: " << title << std::endl;
    std::cout << "Gatunek: " << genre << std::endl;
    std::cout << "Rok wydania: " << year << std::endl;
    std::cout << "Cena: " << price << " zlotych" << std::endl;
}

void Item::write_data(){
    std::cout << "Podaj tytul: ";
    std::cin.get();
    getline(std::cin, title);
    std::cout << "Podaj gatunek: ";
    getline(std::cin, genre);
    std::cout << "Podaj rok wydania: ";
    while(!(std::cin >> year)){
        std::cout << "Rok musi byc liczba. Podaj poprawny rok: ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    std::cout << "Podaj cene w pelnych zlotych: ";
    while(!(std::cin >> price)){
        std::cout << "Cena musi byc liczba. Podaj poprawna cene: ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
}

Item & Item::operator=(const Item & item){
	if(&item == this) return *this;
    item_type = item.item_type;
    title = item.title;
    genre = item.genre;
    year = item.year;
    price = item.price;
    return *this;
}
