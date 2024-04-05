#include <iostream>
#include <string>
using namespace std;

namespace 
{
    string password;
    bool isValid()
	{
        bool hasNonLetter = false;
        if (password.length() < 8) 
		{
            return false;
        }
        for (int i = 0; i < password.length(); i++) 
		{
            if (!isalpha(password[i])) 
			{
                hasNonLetter = true;
                break;
            }
        }
        return hasNonLetter;
    }
}

namespace Authenticate
{
    void inputPassword() 
	{
        do 
		{
            cout << "Enter your password (at least 8 characters and at least one non-letter)" << endl;
            cin >> password;
        } while (!isValid());
    }
    
    string getPassword() 
	{
        return password;
    }
}
