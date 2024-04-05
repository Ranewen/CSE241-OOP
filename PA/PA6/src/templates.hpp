#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include "exceptions.hpp"
#include "functions.hpp"
#include <fstream>
#include <forward_list>
#include <string>
#include <sstream>

using std::ifstream;
using std::ofstream;
using std::forward_list;
using std::getline;
using std::string;
using std::stringstream;
using Exceptions::MissingField;
using Exceptions::DuplicateEntry;
using Exceptions::WrongCommand;
using Exceptions::BlankMethod;


template <typename T>
void ReadData(ifstream &in, forward_list<T> &list, ofstream &out)
{
    string readLine;                        // Variable to hold the read line from the file
    int uniqueEntries = 0;                  // Counter for unique entries
    string firstField;                      // First field in each line
    forward_list<string> *fields;           // Pointer to hold the split fields
    int fieldCount;                         // Counter for the number of fields
    
    while (getline(in, readLine))
    {
        fields = SplitStringEncapsulated(readLine, '"');  // Split the line into fields
        fieldCount = 0;                     // Reset the field count
        
        try
        {
            for (auto it = fields->begin(); it != fields->end(); ++it)
            {
                firstField = *it;           // Get the first field
                ++fieldCount;               // Increment the field count
            }
            
            if (fieldCount != T::GetFieldCount())  // Check if the number of fields matches the expected count
                throw MissingField();               // Throw an exception if a field is missing
        }
        catch (MissingField e)
        {
            out << "Exception: " << e.what() << std::endl
                << readLine << std::endl;           // Output the exception and the line with missing fields
            delete fields;                          // Clean up the dynamically allocated fields list
            continue;                               // Continue to the next line
        }
        
        try
        {
            for (auto it = list.begin(); it != list.end(); ++it)
            {
                if (it->GetTitle() == firstField)    // Check if an entry with the same title already exists
                    throw DuplicateEntry();         // Throw an exception if a duplicate entry is found
            }
        }
        catch (DuplicateEntry e)
        {
            out << "Exception: " << e.what() << std::endl
                << readLine << std::endl;           // Output the exception and the line with duplicate entry
            delete fields;                          // Clean up the dynamically allocated fields list
            continue;                               // Continue to the next line
        }
        
        ++uniqueEntries;                            // Increment the counter for unique entries
        list.emplace_front(fields);                 // Add the entry to the list
        delete fields;                              // Clean up the dynamically allocated fields list
    }
    
    out << uniqueEntries << " unique entries\n";     // Output the number of unique entries
}


template <typename T>
void ExecuteCommands(ifstream &in, forward_list<T> &dataList, ofstream &out)
{
    string readLine;                                // Variable to hold the read line from the file
    
    forward_list<string> *fields;                   // Pointer to hold the split fields
    
    while (getline(in, readLine))
    {
        stringstream streamReadLine(readLine);      // Convert the read line to a stringstream
        stringstream commandResult;                 // Stream to hold the result of the command
        
        fields = SplitStringEncapsulated(readLine, '"');  // Split the line into fields
        auto commandArg = fields->begin();          // Iterator for the command argument
        
        string command;                             // Variable to hold the command
        streamReadLine >> command;                   // Read the command from the stringstream
        string searchField = *commandArg++;          // Get the search field
        
        try
        {
            if (command == "search")
            {
                string searched = *commandArg++;     // Get the searched value
                
                // Perform search based on the search field
                if (searchField == "title")
                {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it)
                    {
                        if (it->GetTitle().find(searched) != string::npos)
                            commandResult << *it;
                    }
                }
                else if (searchField == "authors")
                {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it)
                    {
                        if (it->GetAuthors().find(searched) != string::npos)
                            commandResult << *it;
                    }
                }
                else if (searchField == "year")
                {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it)
                    {
                        if (std::to_string(it->GetYear()).find(searched) != string::npos)
                            commandResult << *it;
                    }
                }
                else if (searchField == "tags")
                {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it)
                    {
                        if (it->GetTags().find(searched) != string::npos)
                            commandResult << *it;
                    }
                }
                else if (searchField == "artists")
                {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it)
                    {
                        if (it->GetArtists().find(searched) != string::npos)
                            commandResult << *it;
                    }
                }
                else if (searchField == "genre")
                {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it)
                    {
                        if (it->GetGenre().find(searched) != string::npos)
                            commandResult << *it;
                    }
                }
                else if (searchField == "director")
                {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it)
                    {
                        if (it->GetDirector().find(searched) != string::npos)
                            commandResult << *it;
                    }
                }
                else if (searchField == "starring")
                {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it)
                    {
                        if (it->GetStarring().find(searched) != string::npos)
                            commandResult << *it;
                    }
                }
                else
                {
                    throw WrongCommand();               // Throw an exception if an invalid search field is specified
                }
            }
            
            else if (command == "sort")
            {
                // Sort the data list based on the search field
                if (searchField == "title")
                    dataList.sort(T::CompareTitle);
                else if (searchField == "authors")
                    dataList.sort(T::CompareAuthors);
                else if (searchField == "year")
                    dataList.sort(T::CompareYear);
                else if (searchField == "tags")
                    dataList.sort(T::CompareTags);
                else if (searchField == "artists")
                    dataList.sort(T::CompareArtists);
                else if (searchField == "genre")
                    dataList.sort(T::CompareGenre);
                else if (searchField == "director")
                    dataList.sort(T::CompareTitle);
                else if (searchField == "starring")
                    dataList.sort(T::CompareTitle);
                else
                {
                    throw WrongCommand();               // Throw an exception if an invalid sort field is specified
                }
                
                for (auto it = dataList.begin(); it != dataList.end(); ++it)
                    commandResult << *it;
            }
        }
        
        catch (BlankMethod e)
        {
            throw WrongCommand();                       // Throw an exception if a blank method is detected
        }
        
        catch (WrongCommand e)
        {
            out << "Exception: " << e.what() << std::endl
                << readLine << std::endl;               // Output the exception and the command line
            delete fields;                              // Clean up the dynamically allocated fields list
            continue;                                   // Continue to the next line
        }
        
        out << readLine << std::endl
            << commandResult.str();                      // Output the command line and the command result
        delete fields;                                  // Clean up the dynamically allocated fields list
    }
}
#endif // TEMPLATES_HPP

