#include "book.hpp" // Include the header file for the Book class
#include <string>
#include <forward_list>
#include <sstream>

using std::stringstream;
using std::forward_list;
using std::string;

namespace Catalog
{
    // Default constructor for the Book class
    Book::Book() : title{}, authors{}, year{}, tags{}
    {

    }

    // Copy constructor for the Book class
    Book::Book(const Book &book) : title(book.title), authors(book.authors), year(book.year), tags(book.tags)
    {

    }
    
    // Constructor for the Book class that takes a pointer to a forward_list of strings
    Book::Book(const forward_list<string> *fields)
    {
		auto it = fields->begin();
		tags = *it++; // Assign the first string to the 'tags' member variable and increment the iterator
		year = std::stoi(*it++); // Assign the second string converted to an integer to the 'year' member variable and increment the iterator
		authors = *it++; // Assign the third string to the 'authors' member variable and increment the iterator
		title = *it++; // Assign the fourth string to the 'title' member variable
    }

    // Comparison function to compare books based on their titles
    bool Book::CompareTitle(const Book &book1, const Book &book2) 
	{
		return book1.title < book2.title;
    }

    // Comparison function to compare books based on their authors
    bool Book::CompareAuthors(const Book &book1, const Book &book2) 
	{
		return book1.authors < book2.authors;
    }

    // Comparison function to compare books based on their publication years
    bool Book::CompareYear(const Book &book1, const Book &book2) 
	{
		return book1.year < book2.year;
    }
    
    // Comparison function to compare books based on their tags
    bool Book::CompareTags(const Book &book1, const Book &book2) 
	{
		return book1.tags < book2.tags;
    }

    // Overloaded insertion operator to output the Book object to a stringstream
    stringstream & operator<<(stringstream &out, const Book &book)
	{
		out << '"' << book.title << "\" \"" << book.authors << "\" \"" << book.year << "\" \"" 
	    << book.tags << '"' << std::endl;
		return out;
    }
}
