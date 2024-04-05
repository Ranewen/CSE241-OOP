#include <iostream> 
#include <math.h> 
#include <cstdlib>
#define max 50
using namespace std; 

/* Class Defined */
class MyInteger
{ 
	public: 
		MyInteger(int num)
		{
			this->num=num;
		} 
		int getnum()
		{
			return num;
		} 
		int operator[](int index); 
	
	private: 
		int num; int a[max];
}; 

/* Overrides [] to compute the ith digit */
int MyInteger::operator[](int index) 
{ 
	int i; 
	if(num==0) 
	{ 
		cout<<"illegal index value\n"; 
		index=-1; 
		return index; 
	} 
	if(index==0) 
	{ 
		a[0]=num%10; 
		return a[0]; 
	} 
	else if(i=index) 
	{ 
		num/=10; 
		a[i]=num%10; 
		return a[i]; 
	}   
}

/* Main Function */ 
int main() 
{  
	/* Test Function */
	MyInteger num(27); 
	cout << num[0] << " "; cout << num[1] << " "; cout << num[2] << endl; cout << num[3] << endl; cout << num[-1] << endl; 
	return 0; 
}
