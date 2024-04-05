#ifndef STUDENT_H 		// Include guards to avoid multiple inclusions of header files.
#define STUDENT_H 

#include "Course.h" 	// Include the header file for the Course class.
#include <iostream> 	// Include the header file for input/output streams.

using std::string;      // Using declaration for the string class.
using std::istream;     // Using declaration for the input stream.
using std::ostream;     // Using declaration for the output stream

namespace PA4 
{
    class Course;   // Forward declaration of the Course class

    class Student 
	{
    	private:
        	string name;            // Name of the student
        	int id;                 // ID of the student
        	Course** courseRefs;    // Pointer array to courses
        	int courseRefSize;      // Size of the course reference array
        	friend class Course;    // Allow Course class to access Student's private data

    	public:
        	Student(string newName, int newId); // Constructor with name and id parameters
        	Student();                          // Default constructor
        	~Student();                         // Destructor

        	// Getters and setters
        	string getName() const;
        	void setName(string newName);

        	int getId() const;
        	void setId(int newId);

        	// Course related functions
        	void assignCourse(Course& course);  // Assign a course to student
        	void dropCourse(Course& course);    // Drop a course from student
        	bool isIn(const Course& course) const;  // Check if student is in a course

        	void print() const;     // Print student's data for debugging

        	// Operator overloads
        	friend bool operator==(const Student& op1, const Student& op2);
        	friend bool operator!=(const Student& op1, const Student& op2);
        	friend istream& operator>>(istream& in, Student& student);
        	friend ostream& operator<<(ostream& out, const Student& student);
    };
}   // namespace PA4

#endif
