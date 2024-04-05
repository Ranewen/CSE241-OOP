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
    // default constructor
    Course::Course() :
        name(""), code(""), studentRefSize(0), studentRefs(nullptr) {}

    // parameterized constructor
    Course::Course(string newName, string newCode) :
        name(newName), code(newCode), studentRefSize(0), studentRefs(nullptr) {}

    // destructor
    Course::~Course() 
	{
        delete[] studentRefs;
    }

    // getter and setter for name
    string Course::getName() const 
	{
        return name;
    }

    void Course::setName(string newName) 
	{
        name = newName;
    }

    // getter and setter for code
    string Course::getCode() const 
	{
        return code;
    }

    void Course::setCode(string newCode) 
	{
        code = newCode;
    }

    // assign a student to the course
    void Course::assignStudent(Student& student) 
	{
        // if the student is not already in the course
        if (!doesHave(student)) 
		{
            // create a new array with one more element than the previous array
            Student** newRef = new Student * [studentRefSize + 1];
            // copy all elements from the old array to the new array
            for (int i = 0; i < studentRefSize; ++i)
                newRef[i] = studentRefs[i];
            // add the new student to the end of the new array
            newRef[studentRefSize] = &student;
            // update the size of the array
            studentRefSize++;
            // delete the old array
            delete[] studentRefs;
            // point the studentRefs pointer to the new array
            studentRefs = newRef;
            // register the course to the student
            studentRefs[studentRefSize - 1]->assignCourse(*this);
        }
    }

    // drop a student from the course
    void Course::dropStudent(Student& student) 
	{
        // if the student is in the course
        if (doesHave(student)) 
		{
            Student* to_drop;
            // create a new array with one less element than the previous array
            Student** newRef = new Student * [studentRefSize - 1];
            // copy all elements from the old array to the new array except the student to drop
            for (int i = 0; i < studentRefSize; ++i) 
			{
                if (*studentRefs[i] != student)
                    newRef[i] = studentRefs[i];
                else
                    to_drop = studentRefs[i];
            }
            // update the size of the array
            studentRefSize--;
            // delete the old array
            delete[] studentRefs;
            // point the studentRefs pointer to the new array
            studentRefs = newRef;
            // drop the course from the student
            to_drop->dropCourse(*this);
        }
    }

    // check if a student is already in the course
    bool Course::doesHave(const Student& student) const 
	{
        bool in = false;
        // iterate through all students in the course
        for (int i = 0; i < studentRefSize; ++i)
            if (*studentRefs[i] == student)
                in = true;
        return in;
    }


   void Course::print() const
   {     
    	cout << "course: " << code << " " << name << endl; // prints the course code and name
    	cout << "Students: " << endl; // prints a heading for the list of students
    	for(int i = 0; i < studentRefSize; ++i)
        	cout << studentRefs[i]->name << " " << studentRefs[i]->id << endl; // prints the name and ID of each student in the course
    	cout << endl;
	}
	
	// Prints all registered students for a course// Prints all registered students for a course
	void Course::printRegistered() const
	{   
    	for(int i = 0; i < studentRefSize; ++i)
		{
        	cout << i+1 << " :" << *studentRefs[i] << endl; // prints the index of each student and calls the overloaded << operator for each student to print their information
    	}
	}
	
	// Overloaded operator for checking equality of two Course objects
	bool operator==(const Course& op1, const Course& op2)
	{ 
    	bool same = true; // initializes a flag to check if the two courses have the same students
    	
    	for(int i = 0; i < op1.studentRefSize && i < op2.studentRefSize; ++i)
        	if(op1.studentRefs[i] != op2.studentRefs[i]) // checks if the i-th student in op1 is the same as the i-th student in op2
            	same = false; // sets the flag to false if the i-th students are not the same
    	return op1.name == op2.name && op1.code == op2.code && same; // returns true if the names, codes, and students are the same for the two courses
	}

	bool operator!=(const Course& op1, const Course& op2)
	{
    	return !(op1 == op2); // returns the opposite of the result of the == operator
	}

	istream& operator>>(istream& in, Course& course)
	{
    	string name;
    	string code;
    	in >> code; // reads in the course code
    	char c;     
    	in >> c; // reads in a space character
    	getline(in, name); // reads in the course name
    	name = c + name; // concatenates the space character to the course name
    	course = Course(name, code); // assigns the course name and code to the course object
    	return in;
	}

	ostream& operator<<(ostream& out, const Course& course)
	{
    	out << course.code << " " << course.name; // prints the course code and name
    	return out;
	}
}
