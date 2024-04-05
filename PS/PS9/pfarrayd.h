#ifndef PFARRAYD_H
#define PFARRAYD _H

#include <string>

using std::string;

class Exception
{
};

class OutOfRange : public Exception
{
	public :
		OutOfRange(string thisMessage, int thisIndex);
		string getMessage () const;
		int getIndex() const;
	private :
		string message;
		int index;
};

class AnotherException
{
};

//Objects of this class are partially filled arrays of doubles.
class PFArrayD
{
	public :
		PFArrayD();
		// Initializes with a capacity of 50.
		PFArrayD(int capacityValue);
		PFArrayD(const PFArrayD& pfaObject);
		void addElement (double element);
		// Pre condition : The array is not full .
		// Post condition : The element has been added .
		bool full() const { return ( capacity == used);}	
		//Returns true if the array is full , false otherwise .
		int getCapacity() const { return capacity;}
		int getNumberUsed() const { return used;}
		void emptyArray(){ used = 0;}
		//Empties the array .
		double& operator [] (int index);
		//Read and change ac c e s s to element s 0 through numberUsed . 1.
		PFArrayD& operator = (const PFArrayD& rightSide);
		~PFArrayD();
	private :
		double *a; 		// for an array of doubles.
		int capacity; 	// for the size of the array .
		int used; 		// for the number of array positions currently in use .
};
#endif //PFARRAYD_H
