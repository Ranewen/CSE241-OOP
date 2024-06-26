#include <iostream>
#include <cstdlib>

namespace
{
	int lev =0;
	
	void f(int throw_level)
	{
		++lev;
		std::cout << "lev == " << lev << std::endl;
		
		if(throw_level == lev)
			throw lev;
		else
			f(throw_level);
	}
}

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	int depth = 10;
	
	int catch_level;
	cout << "Enter an exception level greater than or equal to 0: ";
	cin >> catch_level;
	cout << endl;
	
	try
	{
		if(catch_level == 0)
			throw 0;
		else
			f(catch_level);
	}
	catch(int depth)
	{
		cout << "Caught exception at level " << depth << endl;
	}
	return 0;
}
