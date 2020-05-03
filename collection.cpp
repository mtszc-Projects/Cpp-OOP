#include "collection.h"
#include <iostream>

const int Collection::quantity = 2;

Collection::Collection(std::string n, int bq, int aq, int mq) : name(n), book_quantity(bq), album_quantity(aq), movie_quntity(mq){
}

Collection::~Collection(){
}
