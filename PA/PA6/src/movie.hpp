#ifndef MOVIE_HPP
#define MOVIE_HPP

#include "catalog.hpp"
#include <string>
#include <forward_list>
#include <sstream>

using std::forward_list;
using std::string;
using std::stringstream;

namespace Catalog
{

    class Movie : public CatalogBase
	{
		public:
	    	Movie(); // Default constructor
	    	Movie(const Movie &movie); // Copy constructor
	    	Movie(const forward_list<string> *fields); // Constructor that takes a forward list of fields
	    	Movie(const string &_title, const string &_director, int _year, const string &_genre, const string &_starring); // Constructor that takes individual fields

	    	string GetTitle() const{return title;} // Getter for the title
	    	string GetDirector() const{return director;} // Getter for the director
	    	int GetYear() const{return year;} // Getter for the year
	    	string GetGenre() const{return genre;} // Getter for the genre
	    	string GetStarring() const{return starring;} // Getter for the starring

	    	static int GetFieldCount() {return 5;} // Static function to get the number of fields in a Movie object
	    	static bool CompareTitle(const Movie &movie1, const Movie &movie2); // Static comparison function to compare Movie objects based on title
	    	static bool CompareDirector(const Movie &movie1, const Movie &movie2); // Static comparison function to compare Movie objects based on director
	    	static bool CompareYear(const Movie &movie1, const Movie &movie2); // Static comparison function to compare Movie objects based on year
	    	static bool CompareGenre(const Movie &movie1, const Movie &movie2); // Static comparison function to compare Movie objects based on genre
	    	static bool CompareStarring(const Movie &movie1, const Movie &movie2); // Static comparison function to compare Movie objects based on starring

	    	friend stringstream & operator<<(stringstream &out, const Movie &movie); // Overloaded stream insertion operator to output Movie object to a stringstream
		private:
	    	string title; // Title of the movie
	    	string director; // Director of the movie
	    	int year; // Year of release
	    	string genre; // Genre of the movie
	    	string starring; // Actors starring in the movie
    };
}

#endif//MOVIE_HPP

