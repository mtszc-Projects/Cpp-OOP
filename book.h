#ifndef BOOK_H__
#define BOOK_H__

#include "item.h"

class Book : public Item{
    std::string  author;
    int pages;
public:
    explicit Book(std::string = "Autor nieznany", int = 0);
    explicit Book(const Book & book);
    ~Book();

    //GETTERS
    std::string getAuthor() const { return author; };
    int getPages() const { return pages; };

    //SETTERS
    void  setAuthor(std::string a) { author = a; };
    void  setPages(int p) { pages = p; };

    //METODS
    void write_data() override;
    void display_data() const override;

    //OVERLOADED OPERATORS
    Book & operator=(const Book & book);
};

#endif // BOOK_H__
