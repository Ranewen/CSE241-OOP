#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H

#include "Course.h"
#include "Student.h"
#include <iostream>

using std::string;

namespace PA4 
{

    // This class represents a school management system that can add and delete students and courses, 
    // and list all students and courses in the system.
    class SchoolManagerSystem 
	{
    	private:
        	Course * courseRefs;    // An array of pointers to the courses in the system
        	Student * studentRefs;  // An array of pointers to the students in the system
        	int courseRefSize;      // The current size of the courseRefs array
        	int studentRefSize;     // The current size of the studentRefs array

    	public:
        	// Default constructor for SchoolManagerSystem class
        	SchoolManagerSystem();

        	// Function to add a new student to the system using a Student object
        	void addStudent(const Student& student);

        	// Function to add a new student to the system using a name and id
        	void addStudent(string name, int id);

        	// Function to add a new student to the system through user input
        	void add_student();

        	// Function to select a student from the system through user input
        	Student& select_student();

        	// Function to add a new course to the system using a Course object
        	void addCourse(const Course& course);

        	// Function to add a new course to the system using a name and code
        	void addCourse(string name, string code);

        	// Function to add a new course to the system through user input
        	void add_course();

        	// Function to select a course from the system through user input
        	Course& select_course();

        	// Function to delete a student from the system
        	void deleteStudent(Student& student);

        	// Function to delete a course from the system
        	void deleteCourse(Course& course);

        	// Function to get a reference to a student in the system by passing a Student object
        	Student& getStudent(const Student& toGetStudent);

        	// Function to get a reference to a course in the system by passing a Course object
        	Course& getCourse(const Course& toGetCourse);

        	// Function to get a reference to a course in the system by passing an index
        	Course& getCourse(int ix);

        	// Function to get the index of a course in the courseRefs array
        	int courseIx(const Course& course) const;

        	// Function to get the index of a student in the studentRefs array
        	int studentIx(const Student& student) const;

        	// Function to print the current state of the system (i.e., all students and courses)
        	void print() const;

        	// Function to list all students in the system
        	void listAllStudents() const;

        	// Function to list all courses in the system
        	void listAllCourses() const;

        	// Function to display the main menu and return the user's choice
        	int menu() const;

        	// Function to display the student menu and return the user's choice
        	int studentMenu() const;

        	// Function to display the course menu and return the user's choice
        	int courseMenu() const;

        	// Function to display the select student menu and return the user's choice
        	int selectStudentMenu() const;

        	// Function to display the select course menu and return the user's choice
        	int selectCourseMenu() const;

        	// Destructor for SchoolManagerSystem class
        	~SchoolManagerSystem();
    };
}
#endif
