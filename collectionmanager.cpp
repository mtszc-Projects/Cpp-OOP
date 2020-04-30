#include "collectionmanager.h"
#include <iostream>
#include <iomanip>

CollectionManager::CollectionManager(User & u1) : user1(u1) {
}

CollectionManager::~CollectionManager(){
}

void CollectionManager::add_collection(){
    std::cout << "Jak chcesz nazwac kolekcje o nr " << user1.getCreatedCollections()+1 << "?: ";
    std::string collection_name;
    std::cin.get();
    getline(std::cin, collection_name);
    user1.getUserCollection().at(0).setName(collection_name);
    user1.getUserCollection().at(0).setBookQuantity(0);
    user1.getUserCollection().at(0).setAlbumQuantity(0);
    user1.getUserCollection().at(0).setMovieQuantity(0);
    std::cout << std::endl << "Gratuluje! Utworzyles kolekcje: " << user1.getUserCollection().at(0).getName() << "." << std::endl;
}
void CollectionManager::search_collection(){
}
void CollectionManager::update_collection(){
}
void CollectionManager::delete_collection(){
}

void CollectionManager::add_item(){
    std::cout << "Do ktorej kolekcji chcesz dodac przedmiot?";
    std::string item_type;
    while (item_type != "k" && item_type != "f" && item_type != "a"){
        std::cout << user1.getName() << " co chcesz dodac do swojej kolekcji? (ksiazka - nacisnij k; film - nacisnij" <<
        " f; album muzyczny - nacisnij a): ";
        std::cin >> item_type;
    }
    std::cout << std::endl;
    if (item_type == "k"){
        user1.getUserCollection().at(0).getBookCollection().at(user1.getUserCollection().at(0).getBookQuantity()).write_data();
        user1.getUserCollection().at(0).setBookQuantity(user1.getUserCollection().at(0).getBookQuantity()+1);
    }
    else if (item_type == "f"){
        user1.getUserCollection().at(0).getMovieCollection().at(user1.getUserCollection().at(0).getMovieQuantity()).write_data();
        user1.getUserCollection().at(0).setMovieQuantity(user1.getUserCollection().at(0).getMovieQuantity()+1);

    }
    else {
        user1.getUserCollection().at(0).getAlbumCollection().at(user1.getUserCollection().at(0).getAlbumQuantity()).write_data();
        user1.getUserCollection().at(0).setAlbumQuantity(user1.getUserCollection().at(0).getAlbumQuantity()+1);
    }
    std::cout << "Pozycja dodana do twojej kolekcji o nazwie: " << user1.getUserCollection().at(0).getName() << ".";
    std::cout << std::endl;
    std::cout << "W tej chwili w kolekcji " << user1.getUserCollection().at(0).getName() << " znajduje sie " <<
    user1.getUserCollection().at(0).getBookQuantity() << " ksiazek/ki, " << user1.getUserCollection().at(0).getMovieQuantity() <<
    " filmy/ow, i " << user1.getUserCollection().at(0).getAlbumQuantity() << " albumy/ow.";
}
void CollectionManager::search_item(){
}
void CollectionManager::update_item(){
}
void CollectionManager::delete_item(){
}

void CollectionManager::manage(){
    std::cout << "Witaj " << user1.getName() << " " << user1.getSurname() << "! Czy chcesz zmienic swoje imie i nazwisko?(y/n)";
    std::string flag;
    std::cin >> flag;
    if( flag == "y"){
        std::cout << std::endl;
        std::string newname;
        std::cout << "Wprowadz swoje imie: ";
        std::cin.get();
        getline(std::cin, newname);
        user1.setName(newname);
        std::string newsurname;
        std::cout << "Wprowadz swoje nazwisko: ";
        std::cin >> newsurname;
        user1.setSurname(newsurname);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << user1.getName() << " witaj w menedzerze kolekcji. Przysluguje Ci " << user1.getMaxCollections() <<
    " osobnych kolekcji, ktore moga reprezentowac rozne \nkategorie (np. wesole, sensacyjne itd.), mozesz tez" <<
    " korzystac z jednej ogolnej kolekcji. W kazdej z nich \nmozesz zapisywac swoje ulubione ksiazki, filmy i" <<
    " albumy muzyczne w ilosci do " << user1.getUserCollection().at(0).getQuantity()<< " z kazdej kategorii.";
    std::cout << std::endl <<std::endl;
    user1.setCreatedCollections(0);
    std::cout << "Obecnie posiadasz "<< user1.getCreatedCollections() << " kolekcji." << std::endl;
    int wybor;
    std::cout << std::endl;
    while (wybor != 11){
        std::cout << "Masz do wyboru nastepujace dzialania:"<<std::endl << std::endl;
        std::cout << "1.  Utworz nowa kolekcje."; std::cout << std::setw(39) << "(nacisnij:  1)" << std::endl;
        std::cout << "2.  Dodaj przedmiot do istniejacej kolekcji."; std::cout << std::setw(20) << "(nacisnij:  2)" << std::endl;
        std::cout << "3.  Zmodyfikuj przedmiot w kolekcji."; std::cout << std::setw(28) << "(nacisnij:  3)" << std::endl;
        std::cout << "4.  Zmodyfikuj kolekcje."; std::cout << std::setw(40) << "(nacisnij:  4)" << std::endl;
        std::cout << "5.  Szukaj przedmiotu w kolekcji."; std::cout << std::setw(31) << "(nacisnij:  5)" << std::endl;
        std::cout << "6.  Szukaj kolekcji."; std::cout << std::setw(44) << "(nacisnij:  6)" << std::endl;
        std::cout << "7.  Wyswietl przedmiot w kolekcji."; std::cout << std::setw(30) << "(nacisnij:  7)" << std::endl;
        std::cout << "8.  Wyswietl kolekcje."; std::cout << std::setw(42) << "(nacisnij:  8)" << std::endl;
        std::cout << "9.  Usun przedmiotu z kolekcji."; std::cout << std::setw(33) << "(nacisnij:  9)" << std::endl;
        std::cout << "10. Usun kolekcji."; std::cout << std::setw(46) << "(nacisnij: 10)" << std::endl;
        std::cout << "11. Zakoncz dzialanie programu."; std::cout << std::setw(33) << "(nacisnij: 11)" << std::endl << std::endl;
        std::cout << "Podaj numer: ";
        std::cin >> wybor;
        switch (wybor){
        case 1:
            add_collection();
            break;
        case 2:
            add_item();
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:

            break;
        case 11:

            break;
        }
    }
}
