#include "collectionmanager.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <fstream>

CollectionManager::CollectionManager(User & u1) : user1(u1) {
}

CollectionManager::~CollectionManager(){
}

void CollectionManager::name_change(){
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
}


void CollectionManager::collection_not_created(){
    std::cout << "Aby wykonac operacje na elemencie, musisz wczesniej utworzyc chociaz jedna kolekcje.\n\n" <<
    "Nacisnij dowolny klawisz, aby wrocic do glownego menu: ";
    getch();
    system("cls");
}


void CollectionManager::exit_to_menu(){
    std::cout << std::endl << "Nacisnij dowolny klawisz, aby wrocic do glownego menu: ";
    getch();
    system("cls");
}


void CollectionManager::add_collection(){
    system("cls");
    if(user1.getCreatedCollections() >= user1.getMaxCollections()){
        std::cout << "Nie mozesz zalozyc nowej kolekcji, wykorzystujesz juz maksymalna ilosc kolekcji.\nMozesz modyfikowac " <<
        "istniejace kolekcje, lub usunac jedna z nich.\n" << std::endl;
        exit_to_menu();
    }
    else{
        std::cout << "Jak chcesz nazwac kolekcje o nr " << user1.getCreatedCollections()+1 << "?: ";
        std::string collection_name;
        std::cin.get();
        getline(std::cin, collection_name);
        user1.getUserCollection().at(user1.getCreatedCollections()).setName(collection_name);
        std::cout << std::endl << "Gratuluje! Utworzyles kolekcje: " <<
        user1.getUserCollection().at(user1.getCreatedCollections()).getName() << ".\n";
        user1.setCreatedCollections(user1.getCreatedCollections()+1);
        exit_to_menu();
    }
}


void CollectionManager::add_item(){
    system("cls");
    if(user1.getCreatedCollections() == 0){
        collection_not_created();
    }
    else{
        std::cout << "Do ktorej kolekcji chcesz dodac przedmiot?" << std::endl;
        for (int i=0; i < user1.getCreatedCollections(); ++i){
            std::cout << i+1 << ": " << user1.getUserCollection().at(i).getName() << std::endl;
        }
        int flag;
        while (flag <= 0 || flag > user1.getCreatedCollections()){
            std::cout << std::endl << "Wybierz numer kolekcji z wyzej wymienionych: ";
            while(!(std::cin >> flag)){
                std::cout << std::endl << "Wybierz numer kolekcji z wyzej wymienionych: ";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
        }
        std::string item_type;
        while (item_type != "k" && item_type != "f" && item_type != "a"){
            std::cout << std::endl << user1.getName() << " co chcesz dodac do swojej kolekcji " <<
            user1.getUserCollection().at(flag-1).getName() <<
            "?\n\n(ksiazka - nacisnij k; film - nacisnij f; album muzyczny - nacisnij a): ";
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
                "Mozesz modyfikowac istniejace pozycje. \n";
                exit_to_menu();
            }
        }
        else if (item_type == "f"){
            if(user1.getUserCollection().at(flag-1).getMovieQuantity()<user1.getUserCollection().at(flag-1).getQuantity()){
                user1.getUserCollection().at(flag-1).getMovieCollection().at(user1.getUserCollection().at(flag-1).getMovieQuantity()).write_data();
                user1.getUserCollection().at(flag-1).setMovieQuantity(user1.getUserCollection().at(flag-1).getMovieQuantity()+1);
            }
            else{
                std::cout << "Nie mozesz dodac nowego filmu. Posiadasz juz maksymalna ilosc filmow w tej kolekcji.\n" <<
                "Mozesz modyfikowac istniejace pozycje. \n";
                exit_to_menu();
            }
        }
        else {
            if(user1.getUserCollection().at(flag-1).getAlbumQuantity()<user1.getUserCollection().at(flag-1).getQuantity()){
                user1.getUserCollection().at(flag-1).getAlbumCollection().at(user1.getUserCollection().at(flag-1).getAlbumQuantity()).write_data();
                user1.getUserCollection().at(flag-1).setAlbumQuantity(user1.getUserCollection().at(flag-1).getAlbumQuantity()+1);
            }
            else{
                std::cout << "Nie mozesz dodac nowego filmu. Posiadasz juz maksymalna ilosc filmow w tej kolekcji.\n" <<
                "Mozesz modyfikowac istniejace pozycje. \n";
                exit_to_menu();
            }
        }
        std::cout << "Pozycja dodana do twojej kolekcji o nazwie: " << user1.getUserCollection().at(flag-1).getName() << ".\n";
        std::cout << std::endl <<"W tej chwili w kolekcji " << user1.getUserCollection().at(flag-1).getName() << " znajduje sie " <<
        user1.getUserCollection().at(flag-1).getBookQuantity() << " ksiazek/ki, " << user1.getUserCollection().at(flag-1).getMovieQuantity() <<
        " filmy/ow, i " << user1.getUserCollection().at(flag-1).getAlbumQuantity() << " albumy/ow.\n";
        exit_to_menu();
    }
}


void CollectionManager::display_collection(){
    system("cls");
    if(user1.getCreatedCollections() == 0){
        collection_not_created();
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
    exit_to_menu();
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
        std::cout << std::endl << "KSIAZKI we wszystkich kolekcjach:" << std::endl << std::endl;
        for(int i = 0; i < user1.getCreatedCollections(); ++i ){
            for(int j=0; j < user1.getUserCollection().at(i).getBookQuantity(); ++j){
                if(user1.getUserCollection().at(i).getBookQuantity()>0){
                    std::cout << "Kolekcja: " << user1.getUserCollection().at(i).getName() << std::endl;
                }
                user1.getUserCollection().at(i).getBookCollection().at(j).display_data();
                ++ counter;
            }
        }
        if ((counter == 0)){ std::cout << "W twoich kolekcjach nie ma ani jednej ksiazki." << std::endl << std::endl; }
    }
    else if(item_type == "f"){
        std::cout << std::endl << "FILMY we wszystkich kolekcjach:" << std::endl << std::endl;
        for(int i = 0; i < user1.getCreatedCollections(); ++i ){
            for(int j=0; j < user1.getUserCollection().at(i).getMovieQuantity(); ++j){
                user1.getUserCollection().at(i).getMovieCollection().at(j).display_data();
                ++ counter;
            }
        }
        if ((counter == 0)){ std::cout << "W twoich kolekcjach nie ma ani jednego filmu." << std::endl << std::endl; }
    }
    else{
        std::cout << std::endl << "ALBUMY we wszystkich kolekcjach:" << std::endl << std::endl;
        for(int i = 0; i < user1.getCreatedCollections(); ++i ){
            for(int j=0; j < user1.getUserCollection().at(i).getAlbumQuantity(); ++j){
                user1.getUserCollection().at(i).getAlbumCollection().at(j).display_data();
                ++ counter;
            }
        }
        if ((counter == 0)){ std::cout << "W twoich kolekcjach nie ma ani jednego albumu." << std::endl << std::endl; }
    }
    exit_to_menu();
}


void CollectionManager::change_collection_name(){
    system("cls");
    if(user1.getCreatedCollections() == 0){
        std::cout << "Aby zmienic nazwe kolekcji, musisz wczesniej utworzyc chociaz jedna kolekcje.\n";
        exit_to_menu();
    }
    else{
        std::cout << "Ktorej kolekcji chcesz zmienic nazwe?" << std::endl;
        for (int i=0; i < user1.getCreatedCollections(); ++i){
            std::cout << i+1 << ": " << user1.getUserCollection().at(i).getName() << std::endl;
        }
        int flag;
        while (flag <= 0 || flag > user1.getCreatedCollections()){
            std::cout << std::endl << "Wybierz numer kolekcji z wyzej wymienionych: ";
            while(!(std::cin >> flag)){
                std::cout << std::endl << "Wybierz numer kolekcji z wyzej wymienionych: ";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
        }
        std::cout << "Jaka nowa nazwe chcesz nadac kolekcji " << user1.getUserCollection().at(flag-1).getName() << "?: ";
        std::string collection_name;
        std::cin >> collection_name;
        user1.getUserCollection().at(flag-1).setName(collection_name);
        std::cout << std::endl << "Gratuluje! Zmieniles nazwe kolekcji. Nowa nazwa to: " <<
        user1.getUserCollection().at(flag-1).getName() << ".";
        exit_to_menu();
    }
}


void CollectionManager::search_item(){
    system("cls");
    if(user1.getCreatedCollections() == 0){
        collection_not_created();
    }
    else{
        std::string search_name;
        std::cout << "Wpisz szukana fraze: ";
        std::cin.get();
        getline(std::cin, search_name);
        int counter = 0;
        size_t position;
        std::cout << std::endl << "Znalezione przedmioty z podana fraza w tytule:" << std::endl << std::endl;
        for(int i = 0; i < user1.getCreatedCollections(); ++i ){
            for(int j=0; j < user1.getUserCollection().at(i).getBookQuantity(); ++j){
                if(user1.getUserCollection().at(i).getBookQuantity()>0){
                    position = (user1.getUserCollection().at(i).getBookCollection().at(j).getTitle()).find(search_name);
                    if (position !=std::string::npos){
                        std::cout << "Kolekcja: " << user1.getUserCollection().at(i).getName() << std::endl;
                        user1.getUserCollection().at(i).getBookCollection().at(j).display_data();
                        ++ counter;
                    }
                }
            }
            for(int k=0; k < user1.getUserCollection().at(i).getMovieQuantity(); ++k){
                if(user1.getUserCollection().at(i).getMovieQuantity()>0){
                    position = (user1.getUserCollection().at(i).getMovieCollection().at(k).getTitle()).find(search_name);
                    if (position !=std::string::npos){
                        std::cout << "Kolekcja: " << user1.getUserCollection().at(i).getName() << std::endl;
                        user1.getUserCollection().at(i).getMovieCollection().at(k).display_data();
                        ++ counter;
                    }
                }
            }
            for(int l=0; l < user1.getUserCollection().at(i).getAlbumQuantity(); ++l){
                if(user1.getUserCollection().at(i).getAlbumQuantity()>0){
                    position = (user1.getUserCollection().at(i).getAlbumCollection().at(l).getTitle()).find(search_name);
                    if (position !=std::string::npos){
                        std::cout << "Kolekcja: " << user1.getUserCollection().at(i).getName() << std::endl;
                        user1.getUserCollection().at(i).getAlbumCollection().at(l).display_data();
                        ++ counter;
                    }
                }
            }
        }
        if ((counter == 0)){ std::cout << "W twoich kolekcjach nie ma przedmiotu zawierajacego podana fraze." << std::endl << std::endl; }
        exit_to_menu();
    }

}


void CollectionManager::update_item(){
    system("cls");
    if(user1.getCreatedCollections() == 0){
        collection_not_created();
    }
    else{
        std::cout << "W ktorej kolekcji chcesz uaktualnic przedmiot?" << std::endl;
        for (int i=0; i < user1.getCreatedCollections(); ++i){
            std::cout << i+1 << ": " << user1.getUserCollection().at(i).getName() << std::endl;
        }
        int flag;
        while (flag <= 0 || flag > user1.getCreatedCollections()){
            std::cout << std::endl << "Wybierz numer kolekcji z wyzej wymienionych: ";
            while(!(std::cin >> flag)){
                std::cout << std::endl << "Wybierz numer kolekcji z wyzej wymienionych: ";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
        }
        std::string item_type;
        while (item_type != "k" && item_type != "f" && item_type != "a"){
            std::cout << std::endl << user1.getName() << " jaki rodzaj przedmiotu chcesz zmienic w swojej kolekcji " <<
            user1.getUserCollection().at(flag-1).getName() <<
            "?\n\n(ksiazka - nacisnij k; film - nacisnij f; album muzyczny - nacisnij a): ";
            std::cin >> item_type;
        }
        std::cout << std::endl;
        if(item_type == "k"){
            std::cout << "KSIAZKI:" << std::endl << std::endl;
            for(int i=0; i < user1.getUserCollection().at(flag-1).getBookQuantity(); ++i){
                std::cout << "Ksiazka nr " << i+1 << std::endl << std::endl;
                user1.getUserCollection().at(flag-1).getBookCollection().at(i).display_data();
            }
            if(user1.getUserCollection().at(flag-1).getBookQuantity() == 0){
                std::cout << "Nie masz zadnych ksiazek w tej kolekcji." << std::endl;
                exit_to_menu();
            }
            else{
                int book_number;
                while (book_number <= 0 || book_number > user1.getUserCollection().at(flag-1).getBookQuantity()){
                    std::cout << std::endl << "Wybierz numer ksiazki, ktora chcesz zmodyfikowac: ";
                    while(!(std::cin >> book_number)){
                        std::cout << std::endl << "Wybierz numer ksiazki, ktora chcesz zmodyfikowac: ";
                        std::cin.clear();
                        std::cin.ignore(100, '\n');
                    }
                }
                std::cout << std::endl;
                user1.getUserCollection().at(flag-1).getBookCollection().at(book_number-1).write_data();
                std::cout << std::endl << "Pozycja zmieniona pomyslnie." << std::endl;
                exit_to_menu();
            }
        }
        else if(item_type == "f"){
            std::cout << "FILMY:" << std::endl << std::endl;
            for(int i=0; i < user1.getUserCollection().at(flag-1).getMovieQuantity(); ++i){
                std::cout << "Film nr " << i+1 << std::endl << std::endl;
                user1.getUserCollection().at(flag-1).getMovieCollection().at(i).display_data();
            }
            if(user1.getUserCollection().at(flag-1).getMovieQuantity() == 0){
                std::cout << "Nie masz zadnych filmow w tej kolekcji." << std::endl;
                exit_to_menu();
            }
            else{
                int movie_number;
                while (movie_number <= 0 || movie_number > user1.getUserCollection().at(flag-1).getMovieQuantity()){
                    std::cout << std::endl << "Wybierz numer filmu, ktory chcesz zmodyfikowac: ";
                    while(!(std::cin >> movie_number)){
                        std::cout << std::endl << "Wybierz numer filmu, ktory chcesz zmodyfikowac: ";
                        std::cin.clear();
                        std::cin.ignore(100, '\n');
                    }
                }
                std::cout << std::endl;
                user1.getUserCollection().at(flag-1).getMovieCollection().at(movie_number-1).write_data();
                std::cout << std::endl << "Pozycja zmieniona pomyslnie." << std::endl;
                exit_to_menu();
            }
        }
        else if(item_type == "a"){
            std::cout << "ALBUMY:" << std::endl << std::endl;
            for(int i=0; i < user1.getUserCollection().at(flag-1).getAlbumQuantity(); ++i){
                std::cout << "Album nr " << i+1 << std::endl << std::endl;
                user1.getUserCollection().at(flag-1).getAlbumCollection().at(i).display_data();
            }
            if(user1.getUserCollection().at(flag-1).getAlbumQuantity() == 0){
                std::cout << "Nie masz zadnych albomow w tej kolekcji." << std::endl;
                exit_to_menu();
            }
            else{
                int album_number;
                while (album_number <= 0 || album_number > user1.getUserCollection().at(flag-1).getAlbumQuantity()){
                    std::cout << std::endl << "Wybierz numer albumu, ktory chcesz zmodyfikowac: ";
                    while(!(std::cin >> album_number)){
                        std::cout << std::endl << "Wybierz numer albumu, ktory chcesz zmodyfikowac: ";
                        std::cin.clear();
                        std::cin.ignore(100, '\n');
                    }
                }
                std::cout << std::endl;
                user1.getUserCollection().at(flag-1).getAlbumCollection().at(album_number-1).write_data();
                std::cout << std::endl << "Pozycja zmieniona pomyslnie." << std::endl;
                exit_to_menu();
            }
        }
    }
}


void CollectionManager::statistics(){
    system("cls");
    int counter_book = 0;
    int counter_movie = 0;
    int counter_album = 0;
    for(int i = 0; i < user1.getCreatedCollections(); ++i ){
        for(int j=0; j < user1.getUserCollection().at(i).getBookQuantity(); ++j){
            ++ counter_book;
        }
        for(int k=0; k < user1.getUserCollection().at(i).getMovieQuantity(); ++k){
            ++ counter_movie;
        }
        for(int l=0; l < user1.getUserCollection().at(i).getAlbumQuantity(); ++l){
            ++ counter_album;
        }
    }
    std::cout << "W swoich kolekcjach posiadasz: " << std::endl;
    std::cout << counter_book << " ksiazki/ek." << std::endl;
    std::cout << counter_movie << " filmy/ow." << std::endl;
    std::cout << counter_album << " albumy/ow." << std::endl;
    exit_to_menu();
}


void CollectionManager::delete_item(){
    system("cls");
    if(user1.getCreatedCollections() == 0){
        collection_not_created();
    }
    else{
        std::cout << "W ktorej kolekcji chcesz usunac przedmiot?" << std::endl;
        for (int i=0; i < user1.getCreatedCollections(); ++i){
            std::cout << i+1 << ": " << user1.getUserCollection().at(i).getName() << std::endl;
        }
        int flag;
        while (flag <= 0 || flag > user1.getCreatedCollections()){
            std::cout << std::endl << "Wybierz numer kolekcji z wyzej wymienionych: ";
            while(!(std::cin >> flag)){
                std::cout << std::endl << "Wybierz numer kolekcji z wyzej wymienionych: ";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
        }
        std::string item_type;
        while (item_type != "k" && item_type != "f" && item_type != "a"){
            std::cout << std::endl << user1.getName() << " jaki rodzaj przedmiotu chcesz usunac w swojej kolekcji " <<
            user1.getUserCollection().at(flag-1).getName() <<
            "?\n\n(ksiazka - nacisnij k; film - nacisnij f; album muzyczny - nacisnij a): ";
            std::cin >> item_type;
        }
        std::cout << std::endl;
        if(item_type == "k"){
            std::cout << "KSIAZKI:" << std::endl << std::endl;
            for(int i=0; i < user1.getUserCollection().at(flag-1).getBookQuantity(); ++i){
                std::cout << "Ksiazka nr " << i+1 << std::endl << std::endl;
                user1.getUserCollection().at(flag-1).getBookCollection().at(i).display_data();
            }
            if(user1.getUserCollection().at(flag-1).getBookQuantity() == 0){
                std::cout << "Nie masz zadnych ksiazek w tej kolekcji." << std::endl;
                exit_to_menu();
            }
            else{
                int book_number;
                while (book_number <= 0 || book_number > user1.getUserCollection().at(flag-1).getBookQuantity()){
                    std::cout << std::endl << "Wybierz numer ksiazki, ktora chcesz usunac: ";
                    while(!(std::cin >> book_number)){
                        std::cout << std::endl << "Wybierz numer ksiazki, ktora chcesz usunac: ";
                        std::cin.clear();
                        std::cin.ignore(100, '\n');
                    }
                }
                std::cout << std::endl;
                user1.getUserCollection().at(flag-1).getBookCollection().erase(user1.getUserCollection().at(flag-1).getBookCollection().begin() + book_number - 1);
                user1.getUserCollection().at(flag-1).setBookQuantity(user1.getUserCollection().at(flag-1).getBookQuantity() - 1);
                Book blank_book;
                user1.getUserCollection().at(flag-1).getBookCollection().push_back(blank_book);
                std::cout << std::endl << "Pozycja usunieta pomyslnie." << std::endl;
                exit_to_menu();
            }
        }
        else if(item_type == "f"){
            std::cout << "FILMY:" << std::endl << std::endl;
            for(int i=0; i < user1.getUserCollection().at(flag-1).getMovieQuantity(); ++i){
                std::cout << "Film nr " << i+1 << std::endl << std::endl;
                user1.getUserCollection().at(flag-1).getMovieCollection().at(i).display_data();
            }
            if(user1.getUserCollection().at(flag-1).getMovieQuantity() == 0){
                std::cout << "Nie masz zadnych filmow w tej kolekcji." << std::endl;
                exit_to_menu();
            }
            else{
                int movie_number;
                while (movie_number <= 0 || movie_number > user1.getUserCollection().at(flag-1).getMovieQuantity()){
                    std::cout << std::endl << "Wybierz numer filmu, ktory chcesz usunac: ";
                    while(!(std::cin >> movie_number)){
                        std::cout << std::endl << "Wybierz numer filmu, ktory chcesz usunac: ";
                        std::cin.clear();
                        std::cin.ignore(100, '\n');
                    }
                }
                std::cout << std::endl;
                user1.getUserCollection().at(flag-1).getMovieCollection().erase(user1.getUserCollection().at(flag-1).getMovieCollection().begin() + movie_number - 1);
                user1.getUserCollection().at(flag-1).setMovieQuantity(user1.getUserCollection().at(flag-1).getMovieQuantity() - 1);
                Movie blank_movie;
                user1.getUserCollection().at(flag-1).getMovieCollection().push_back(blank_movie);
                std::cout << std::endl << "Pozycja usunieta pomyslnie." << std::endl;
                exit_to_menu();
            }
        }
        else if(item_type == "a"){
            std::cout << "ALBUMY:" << std::endl << std::endl;
            for(int i=0; i < user1.getUserCollection().at(flag-1).getAlbumQuantity(); ++i){
                std::cout << "Album nr " << i+1 << std::endl << std::endl;
                user1.getUserCollection().at(flag-1).getAlbumCollection().at(i).display_data();
            }
            if(user1.getUserCollection().at(flag-1).getAlbumQuantity() == 0){
                std::cout << "Nie masz zadnych albomow w tej kolekcji." << std::endl;
                exit_to_menu();
            }
            else{
                int album_number;
                while (album_number <= 0 || album_number > user1.getUserCollection().at(flag-1).getAlbumQuantity()){
                    std::cout << std::endl << "Wybierz numer albumu, ktory chcesz usunac: ";
                    while(!(std::cin >> album_number)){
                        std::cout << std::endl << "Wybierz numer albumu, ktory chcesz usunac: ";
                        std::cin.clear();
                        std::cin.ignore(100, '\n');
                    }
                }
                std::cout << std::endl;
                user1.getUserCollection().at(flag-1).getAlbumCollection().erase(user1.getUserCollection().at(flag-1).getAlbumCollection().begin() + album_number - 1);
                user1.getUserCollection().at(flag-1).setAlbumQuantity(user1.getUserCollection().at(flag-1).getAlbumQuantity() - 1);
                Album blank_album;
                user1.getUserCollection().at(flag-1).getAlbumCollection().push_back(blank_album);
                std::cout << std::endl << "Pozycja usunieta pomyslnie." << std::endl;
                exit_to_menu();
            }
        }
    }
}


void CollectionManager::delete_collection(){
    system("cls");
    if(user1.getCreatedCollections() == 0){
        std::cout << "Aby usunac kolekcje, musisz wczesniej utworzyc chociaz jedna kolekcje.\n";
        exit_to_menu();
    }
    else{
        std::cout << "Ktora kolekcje chcesz usunac?" << std::endl;
        for (int i=0; i < user1.getCreatedCollections(); ++i){
            std::cout << i+1 << ": " << user1.getUserCollection().at(i).getName() << std::endl;
        }
        int flag;
        while (flag <= 0 || flag > user1.getCreatedCollections()){
            std::cout << std::endl << "Wybierz numer kolekcji, ktora chcesz usunac, z wyzej wymienionych: ";
            while(!(std::cin >> flag)){
                std::cout << std::endl << "Wybierz numer kolekcji, ktora chcesz usunac, z wyzej wymienionych: ";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
        }
        std::cout << std::endl;
        user1.getUserCollection().erase(user1.getUserCollection().begin() + flag - 1);
        user1.setCreatedCollections(user1.getCreatedCollections() - 1);
        Collection blank_collection;
        user1.getUserCollection().push_back(blank_collection);
        std::cout << std::endl << "Kolekcja usunieta pomyslnie." << std::endl;
        exit_to_menu();
    }
}


void CollectionManager::save_to_file(){
    system("cls");
    std::fstream file;
    file.open("Kolekcja.txt", std::ios::out);
    file << "Uzytkownik: " << user1.getName() << " " << user1.getSurname() << std::endl << std::endl;
    for(int i = 0; i < user1.getCreatedCollections(); ++i ){
        file << "KOLEKCJA: " << user1.getUserCollection().at(i).getName() << std::endl << std::endl;
        file << "KSIAZKI: " << std::endl << std::endl;
        for(int j=0; j < user1.getUserCollection().at(i).getBookQuantity(); ++j){
            file << "Typ przedmiotu w kolekcji: " << user1.getUserCollection().at(i).getBookCollection().at(j).getItemType() << std::endl;
            file << "Tytul: " << user1.getUserCollection().at(i).getBookCollection().at(j).getTitle() << std::endl;
            file << "Gatunek: " << user1.getUserCollection().at(i).getBookCollection().at(j).getGenre() << std::endl;
            file << "Rok wydania: " << user1.getUserCollection().at(i).getBookCollection().at(j).getYear() << std::endl;
            file << "Cena: " << user1.getUserCollection().at(i).getBookCollection().at(j).getPrice() << std::endl;
            file << "Autor: " << user1.getUserCollection().at(i).getBookCollection().at(j).getAuthor() << std::endl;
            file << "Liczba stron: " << user1.getUserCollection().at(i).getBookCollection().at(j).getPages() << std::endl << std::endl;
        }
        file << "FILMY: " << std::endl << std::endl;
        for(int k=0; k < user1.getUserCollection().at(i).getMovieQuantity(); ++k){
            file << "Typ przedmiotu w kolekcji: " << user1.getUserCollection().at(i).getMovieCollection().at(k).getItemType() << std::endl;
            file << "Tytul: " << user1.getUserCollection().at(i).getMovieCollection().at(k).getTitle() << std::endl;
            file << "Gatunek: " << user1.getUserCollection().at(i).getMovieCollection().at(k).getGenre() << std::endl;
            file << "Rok wydania: " << user1.getUserCollection().at(i).getMovieCollection().at(k).getYear() << std::endl;
            file << "Cena: " << user1.getUserCollection().at(i).getMovieCollection().at(k).getPrice() << std::endl;
            file << "Rezyser: " << user1.getUserCollection().at(i).getMovieCollection().at(k).getDirector() << std::endl;
            file << "Scenarzysta: " << user1.getUserCollection().at(i).getMovieCollection().at(k).getScriptWriter() << std::endl;
            file << "Dlugosc filmu: " << user1.getUserCollection().at(i).getMovieCollection().at(k).getLength() << " minut" << std::endl << std::endl;
        }
        file << "ALBUMY: " << std::endl << std::endl;
        for(int l=0; l < user1.getUserCollection().at(i).getAlbumQuantity(); ++l){
            file << "Typ przedmiotu w kolekcji: " << user1.getUserCollection().at(i).getAlbumCollection().at(l).getItemType() << std::endl;
            file << "Tytul: " << user1.getUserCollection().at(i).getAlbumCollection().at(l).getTitle() << std::endl;
            file << "Gatunek: " << user1.getUserCollection().at(i).getAlbumCollection().at(l).getGenre() << std::endl;
            file << "Rok wydania: " << user1.getUserCollection().at(i).getAlbumCollection().at(l).getYear() << std::endl;
            file << "Cena: " << user1.getUserCollection().at(i).getAlbumCollection().at(l).getPrice() << std::endl;
            file << "Autor: " << user1.getUserCollection().at(i).getAlbumCollection().at(l).getAuthor() << std::endl;
            file << "Dlugosc albumu: " << user1.getUserCollection().at(i).getAlbumCollection().at(l).getLength() << std::endl << std::endl;
        }
    }
    file.close();
    std::cout << "Kolekcje zapisane do pliku." << std::endl;
    exit_to_menu();
}


void CollectionManager::manage(){
    name_change();
    int wybor;
    while (wybor != 12){
        std::cout << user1.getName() << " przysluguje Ci " << user1.getMaxCollections() <<
        " osobnych kolekcji, ktore moga reprezentowac rozne kategorie (np. wesole, sensacyjne itd.). \nMozesz tez" <<
        " korzystac z jednej ogolnej kolekcji. W kazdej z nich mozesz zapisywac swoje ulubione ksiazki, filmy \ni" <<
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
        std::cout << "6.  Szukaj przedmiotu w kolekcjach."; std::cout << std::setw(29) << "(nacisnij:  6)" << std::endl;
        std::cout << "7.  Zmodyfikuj przedmiot w kolekcji."; std::cout << std::setw(28) << "(nacisnij:  7)" << std::endl;
        std::cout << "8.  Pokaz statystyki przedmiotow."; std::cout << std::setw(31) << "(nacisnij:  8)" << std::endl;
        std::cout << "9.  Usun przedmiot z kolekcje."; std::cout << std::setw(34) << "(nacisnij:  9)" << std::endl;
        std::cout << "10. Usun kolekcji."; std::cout << std::setw(46) << "(nacisnij: 10)" << std::endl;
        std::cout << "11. Zapisz kolekcje do pliku."; std::cout << std::setw(35) << "(nacisnij: 11)" << std::endl;
        std::cout << "12. Zakoncz dzialanie programu."; std::cout << std::setw(33) << "(nacisnij: 12)" << std::endl << std::endl;
        std::cout << "Podaj numer z powyzszej listy: ";
        while(!(std::cin >> wybor)){
            std::cout << "Podaj numer z powyzszej listy: ";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        if(wybor<1 || wybor>12){
            system("cls");
        }
        else{
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
                search_item();
                break;
            case 7:
                update_item();
                break;
            case 8:
                statistics();
                break;
            case 9:
                delete_item();
                break;
            case 10:
                delete_collection();
                break;
            case 11:
                save_to_file();
                break;
            case 12:
                exit(0);
                break;
            }
        }
    }
}
