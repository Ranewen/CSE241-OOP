#include "Student.h"
#include "Course.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

namespace PA4 
{

    // Default constructor for Student class
    Student::Student() :
        name(""), id(0), courseRefSize(0), courseRefs(nullptr) 
		{
        // This constructor initializes the name and id variables to their default values.
        // courseRefs is initialized to nullptr, and courseRefSize to 0.
    	}	

    // Parameterized constructor for Student class
    Student::Student(string newName, int newId) :
        name(newName), id(newId), courseRefSize(0), courseRefs(nullptr) 
		{
        // This constructor initializes the name and id variables to the values passed as parameters.
        // courseRefs is initialized to nullptr, and courseRefSize to 0.
    	}

    // Destructor for Student class
    Student::~Student() 
	{
        // This destructor frees the memory allocated to courseRefs array, if any.
        delete[] courseRefs;
    }

    // Accessor function for name variable
    string Student::getName() const 
	{
        return name;
    }

    // Mutator function for name variable
    void Student::setName(string newName) 
	{
        name = newName;
    }

    // Accessor function for id variable
    int Student::getId() const 
	{
        return id;
    }

    // Mutator function for id variable
    void Student::setId(int newId) 
	{
        id = newId;
    }

    // Function to assign a course to the student
    void Student::assignCourse(Course& course) 
	{
        // This function adds a reference to the course passed as parameter to the courseRefs array,
        // if the course is not already in the array.
        if (!isIn(course)) 
		{
            // Creating a new array with an additional element
            Course **newRef = new Course*[courseRefSize + 1];
            for (int i = 0; i < courseRefSize; ++i)
                newRef[i] = courseRefs[i];

            // Adding the new course reference to the end of the new array
            newRef[courseRefSize] = &course;
            courseRefSize++;

            // Freeing the memory allocated to the old array, and updating the pointer to the new array
            delete[] courseRefs;
            courseRefs = newRef;

            // Calling the assignStudent function of the added course, to add a reference to this student
            courseRefs[courseRefSize-1]->assignStudent(*this);
        }
    }

    // Function to drop a course from the student
    void Student::dropCourse(Course& course) 
	{
        // This function removes a reference to the course passed as parameter from the courseRefs array,
        // if the course is already in the array.
        if (isIn(course)) 
		{
            Course* to_drop;
            // Creating a new array with one element less
            Course **newRef = new Course*[courseRefSize - 1];
            for (int i = 0; i < courseRefSize; ++i) 
			{
                if (*courseRefs[i] != course)
                    newRef[i] = courseRefs[i];
                else
                    to_drop = courseRefs[i];
            }
            courseRefSize--;

            // Freeing the memory allocated to the old array, and updating the pointer to the new array
            delete[] courseRefs;
            courseRefs = newRef;

            // Calling the drop Student function of the dropped course, to remove the reference to this student
            to_drop->dropStudent(*this);
        }
    }

    // Function to check if the student is registered in a given course
	bool Student::isIn(const Course& course) const 
	{
		bool in = false; 		
    	// This function checks if the course passed as parameter is already referenced in the courseRefs array.
    	for (int i = 0; i < courseRefSize; ++i) 
		{
        	if (*courseRefs[i] == course)
            	in = true;
    	}
    	return in;
	}
	
	bool operator==(const Student& op1, const Student& op2)
	{
        bool same = true;
        for(int i = 0; i < op1.courseRefSize && i < op2.courseRefSize; ++i)
            if(op1.courseRefs[i] != op2.courseRefs[i])
                same = false;
        return op1.name == op2.name && op1.id == op2.id && same;
    }
	
	bool operator!=(const Student& op1, const Student& op2)
	{
        return ! (op1 == op2);
    }
    
	// Function to print the list of courses the student is registered in
	void Student::print() const
	{
        cout << name << " " << id << " is in: ";
        for(int i = 0; i < courseRefSize; ++i)
        	cout << courseRefs[i]->name << " " << courseRefs[i]->code;
    }
	// Overloading the << operator for Student class
	ostream& operator<<(ostream& out, const Student& student)
	{
        out << student.name << " " << student.id;
        return out;
    }   

	// Overloading the >> operator for Student class
 	istream& operator>>(istream& in, Student& student)
	{
        string name, surname;
        int id;
        in >> name;
        in >> surname;
        in >> id;

        student = Student(name + " " + surname, id);

        return in;
    }		   
} //namespace PA4
