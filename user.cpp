#include "user.h"
#include <iostream>

const int User::max_collections = 3;

User::User(std::string n, std::string s, int cc) : name(n), surname(s), created_collections(cc){
}

User::User(const User & user){
    name = user.name;
    surname = user.surname;
    created_collections = user.created_collections;
    for(int i = 0 ; i < (int)user_collection.size() ; ++i){
		user_collection.at(i) = user.user_collection.at(i);
	}
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

User & User::operator=(const User & user){
	if(&user == this) return *this;
    name = user.name;
    surname = user.surname;
    created_collections = user.created_collections;
    for(int i = 0 ; i < (int)user_collection.size() ; ++i){
		user_collection.at(i) = user.user_collection.at(i);
	}
    return *this;
}
