#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>

using std::string;

namespace Exceptions
{

    class Exception
	{
	public:
	    string what() const { return "base exception"; } // Base exception class with a default what() method
    };

    class MissingField : public Exception
	{
		public:
	    	string what() const { return "missing field"; } // Exception for missing field
    };

    class DuplicateEntry : public Exception
	{
		public:
	    	string what() const { return "duplicate entry"; } // Exception for duplicate entry
    };

    class WrongCommand : public Exception
	{
		public:
	    	string what() const { return "command is wrong"; } // Exception for wrong command
    };

    class BlankMethod : public Exception
	{
	public:
	    string what() const { return "blank method"; } // Exception for a blank method
    };
}

#endif // EXCEPTIONS_HPP

