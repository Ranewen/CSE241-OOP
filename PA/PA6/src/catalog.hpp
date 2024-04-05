#ifndef CATALOG_HPP
#define CATALOG_HPP

#include "exceptions.hpp" // Include the header file for the Exceptions namespace
#include <string>

using std::string;
using Exceptions::BlankMethod; // Use the BlankMethod exception from the Exceptions namespace

namespace Catalog
{

    class CatalogBase
	{
		public:
	    	string GetTitle() const { throw BlankMethod(); } // Method to get the title, throws BlankMethod exception
	    	string GetAuthors() const { throw BlankMethod(); } // Method to get the authors, throws BlankMethod exception
	    	string GetYear() const { throw BlankMethod(); } // Method to get the year, throws BlankMethod exception
	    	string GetTags() const { throw BlankMethod(); } // Method to get the tags, throws BlankMethod exception
	    	string GetArtists() const { throw BlankMethod(); } // Method to get the artists, throws BlankMethod exception
	    	string GetGenre() const { throw BlankMethod(); } // Method to get the genre, throws BlankMethod exception
	    	string GetDirector() const { throw BlankMethod(); } // Method to get the director, throws BlankMethod exception
	    	string GetStarring() const { throw BlankMethod(); } // Method to get the starring, throws BlankMethod exception

	    	static bool CompareTitle(const CatalogBase &cb1, const CatalogBase &cb2) { throw BlankMethod(); } // Static method to compare titles, throws BlankMethod exception
	    	static bool CompareAuthors(const CatalogBase &cb1, const CatalogBase &cb2) { throw BlankMethod(); } // Static method to compare authors, throws BlankMethod exception
	    	static bool CompareYear(const CatalogBase &cb1, const CatalogBase &cb2) { throw BlankMethod(); } // Static method to compare years, throws BlankMethod exception
	    	static bool CompareTags(const CatalogBase &cb1, const CatalogBase &cb2) { throw BlankMethod(); } // Static method to compare tags, throws BlankMethod exception
	    	static bool CompareArtists(const CatalogBase &cb1, const CatalogBase &cb2) { throw BlankMethod(); } // Static method to compare artists, throws BlankMethod exception
	    	static bool CompareGenre(const CatalogBase &cb1, const CatalogBase &cb2) { throw BlankMethod(); } // Static method to compare genres, throws BlankMethod exception
	    	static bool CompareDirector(const CatalogBase &cb1, const CatalogBase &cb2) { throw BlankMethod(); } // Static method to compare directors, throws BlankMethod exception
	    	static bool CompareStarring(const CatalogBase &cb1, const CatalogBase &cb2) { throw BlankMethod(); } // Static method to compare starring, throws BlankMethod exception
    };

}

#endif // CATALOG_HPP

