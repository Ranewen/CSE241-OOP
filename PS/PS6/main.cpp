#include <iostream>
#include "user.h"       // include the header file for the username functions
#include "password.h"   // include the header file for the password functions

using namespace std;
using namespace Authenticate;

int main()
{
	inputUserName();                  // call the function to input and validate the username
   	inputPassword();                  // call the function to input and validate the password
    cout << "Your username is " << Authenticate::getUserName() << " and your password is: " << Authenticate::getPassword() << std::endl;    // print out the validated username and password
    return 0;       // exit the program

}
