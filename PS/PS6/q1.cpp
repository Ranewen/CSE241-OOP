#include <iostream>
#include <string>

using namespace std;

class DynamicStringArray 
{
	private:
    	string* dynamicArray;
    	int size;

	public:
    	// Default constructor
    	DynamicStringArray() 
		{
        	dynamicArray = NULL;
        	size = 0;
    	}

    	// Destructor
    	~DynamicStringArray() 
		{
        	delete[] dynamicArray;
    	}

    	// Copy constructor
    	DynamicStringArray(const DynamicStringArray& other) 
		{
        	size = other.size;
        	dynamicArray = new string[size];
        	for (int i = 0; i < size; i++) 
			{
            	dynamicArray[i] = other.dynamicArray[i];
        	}
    	}

    	// Overloaded assignment operator
    	DynamicStringArray& operator=(const DynamicStringArray& other) 
		{
        	if (this != &other) 
			{
            	delete[] dynamicArray;
            	size = other.size;
            	dynamicArray = new string[size];
            	for (int i = 0; i < size; i++) 
				{
                	dynamicArray[i] = other.dynamicArray[i];
            	}
        	}
        	return *this;
    	}

    	// Get size of the array
    	int getSize() const 
		{
        	return size;
    	}

    	// Add an entry to the array
    	void addEntry(const string& entry) 
		{
        	// Create new array with one more element
        	string* newDynamicArray = new string[size + 1];
        	// Copy old elements to new array
        	for (int i = 0; i < size; i++) 
			{
            	newDynamicArray[i] = dynamicArray[i];
        	}
        	// Add new element to end of new array
        	newDynamicArray[size] = entry;
        	// Update size
        	size++;
        	// Delete old array
        	delete[] dynamicArray;
        	// Set dynamicArray to new array
        	dynamicArray = newDynamicArray;
    	}

    	// Delete an entry from the array
    	bool deleteEntry(const string& entry) 
		{
        	// Search for entry
        	int index = -1;
        	for (int i = 0; i < size; i++) 
			{
            	if (dynamicArray[i] == entry) 
				{
                	index = i;
                	break;
            	}
        	}
        	// If entry is not found, return false
        	if (index == -1) 
			{
            	return false;
        	}
        	// Create new array with one less element
        	string* newDynamicArray = new string[size - 1];
        	// Copy old elements to new array, skipping the deleted entry
        	int j = 0;
        	for (int i = 0; i < size; i++) 
			{
            	if (i != index) 
				{
                	newDynamicArray[j] = dynamicArray[i];
                	j++;
            	}
        	}
        	// Update size
        	size--;
        	// Delete old array
        	delete[] dynamicArray;
        	// Set dynamicArray to new array
        	dynamicArray = newDynamicArray;
        	// Return true to indicate success
        	return true;
    	}

    	// Get an entry from the array by index
    	string getEntry(int index) const 
		{
        	// If index is out of bounds, return NULL
        	if (index < 0 || index >= size) 
			{
            	return NULL;
        	}
        	// Otherwise, return the string at the given index
        	return dynamicArray[index];
    	}
};

int main()
{
	DynamicStringArray names;
	// List of names
	names.addEntry("Frank");
	names.addEntry("Wiggum");
	names.addEntry("Nahasapeemapetilon");
	names.addEntry("Quimby");
	names.addEntry("Flanders");

	// Output list
	cout << "List of names:" << endl;
	for (int i = 0; i < names.getSize(); i++)
    	cout << names.getEntry(i) << endl;
	cout << endl;

	// Add and remove some names
	names.addEntry("Spuckler");
	cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
    	cout << names.getEntry(i) << endl;
	cout << endl;

	names.deleteEntry("Nahasapeemapetilon");
	cout << "After removing a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
    	cout << names.getEntry(i) << endl;
	cout << endl;

	names.deleteEntry("Skinner");
	cout << "After removing a name that isn't on the list:" << endl;
	for (int i = 0; i < names.getSize(); i++)
    	cout << names.getEntry(i) << endl;
	cout << endl;

	names.addEntry("Muntz");
	cout << "After adding another name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
    	cout << names.getEntry(i) << endl;
	cout << endl;

	// Remove all of the names by repeatedly deleting the last one
	while (names.getSize() > 0) 
	{
    	names.deleteEntry(names.getEntry(names.getSize() - 1));
	}
	cout << "After removing all of the names:" << endl;
	for (int i = 0; i < names.getSize(); i++)
    	cout << names.getEntry(i) << endl;
	cout << endl;

	names.addEntry("Burns");
	cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
    	cout << names.getEntry(i) << endl;
	cout << endl;

	cout << "Testing copy constructor" << endl;
	DynamicStringArray names2(names);
	
	// Remove Burns from names
	names.deleteEntry("Burns");
	cout << "Copied names:" << endl;
	for (int i = 0; i < names2.getSize(); i++)
    	cout << names2.getEntry(i) << endl;
	cout << endl;

	cout << "Testing assignment" << endl;
	DynamicStringArray names3 = names2;
	
	// Remove Burns from names2
	names2.deleteEntry("Burns");
	cout << "Copied names:" << endl;
	for (int i = 0; i < names3.getSize(); i++)
    	cout << names3.getEntry(i) << endl;
	cout << endl;

	cout << "Enter a character to exit." << endl;
	char wait;
	cin >> wait;
	return 0;
}
