#ifndef MOVIE_H__
#define MOVIE_H__

#include "item.h"

class Movie : public Item{
    std::string director;
    std::string script_writer;
public:
    Movie(std::string = "Rezyser nieznany", std:: string = "Scenarzysta nieznany");
    ~Movie();

    //GETTERS
    std::string  getDirector() const { return director; };
    std::string  getScriptWriter() const { return script_writer; };

    //SETTERS
    void  setDirector(std::string d) { director = d; };
    void  setScriptWriter(std::string sw) { script_writer = sw; };

    //METODS
    void write_data() override;
    void display_data() const override;
};

#endif // MOVIE_H__
