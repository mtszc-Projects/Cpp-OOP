#include "collection.h"
#include <iostream>

const int Collection::quantity = 2;

Collection::Collection(std::string n, int bq, int aq, int mq) : name(n), book_quantity(bq), album_quantity(aq), movie_quantity(mq){
}

Collection::Collection(const Collection & collection){
    name = collection.name;
    book_quantity = collection.book_quantity;
    album_quantity = collection.album_quantity;
    movie_quantity = collection.movie_quantity;
    for(int i = 0 ; i < (int)book_collection.size() ; ++i){
		book_collection.at(i) = collection.book_collection.at(i);
	}
    for(int i = 0 ; i < (int)album_collection.size() ; ++i){
		album_collection.at(i) = collection.album_collection.at(i);
	}
    for(int i = 0 ; i < (int)movie_collection.size() ; ++i){
		movie_collection.at(i) = collection.movie_collection.at(i);
	}
}

Collection::~Collection(){
}

Collection & Collection::operator=(const Collection & collection){
	if(&collection == this) return *this;
    name = collection.name;
    book_quantity = collection.book_quantity;
    album_quantity = collection.album_quantity;
    movie_quantity = collection.movie_quantity;
    for(int i = 0 ; i < (int)book_collection.size() ; ++i){
		book_collection.at(i) = collection.book_collection.at(i);
	}
    for(int i = 0 ; i < (int)album_collection.size() ; ++i){
		album_collection.at(i) = collection.album_collection.at(i);
	}
    for(int i = 0 ; i < (int)movie_collection.size() ; ++i){
		movie_collection.at(i) = collection.movie_collection.at(i);
	}
    return *this;
}
