#ifndef MUSIC_HPP
#define MUSIC_HPP

#include "catalog.hpp"  // Include the base catalog header
#include <string>
#include <forward_list>
#include <sstream>

using std::forward_list;
using std::string;
using std::stringstream;

namespace Catalog
{

    class Music : public CatalogBase  // Music class inherits from the CatalogBase
    {
    	public:
        	Music();  // Default constructor
        	Music(const Music &music);  // Copy constructor
        	Music(const forward_list<string> *fields);  // Constructor with a list of fields
        	Music(const string &_title, const string &_artists, int _year, const string &_genre);  // Constructor with individual fields

        	string GetTitle() const { return title; }  // Getter method for the title
        	string GetArtists() const { return artists; }  // Getter method for the artists
        	int GetYear() const { return year; }  // Getter method for the year
        	string GetGenre() const { return genre; }  // Getter method for the genre

        	static int GetFieldCount() { return 4; }  // Static method to get the number of fields in Music catalog
        	static bool CompareTitle(const Music &music1, const Music &music2);  // Static method to compare titles
        	static bool CompareArtists(const Music &music1, const Music &music2);  // Static method to compare artists
        	static bool CompareYear(const Music &music1, const Music &music2);  // Static method to compare years
        	static bool CompareGenre(const Music &music1, const Music &music2);  // Static method to compare genres

        	friend stringstream &operator<<(stringstream &out, const Music &music);  // Overloaded stream insertion operator to output Music object

    	private:
        	string title;  // Title of the music
        	string artists;  // Artists or band of the music
        	int year;  // Year of release
        	string genre;  // Genre of the music
    };
}

#endif // MUSIC_HPP
