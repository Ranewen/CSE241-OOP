/* Compile g++ --std=c++11 q2.cpp */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
void output(vector<int>& suitors);
int main() 
{	

	int n;
	int i;
	
	//getting the number of Suitors
	cout << "How many suitors are there for the beautiful princess Eve?\n";
	cin >> n;
	
	//declaring the suitors vector
	std::vector<int> suitors;

	//filling the suitors vector with numbers
	for (i = 1; i <= n; i++)
		suitors.push_back(i);
	
	 if (n <= 0)
    {
        cout << "Not enough suitors." << endl;
    }

    else if (n == 1)
    {
         cout << "You would stand first in line." << endl;
    }
	
	else
	{
		//printing the all suitors
		cout << "Suitors are: ";

		for (auto it = suitors.begin(); it != suitors.cend(); it++)
			cout << *it << " ";

		cout << endl << endl;

		int currentIndex = 0;

		//removing the suitors until suitors size is !=1

		while (suitors.size() != 1) 
		{
			for (int i = 1; i <= 2; i++) 
			{
				currentIndex++;
				if (currentIndex == suitors.size())
					currentIndex = 0;

			}
			//removing the suitor
			suitors.erase(suitors.begin() + currentIndex);
			if (currentIndex == suitors.size())
				currentIndex = 0;

			for (auto it = suitors.begin(); it != suitors.cend(); it++)
				cout << *it << " ";

			cout << endl;
		}
	}
	output(suitors);
}

void output(vector<int>& suitors)
{
    cout<<"\nIf you want to marry the beautiful princess Eve, you should stand ";
    cout<<"in position "<<suitors[0]<<".\n\n";
}
