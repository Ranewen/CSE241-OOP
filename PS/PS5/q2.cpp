#include <iostream>
using namespace std;

class Student 
{
	private:
    	string name;
    	int numClasses;
    	string* classList;

	public:
    	// Constructor
    	Student() 
		{
        	name = "";
        	numClasses = 0;
        	classList = NULL;
    	}

    	// Destructor
    	~Student() 
		{
        	delete[] classList;
    	}

    	// Copy constructor
    	Student(const Student& other) 
		{
        	name = other.name;
        	numClasses = other.numClasses;

        	if (numClasses > 0) 
			{
            	classList = new string[numClasses];
            	for (int i = 0; i < numClasses; i++) 
				{
                	classList[i] = other.classList[i];
            	}
        	}
        	else 
			{
            	classList = NULL;
        	}
    	}
    
    	// Assignment operator
    	Student& operator=(const Student& other) 
		{
        	if (this != &other) 
			{
            	name = other.name;
            	numClasses = other.numClasses;

            	delete[] classList;

            	if (numClasses > 0) 
				{
                	classList = new string[numClasses];
                	for (int i = 0; i < numClasses; i++) 
					{
                    	classList[i] = other.classList[i];
                	}
            	}
            	else 
				{
                	classList = NULL;
            	}
        	}
        return *this;
    	}
    
    	// Input all values from the user, including the list of class names
    	void InputData() 
		{
        	cout << "Enter student name: ";
        	getline(cin, name);

        	cout << "Enter number of classes: ";
        	cin >> numClasses;
        	cin.ignore(); // discard newline character

        	if (numClasses > 0) 
			{
            	classList = new string[numClasses];
            	for (int i = 0; i < numClasses; i++) 
				{
                	cout << "Enter name of class " << i+1 << ": ";
                	getline(cin, classList[i]);
            	}
        	}
    	}

    	// Output the name and list of all courses
    	void OutputData() const 
		{
        	cout << "Name: " << name << endl;
			cout<<"Number of classes: "<<numClasses<<endl;
        	if (numClasses > 0) 
			{
            	for (int i = 0; i < numClasses; i++) 
				{
					cout<<"Class "<<i+1<<": "<<classList[i]<<endl;
            	}
        	}
    	}

    	// Reset the number of classes to 0 and the classList to an empty list
    	void ResetClasses() 
		{
        	numClasses = 0;
        	delete[] classList;
        	classList = NULL;
    	}
};
int main()
{
    Student s1, s2;
      
    s1.InputData();    //Input data for student 1
    cout << "Student 1's data: "<<endl;
    s1.OutputData();    //Output data for student 1
      
    s2 = s1;
    cout << "Student 2's data after assignment from student 1:"<<endl;
    s2.OutputData();    //Should output same data as for student 1
      
    s1.ResetClasses();
    cout << "Student 1's data after reset:" << endl;
    s1.OutputData();    //Should have no classes.
      
    cout << "Student 2's data, should still have original classes: " << endl;
    s2.OutputData();    //Should still have original classes.
}
