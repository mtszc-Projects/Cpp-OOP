#include "user.h"
#include <iostream>

const int User::max_collections = 2;

User::User(std::string n, std::string s, int cc) : name(n), surname(s), created_collections(cc){
}

User::~User(){
}

//OVERLOADED OPERATORS
std::ostream & operator<<(std::ostream & output, User & u){
        output << u.name << " " << u.surname << " obecnie posiadasz: " << u.getCreatedCollections() << " kolekcje/i." << std::endl;
        for(int i=0; i<(int)u.getCreatedCollections(); ++i){
            output << "- " << u.getUserCollection().at(i).getName() << std::endl;
        }
        return output;
}
