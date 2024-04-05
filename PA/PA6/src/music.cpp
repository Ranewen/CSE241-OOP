#include "music.hpp"
#include <string>
#include <forward_list>
#include <sstream>

using std::stringstream;
using std::forward_list;
using std::string;

namespace Catalog
{
    
    Music::Music() : title{}, artists{}, year{}, genre{}
    {
        // Default constructor
    }

    Music::Music(const Music &music) : title(music.title), artists(music.artists), year(music.year), genre(music.genre)
    {
        // Copy constructor
    }
    
    Music::Music(const forward_list<string> *fields)
    {
        // Constructor that takes a forward list of fields
        auto it = fields->begin();
        genre = *it++;     // Extract genre
        year = std::stoi(*it++);     // Extract year
        artists = *it++;     // Extract artists
        title = *it++;     // Extract title
    }

    Music::Music(const string &_title, const string &_artists, int _year, const string &_genre)
	: title(_title), artists(_artists), year(_year), genre(_genre)
    {
        // Constructor that takes individual fields
    }
    
    bool Music::CompareTitle(const Music &music1, const Music &music2) {
        // Static comparison function to compare Music objects based on title
	    return music1.title < music2.title;
    }

    bool Music::CompareArtists(const Music &music1, const Music &music2) {
        // Static comparison function to compare Music objects based on artists
	    return music1.artists < music2.artists;
    }

    bool Music::CompareYear(const Music &music1, const Music &music2) {
        // Static comparison function to compare Music objects based on year
	    return music1.year < music2.year;
    }
    
    bool Music::CompareGenre(const Music &music1, const Music &music2) {
        // Static comparison function to compare Music objects based on genre
	    return music1.genre < music2.genre;
    }

    stringstream & operator<<(stringstream &out, const Music &music){
        // Overloaded stream insertion operator to output Music object to a stringstream
	    out << '"' << music.title << "\" \"" << music.artists << "\" \"" << music.year << "\" \"" 
	        << music.genre << '"' << std::endl;
	    return out;
    }
}

