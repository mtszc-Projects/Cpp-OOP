#include "user.h"
#include <iostream>

const int User::max_collections = 2;

User::User(std::string n, std::string s) : name(n), surname(s){
}

User::~User(){
}
