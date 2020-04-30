#ifndef ITEM_H__
#define ITEM_H__

#include <string>

class Item{
protected:
    std::string  item_type;
    std::string  title;
    std::string  genre;
    int  year;
    int  price;
public:

    Item(std::string = "Brak danych", std::string = "Brak danych", std::string = "Brak danych", int = 0, int = 0);
    ~Item();

    //GETTERS
    std::string  getItemType() const { return item_type; };
    std::string  getTitle() const { return title; };
    std::string  getGenre() const { return genre; };
    int  getYear() const { return year; };
    int  getProce() const { return price; };

    //SETTERS
    void  setItemType(std::string it) { item_type = it; };
    void  setTitle(std::string t) { title = t; };
    void  setGenre(std::string g) { genre = g; };
    void  setYear(int y) { year = y; };
    void  setPrice(int p) { price = p; };

    //METODS
    virtual void write_data();
    virtual void display_data() const ;
};

#endif // ITEM_H__
