#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <forward_list>
#include <string>

using std::forward_list;
using std::string;

// Function declaration for SplitStringEncapsulated
// Splits the input string based on the delimiter and returns a pointer to a forward_list of strings
forward_list<string> * SplitStringEncapsulated(const string &str, char delimiter);

#endif // FUNCTIONS_HPP

