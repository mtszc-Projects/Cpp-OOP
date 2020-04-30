#include "movie.h"
#include <iostream>

Movie::Movie(std::string d, std:: string sw): Item("Film", "brak danych", "brak danych", 0, 0), director(d), script_writer(sw){
}

Movie::~Movie(){
}

void Movie::display_data() const {
    Item::display_data();
    std::cout << "Rezyser: " << director << std::endl;
    std::cout << "Scenarzysta: " << script_writer << std::endl;
    std::cout << std::endl;
}

void Movie::write_data(){
    Item::write_data();
    std::cout << "Podaj rezysera: ";
    std::cin.get();
    getline(std::cin, director);
    std::cout << "Podaj scenarzyste: ";
    getline(std::cin, script_writer);
    std::cout << std::endl;
}