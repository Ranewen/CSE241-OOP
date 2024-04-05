#include "functions.hpp"
#include "templates.hpp"
#include "book.hpp"
#include "music.hpp"
#include "movie.hpp"
#include <iostream>
#include <forward_list>
#include <string>
#include <fstream>

using namespace std;
using Catalog::Book;
using Catalog::Music;
using Catalog::Movie;

int main()
{
    // Open the necessary input and output files
    ifstream dataFile("data.txt");
    ofstream outputFile("output.txt");
    ifstream commandFile("commands.txt");

    string catalogType;
    getline(dataFile, catalogType); // Read the catalog type from the data file

    if (catalogType == "book")
    {
        outputFile << "Catalog Read: book\n";
        forward_list<Book> dataList; // Create a forward_list to store Book objects
        ReadData<Book>(dataFile, dataList, outputFile); // Read book data from the data file
        ExecuteCommands<Book>(commandFile, dataList, outputFile); // Execute commands on the book data
    }
    else if (catalogType == "music")
    {
        outputFile << "Catalog Read: music\n";
        forward_list<Music> dataList; // Create a forward_list to store Music objects
        ReadData<Music>(dataFile, dataList, outputFile); // Read music data from the data file
        ExecuteCommands<Music>(commandFile, dataList, outputFile); // Execute commands on the music data
    }
    else if (catalogType == "movie")
    {
        outputFile << "Catalog Read: movie\n";
        forward_list<Movie> dataList; // Create a forward_list to store Movie objects
        ReadData<Movie>(dataFile, dataList, outputFile); // Read movie data from the data file
        ExecuteCommands<Movie>(commandFile, dataList, outputFile); // Execute commands on the movie data
    }
    else
    {
        outputFile << "Invalid catalog type: " << catalogType << endl; // Handle invalid catalog type
    }

    // Close the input and output files
    dataFile.close();
    outputFile.close();
    commandFile.close();

    return 0;
}

