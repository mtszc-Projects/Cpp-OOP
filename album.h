#ifndef ALBUM_H__
#define ALBUM_H__

#include "item.h"

class Album : public Item{
    std::string  author;
    int length;
public:
    Album(std::string = "Autor nieznany", int = 0);
    explicit Album(const Album & album);
    ~Album();

    //GETTERS
    std::string  getAuthor() const { return author; };
    int getLength() const { return length; };

    //SETTERS
    void  setAuthor(std::string a) { author = a; };
    void  setLength(int l) { length = l; };

    //METODS
    void write_data() override;
    void display_data() const override;

    //OVERLOADED OPERATORS
    Album & operator=(const Album & album);
};

#endif // ALBUM_H__
