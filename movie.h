#ifndef MOVIE_H__
#define MOVIE_H__

#include "item.h"

class Movie : public Item{
    std::string director;
    std::string script_writer;
    int length;
public:
    Movie(std::string = "Rezyser nieznany", std:: string = "Scenarzysta nieznany", int = 0);
    explicit Movie(const Movie & movie);
    ~Movie();

    //GETTERS
    std::string getDirector() const { return director; };
    std::string getScriptWriter() const { return script_writer; };
    int getLength() const { return length; };

    //SETTERS
    void  setDirector(std::string d) { director = d; };
    void  setScriptWriter(std::string sw) { script_writer = sw; };
    void  setLength(int l) { length = l; };

    //METODS
    void write_data() override;
    void display_data() const override;

    //OVERLOADED OPERATORS
    Movie & operator=(const Movie & movie);
};

#endif // MOVIE_H__
