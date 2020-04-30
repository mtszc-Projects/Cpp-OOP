#include "item.h"
#include <iostream>
#include <string>

Item::Item(std::string it, std::string t, std::string g, int y, int p) : item_type(it), title(t), genre(g), year(y), price(p){
}

Item::~Item(){
}

void Item::display_data() const {
    std::cout << "Typ przedmiotu w kolekcji: " << item_type << std::endl;
    std::cout << "Tytul: " << title << std::endl;
    std::cout << "Gatunek: " << genre << std::endl;
    std::cout << "Rok wydania: " << year << std::endl;
    std::cout << "Cena: " << price << std::endl;
}

void Item::write_data(){
    std::cout << "Podaj tytul: ";
    std::cin.get();
    getline(std::cin, title);
    std::cout << "Podaj gatunek: ";
    getline(std::cin, genre);
    std::cout << "Podaj rok wydania: ";
    std::cin >> year;
    std::cout << "Podaj cene: ";
    std::cin >> price;
}
