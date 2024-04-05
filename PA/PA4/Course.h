#ifndef COURSE_H           // Include guards to avoid multiple inclusions of header files.
#define COURSE_H

#include "Student.h"      // Include the header file for the Student class.
#include <iostream>       // Include the header file for input/output streams.

using std::string;        // Using declaration for the string class.
using std::istream;       // Using declaration for the input stream.
using std::ostream;       // Using declaration for the output stream.

namespace PA4             // Define the namespace for your program.
{
    class Student;        // Forward declaration of the Student class.

    class Course          // Define the Course class.
    {
    	private:
        	string name;            // Private member variable to store the name of the course.
        	string code;            // Private member variable to store the code of the course.
        	Student** studentRefs;  // Private member variable to store the pointers to the students registered in the course.
        	int studentRefSize;     // Private member variable to store the size of the array of student pointers.
        	friend class Student;   // Friend class declaration for the Student class to access private members.

    	public:
        	Course();                      // Default constructor for the Course class.
        	Course(string newName, string newCode);   // Constructor that takes the name and code of the course.

        	~Course();                             // Destructor for the Course class.

        	string getName() const;            // Getter method for the name of the course.
        	void setName(string newName);      // Setter method for the name of the course.

        	string getCode() const;            // Getter method for the code of the course.
        	void setCode(string newCode);      // Setter method for the code of the course.

        	void assignStudent(Student& student);    // Method to assign a student to the course.
        	void dropStudent(Student& student);      // Method to drop a student from the course.

        	bool doesHave(const Student& student) const;    // Method to check if a given student is registered in the course.

        	void print() const;            // Method to print the details of the course.

        	void printRegistered() const;  // Method to print the names and IDs of the registered students.

        	friend bool operator==(const Course& op1, const Course& op2);    // Friend operator overload for equality check between two courses.

        	friend bool operator!=(const Course& op1, const Course& op2);    // Friend operator overload for inequality check between two courses.

        	friend istream& operator>>(istream& in, Course& course);         // Friend operator overload for input stream to read course details.

        	friend ostream& operator<<(ostream& out, const Course& course);  // Friend operator overload for output stream to print course details.
        
	};
} // PA4

#endif
