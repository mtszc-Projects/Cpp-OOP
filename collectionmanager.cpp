#include "collectionmanager.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>

CollectionManager::CollectionManager(User & u1) : user1(u1) {
}

CollectionManager::~CollectionManager(){
}

void CollectionManager::add_collection(){
    system("cls");
    if(user1.getCreatedCollections() >= user1.getMaxCollections()){
        std::cout << "Nie mozesz zalozyc nowej kolekcji, wykorzystujesz juz maksymalna ilosc kolekcji. Mozesz modyfikowac \n" <<
        "istniejace kolekcje." << std::endl << "(nacisnij dowolny klawisz, aby wrocic do glownego menu.)";
        getch();
        system("cls");
    }
    else{
        std::cout << "Jak chcesz nazwac kolekcje o nr " << user1.getCreatedCollections()+1 << "?: ";
        std::string collection_name;
        std::cin >> collection_name;
        user1.getUserCollection().at(user1.getCreatedCollections()).setName(collection_name);
        std::cout << std::endl << "Gratuluje! Utworzyles kolekcje: " <<
        user1.getUserCollection().at(user1.getCreatedCollections()).getName() << ".\n" <<
        "(nacisnij dowolny klawisz, aby wrocic do glownego menu.)";
        user1.setCreatedCollections(user1.getCreatedCollections()+1);
        getch();
        system("cls");
    }
}

void CollectionManager::display_collection(){
    system("cls");
    if(user1.getCreatedCollections() == 0){
        std::cout << "Aby wyswietlic kolekcje, musisz wczesniej utworzyc chociaz jedna kolekcje.\n" <<
        "(nacisnij dowolny klawisz, aby wrocic do glownego menu.)";
        getch();
        system("cls");
    }
    else{
        std::cout << "Ktora kolekcje chcesz wyswietlic?" << std::endl;
        for (int i=0; i < user1.getCreatedCollections(); ++i){
            std::cout << i+1 << ": " << user1.getUserCollection().at(i).getName() << std::endl;
        }
    }
    int flag;
    while (flag <= 0 || flag > user1.getCreatedCollections()){
        std::cout << std::endl << "Wybierz numer kolekcji z wyzej wymienionych: ";
        std::cin >> flag;
    }
    system("cls");
    std::cout << "ZAWARTOSC KOLEKCJI: " << user1.getUserCollection().at(flag-1).getName() << std::endl <<std::endl;
    std::cout << "KSIAZKI:" << std::endl << std::endl;
    for(int i=0; i < user1.getUserCollection().at(flag-1).getBookQuantity(); ++i){
        user1.getUserCollection().at(flag-1).getBookCollection().at(i).display_data();
    }
    std::cout << "FILMY:" << std::endl << std::endl;
    for(int i=0; i < user1.getUserCollection().at(flag-1).getMovieQuantity(); ++i){
        user1.getUserCollection().at(flag-1).getMovieCollection().at(i).display_data();
    }
    std::cout << "ALBUMY:" << std::endl << std::endl;
    for(int i=0; i < user1.getUserCollection().at(flag-1).getAlbumQuantity(); ++i){
        user1.getUserCollection().at(flag-1).getAlbumCollection().at(i).display_data();
    }
    std::cout << "(nacisnij dowolny klawisz, aby wrocic do glownego menu.)";
    getch();
    system("cls");
}


void CollectionManager::display_category(){
    system("cls");
    std::string item_type;
    while (item_type != "k" && item_type != "f" && item_type != "a"){
        std::cout << user1.getName() << " jaka kategorie chcesz wyswietlic? \n" <<
        "(ksiazka - nacisnij k; film - nacisnij f; album muzyczny - nacisnij a): ";
        std::cin >> item_type;
        }
    int counter = 0;
    if (item_type == "k"){
        std::cout << "KSIAZKI we wszystkich kolekcjach:" << std::endl << std::endl;
        for(int i = 0; i < user1.getCreatedCollections(); ++i ){
            for(int j=0; j < user1.getUserCollection().at(i).getBookQuantity(); ++j){
                user1.getUserCollection().at(i).getBookCollection().at(j).display_data();
                ++ counter;
            }
        }
        if ((counter == 0)){ std::cout << "W twoich kolekcjach nie ma ani jednej ksiazki." << std::endl << std::endl; }
    }
    else if(item_type == "f"){
        std::cout << "FILMY we wszystkich kolekcjach:" << std::endl << std::endl;
        for(int i = 0; i < user1.getCreatedCollections(); ++i ){
            for(int j=0; j < user1.getUserCollection().at(i).getBookQuantity(); ++j){
                user1.getUserCollection().at(i).getBookCollection().at(j).display_data();
            }
        }
    }
    else{
        std::cout << "ALBUMY we wszystkich kolekcjach:" << std::endl << std::endl;
        for(int i = 0; i < user1.getCreatedCollections(); ++i ){
            for(int j=0; j < user1.getUserCollection().at(i).getBookQuantity(); ++j){
                user1.getUserCollection().at(i).getBookCollection().at(j).display_data();
            }
        }
    }
    std::cout << "(nacisnij dowolny klawisz, aby wrocic do glownego menu.)";
    getch();
    system("cls");
}

void CollectionManager::change_collection_name(){
    system("cls");
    if(user1.getCreatedCollections() == 0){
        std::cout << "Aby zmienic nazwe kolekcji, musisz wczesniej utworzyc chociaz jedna kolekcje.\n" <<
        "(nacisnij dowolny klawisz, aby wrocic do glownego menu.)";
        getch();
        system("cls");
    }
    else{
        std::cout << "Ktorej kolekcji chcesz zmienic nazwe?" << std::endl;
        for (int i=0; i < user1.getCreatedCollections(); ++i){
            std::cout << i+1 << ": " << user1.getUserCollection().at(i).getName() << std::endl;
        }
        int flag;
        while (flag <= 0 || flag > user1.getCreatedCollections()){
            std::cout << std::endl << "Wybierz numer kolekcji z wyzej wymienionych: ";
            std::cin >> flag;
        }
        std::cout << "Jaka nowa nazwe chcesz nadac kolekcji " << user1.getUserCollection().at(flag-1).getName() << "?: ";
        std::string collection_name;
        std::cin >> collection_name;
        user1.getUserCollection().at(flag-1).setName(collection_name);
        std::cout << std::endl << "Gratuluje! Zmieniles nazwe kolekcji. Nowa nazwa to: " <<
        user1.getUserCollection().at(flag-1).getName() << ".\n" << "(nacisnij dowolny klawisz, aby wrocic do glownego menu.)";
        getch();
        system("cls");
    }
}

void CollectionManager::delete_collection(){
}

void CollectionManager::add_item(){
    system("cls");
    if(user1.getCreatedCollections() == 0){
        std::cout << "Aby dodac element do kolekcji, musisz wczesniej utworzyc chociaz jedna kolekcje.\n" <<
        "(nacisnij dowolny klawisz, aby wrocic do glownego menu.)";
        getch();
        system("cls");
    }
    else{
        std::cout << "Do ktorej kolekcji chcesz dodac przedmiot?" << std::endl;
        for (int i=0; i < user1.getCreatedCollections(); ++i){
            std::cout << i+1 << ": " << user1.getUserCollection().at(i).getName() << std::endl;
        }
        int flag;
        while (flag <= 0 || flag > user1.getCreatedCollections()){
            std::cout << std::endl << "Wybierz numer kolekcji z wyzej wymienionych: ";
            std::cin >> flag;
        }
        std::string item_type;
        while (item_type != "k" && item_type != "f" && item_type != "a"){
            std::cout << user1.getName() << " co chcesz dodac do swojej kolekcji " <<
            user1.getUserCollection().at(flag-1).getName() <<
            "? (ksiazka - nacisnij k; film - nacisnij f; album muzyczny - nacisnij a): ";
            std::cin >> item_type;
        }
        std::cout << std::endl;
        if (item_type == "k"){
            if(user1.getUserCollection().at(flag-1).getBookQuantity()<user1.getUserCollection().at(flag-1).getQuantity()){
                user1.getUserCollection().at(flag-1).getBookCollection().at(user1.getUserCollection().at(flag-1).getBookQuantity()).write_data();
                user1.getUserCollection().at(flag-1).setBookQuantity(user1.getUserCollection().at(flag-1).getBookQuantity()+1);
            }
            else{
                std::cout << "Nie mozesz dodac nowej ksiazki. Posiadasz juz maksymalna ilosc ksiazek w tej kolekcji.\n" <<
                "Mozesz modyfikowac istniejace pozycje. \n" << "(nacisnij dowolny klawisz, aby wrocic do glownego menu.)";
                getch();
                system("cls");
            }
        }
        else if (item_type == "f"){
            if(user1.getUserCollection().at(flag-1).getMovieQuantity()<user1.getUserCollection().at(flag-1).getQuantity()){
                user1.getUserCollection().at(0).getMovieCollection().at(user1.getUserCollection().at(0).getMovieQuantity()).write_data();
                user1.getUserCollection().at(0).setMovieQuantity(user1.getUserCollection().at(0).getMovieQuantity()+1);
            }
            else{
                std::cout << "Nie mozesz dodac nowego filmu. Posiadasz juz maksymalna ilosc filmow w tej kolekcji.\n" <<
                "Mozesz modyfikowac istniejace pozycje. \n" << "(nacisnij dowolny klawisz, aby wrocic do glownego menu.)";
                getch();
                system("cls");
            }
        }
        else {
            if(user1.getUserCollection().at(flag-1).getAlbumQuantity()<user1.getUserCollection().at(flag-1).getQuantity()){
                user1.getUserCollection().at(0).getAlbumCollection().at(user1.getUserCollection().at(0).getAlbumQuantity()).write_data();
                user1.getUserCollection().at(0).setAlbumQuantity(user1.getUserCollection().at(0).getAlbumQuantity()+1);
            }
            else{
                std::cout << "Nie mozesz dodac nowego filmu. Posiadasz juz maksymalna ilosc filmow w tej kolekcji.\n" <<
                "Mozesz modyfikowac istniejace pozycje. \n" << "(nacisnij dowolny klawisz, aby wrocic do glownego menu.)";
                getch();
                system("cls");
            }
        }
        std::cout << "Pozycja dodana do twojej kolekcji o nazwie: " << user1.getUserCollection().at(0).getName() << ".";
        std::cout << std::endl <<"W tej chwili w kolekcji " << user1.getUserCollection().at(0).getName() << " znajduje sie " <<
        user1.getUserCollection().at(0).getBookQuantity() << " ksiazek/ki, " << user1.getUserCollection().at(0).getMovieQuantity() <<
        " filmy/ow, i " << user1.getUserCollection().at(0).getAlbumQuantity() << " albumy/ow.";
        std::cout << std::endl << "(nacisnij dowolny klawisz, aby wrocic do glownego menu.)";
        getch();
        system("cls");
    }
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
    int wybor;
    while (wybor != 11){
        std::cout << user1.getName() << " przysluguje Ci " << user1.getMaxCollections() <<
        " osobnych kolekcji, ktore moga reprezentowac rozne \nkategorie (np. wesole, sensacyjne itd.), mozesz tez" <<
        " korzystac z jednej ogolnej kolekcji. W kazdej z nich \nmozesz zapisywac swoje ulubione ksiazki, filmy i" <<
        " albumy muzyczne w ilosci do " << user1.getUserCollection().at(0).getQuantity()<< " z kazdej kategorii.";
        std::cout << std::endl <<std::endl;
        std::cout << user1;
        std::cout << std::endl;
        std::cout << "Masz do wyboru nastepujace dzialania:"<<std::endl << std::endl;
        std::cout << "1.  Utworz nowa kolekcje."; std::cout << std::setw(39) << "(nacisnij:  1)" << std::endl;
        std::cout << "2.  Dodaj przedmiot do istniejacej kolekcji."; std::cout << std::setw(20) << "(nacisnij:  2)" << std::endl;
        std::cout << "3.  Wyswietl zawartosc danej kolekcji."; std::cout << std::setw(26) << "(nacisnij:  3)" << std::endl;
        std::cout << "4.  Wyswietl zawartosc danej kategorii."; std::cout << std::setw(25) << "(nacisnij:  4)" << std::endl;
        std::cout << "5.  Zmien nazwe wybranej kolekcji."; std::cout << std::setw(30) << "(nacisnij:  5)" << std::endl;
        std::cout << "6.  Szukaj przedmiotu w kolekcji."; std::cout << std::setw(31) << "(nacisnij:  6)" << std::endl;
        std::cout << "7.  Szukaj kolekcji."; std::cout << std::setw(44) << "(nacisnij:  7)" << std::endl;
        std::cout << "8.  Zmodyfikuj przedmiot w kolekcji."; std::cout << std::setw(28) << "(nacisnij:  8)" << std::endl;
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
            display_collection();
            break;
        case 4:
            display_category();
            break;
        case 5:
            change_collection_name();
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
