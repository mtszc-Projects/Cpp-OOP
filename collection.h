#ifndef COLLECTION_H__
#define COLLECTION_H__
#include <string>
#include <vector>
#include "item.h"
#include "book.h"
#include "album.h"
#include "movie.h"

class Collection{
    std::string name;
    static const int quantity;
    int book_quantity;
    int album_quantity;
    int movie_quntity;
    std::vector <Book> book_collection = std::vector <Book>(quantity);
    std::vector <Album> album_collection = std::vector <Album>(quantity);
    std::vector <Movie> movie_collection = std::vector <Movie>(quantity);
public:

    Collection();
    ~Collection();

    //GETTERS
    std::string getName() const { return name; };
    int getQuantity() const { return quantity; }
    int getBookQuantity() const { return book_quantity; };
    int getAlbumQuantity() const { return album_quantity; };
    int getMovieQuantity() const { return movie_quntity; };
    std::vector <Book> &getBookCollection(){ return book_collection; };
    std::vector <Album> &getAlbumCollection(){ return album_collection; };
    std::vector <Movie> &getMovieCollection(){ return movie_collection; };

    //SETTERS
    void  setName(std::string n) { name = n; };
    void  setBookQuantity(int bq) { book_quantity = bq; };
    void  setAlbumQuantity(int aq) { album_quantity = aq; };
    void  setMovieQuantity(int mq) { movie_quntity = mq; };

};

#endif // COLLECTION_H__
