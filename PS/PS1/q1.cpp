#include <iostream>
using namespace std;
int main()
{
	int count1; 

	for(int i=3;i<=100;i++)	/* This loop that finds and prints all of the prime numbers between 3 and 100.*/
	{
		count1=0;
		for(int j=2;j<i;j++) 
		{
			if(i%j==0) /* Indicates that the number is not prime if this condition is met. */
			{
				count1++;
				break; 
			}
		}
		if(count1==0) /* condition for printing prime numbers */
		{
			cout<<i<<" is a prime number." << endl;
		}
	}
	cout<<endl;
	return 0;
}
