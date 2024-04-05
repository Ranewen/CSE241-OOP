#ifndef BOOK_HPP
#define BOOK_HPP

#include "catalog.hpp" // Include the header file for the CatalogBase class
#include <forward_list>
#include <string>
#include <sstream>

using std::forward_list;
using std::string;
using std::stringstream;

namespace Catalog
{

    class Book : public CatalogBase // Book class inherits from CatalogBase
	{
		public:
	    	Book(); // Default constructor
	    	Book(const Book &book); // Copy constructor
	    	Book(const forward_list<string> *fields); // Constructor that takes a pointer to a forward_list of strings
	    	Book(const string &_title, const string &_authors, int _year, const string &_tags); // Constructor that takes individual fields

	    	string GetTitle() const { return title; } // Getter for title
	    	string GetAuthors() const { return authors; } // Getter for authors
	    	int GetYear() const { return year; } // Getter for year
	    	string GetTags() const { return tags; } // Getter for tags

	    	static int GetFieldCount() { return 4; } // Static function to get the field count
	    	static bool CompareTitle(const Book &book1, const Book &book2); // Static comparison function to compare books based on title
	    	static bool CompareAuthors(const Book &book1, const Book &book2); // Static comparison function to compare books based on authors
	    	static bool CompareYear(const Book &book1, const Book &book2); // Static comparison function to compare books based on year
	    	static bool CompareTags(const Book &book1, const Book &book2); // Static comparison function to compare books based on tags

	    	friend stringstream & operator<<(stringstream &out, const Book &book); // Overloaded insertion operator to output the Book object to a stringstream

		private:
	    	string title; // Title of the book
	    	string authors; // Authors of the book
	    	int year; // Publication year of the book
	    	string tags; // Tags associated with the book
    };
}

#endif // BOOK_HPP

