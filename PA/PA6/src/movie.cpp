#include "movie.hpp"
#include <string>
#include <forward_list>
#include <sstream>

using std::stringstream;
using std::forward_list;
using std::string;

namespace Catalog
{
    // Default constructor for Movie class
    Movie::Movie() : title{}, director{}, year{}, genre{}, starring{}
    {

    }

    // Copy constructor for Movie class
    Movie::Movie(const Movie &movie)
        : title(movie.title), director(movie.director), year(movie.year), genre(movie.genre), starring(movie.starring)
    {

    }

    // Constructor that takes a forward list of string fields and initializes a Movie object
    Movie::Movie(const forward_list<string> *fields)
    {
        auto it = fields->begin();
        starring = *it++; // Extract the starring field from the forward list
        genre = *it++; // Extract the genre field from the forward list
        year = std::stoi(*it++); // Extract the year field from the forward list and convert it to an integer
        director = *it++; // Extract the director field from the forward list
        title = *it++; // Extract the title field from the forward list
    }

    // Constructor that takes individual fields and initializes a Movie object
    Movie::Movie(const string &_title, const string &_director, int _year, const string &_genre, const string &_starring)
        : title(_title), director(_director), year(_year), genre(_genre), starring(_starring)
    {

    }

    // Comparison function to compare Movie objects based on their title
    bool Movie::CompareTitle(const Movie &movie1, const Movie &movie2)
    {
        return movie1.title < movie2.title;
    }

    // Comparison function to compare Movie objects based on their director
    bool Movie::CompareDirector(const Movie &movie1, const Movie &movie2)
    {
        return movie1.director < movie2.director;
    }

    // Comparison function to compare Movie objects based on their year
    bool Movie::CompareYear(const Movie &movie1, const Movie &movie2)
    {
        return movie1.year < movie2.year;
    }

    // Comparison function to compare Movie objects based on their genre
    bool Movie::CompareGenre(const Movie &movie1, const Movie &movie2)
    {
        return movie1.genre < movie2.genre;
    }

    // Comparison function to compare Movie objects based on their starring
    bool Movie::CompareStarring(const Movie &movie1, const Movie &movie2)
    {
        return movie1.starring < movie2.starring;
    }

    // Overloaded stream insertion operator to output Movie object to a stringstream
    stringstream & operator<<(stringstream &out, const Movie &movie)
    {
        out << '"' << movie.title << "\" \"" << movie.director << "\" \"" << movie.year << "\" \""
            << movie.genre << "\" \"" << movie.starring << '"' << std::endl;
        return out;
    }
}

