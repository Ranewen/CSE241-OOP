#include "functions.hpp"
#include <string>
#include <forward_list>

using std::string;
using std::forward_list;

forward_list<string> * SplitStringEncapsulated(const string &str, char delimiter)
{
    forward_list<string> *split = new forward_list<string>(); // Create a new forward_list dynamically

    bool add = false; // Boolean flag to track whether to add characters to the current split string

    for (auto it = str.begin(); it != str.end(); ++it)
    {
        if (*it == delimiter)
        {
            add = !add; // Toggle the add flag when the delimiter is encountered
            if (add)
                split->emplace_front(""); // Add a new empty string at the front of the forward_list
        }
        else if (add)
        {
            split->front() += *it; // Append the character to the current split string if the add flag is true
        }
    }

    return split; // Return the pointer to the forward_list
}

