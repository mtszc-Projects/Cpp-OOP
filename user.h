#ifndef USER_H__
#define USER_H__

#include <string>
#include <vector>
#include <iostream>

#include "collection.h"

class User{
    std::string name;
    std::string surname;
    static const int max_collections;
    int created_collections;
    std::vector <Collection> user_collection = std::vector <Collection>(max_collections);
public:
    User(std::string = "Anon", std::string = "Anonim", int = 0);
    ~User();

    //GETTERS
    std::string  getName() const { return name; };
    std::string  getSurname() const { return surname; };
    int getMaxCollections() const { return max_collections; };
    int getCreatedCollections() const { return created_collections; };
    std::vector <Collection> &getUserCollection(){ return user_collection; };

    //SETTERS
    void setName(std::string n) { name = n; };
    void setSurname(std::string s) { surname = s; };
    void setCreatedCollections(int cr_coll) { created_collections = cr_coll; };

    //OVERLOADED OPERATORS
    friend std::ostream & operator<<(std::ostream & output, User & u);
};

#endif // USER_H__
