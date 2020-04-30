#ifndef ALBUM_H__
#define ALBUM_H__

#include "item.h"

class Album : public Item{
    std::string  author;
public:
    explicit Album(std::string = "Autor nieznany");
    ~Album();

    //GETTERS
    std::string  getAuthor() const { return author; };

    //SETTERS
    void  setAuthor(std::string a) { author = a; };

    //METODS
    void write_data() override;
    void display_data() const override;
};

#endif // ALBUM_H__
