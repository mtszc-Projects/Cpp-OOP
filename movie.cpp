#include "movie.h"
#include <iostream>
#include <iomanip>

Movie::Movie(std::string d, std:: string sw, int l): Item("Film", "brak danych", "brak danych", 0, 0), director(d), script_writer(sw), length(l){
}

Movie::Movie(const Movie & movie) : Item(movie){
    director = movie.director;
    script_writer = movie.script_writer;
    length = movie.length;
}

Movie::~Movie(){
}

void Movie::display_data() const {
    Item::display_data();
    std::cout << "Rezyser: " << director << std::endl;
    std::cout << "Scenarzysta: " << script_writer << std::endl;
    std::cout << "Dlugosc filmu: " << length << " minut" << std::endl;
    std::cout << std::endl;
}

void Movie::write_data(){
    Item::write_data();
    std::cout << "Podaj rezysera: ";
    std::cin.get();
    getline(std::cin, director);
    std::cout << "Podaj scenarzyste: ";
    getline(std::cin, script_writer);
    std::cout << "Podaj dlugosc filmu w minutach: ";
    while(!(std::cin >> length)){
        std::cout << "Dlugosc musi byc liczba. Podaj poprawna dlugosc: ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    std::cout << std::endl;
}

Movie & Movie::operator=(const Movie & movie){
	if(&movie == this) return *this;
	Item::operator=(movie);
    director = movie.director;
    script_writer = movie.script_writer;
    length = movie.length;
    return *this;
}
