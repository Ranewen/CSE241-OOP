#include "SchoolManagerSystem.h"
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

namespace PA4
{
    // Default constructor
    SchoolManagerSystem::SchoolManagerSystem():
        studentRefs(nullptr), courseRefs(nullptr),
        studentRefSize(0), courseRefSize(0){/**/}

    // Destructor
    SchoolManagerSystem::~SchoolManagerSystem()
    {
        delete[] studentRefs; // Free memory allocated for students
        delete[] courseRefs;  // Free memory allocated for courses
    }

    // Add a student to the system
    void SchoolManagerSystem::addStudent(const Student& student)
	{
        // Create a new array with space for one more student reference
        Student * newRef = new Student[studentRefSize + 1];
        // Copy existing student references to the new array
        for(int i = 0; i < studentRefSize; ++i)
            newRef[i] = studentRefs[i]; 
        // Add the new student to the end of the new array
        newRef[studentRefSize] = student;
        // Update the size of the array
        studentRefSize++;
        // Free memory allocated for the old array
        delete [] studentRefs;
        // Point to the new array
        studentRefs = newRef;
    }

    // Add a student to the system with a name and id
    void SchoolManagerSystem::addStudent(string name, int id)
	{
        addStudent(Student(name, id)); // Call the other addStudent function with a Student object
    }

    // Add a course to the system
    void SchoolManagerSystem::addCourse(const Course& course)
	{
        // Create a new array with space for one more course reference
        Course * newRef = new Course[courseRefSize + 1];
        // Copy existing course references to the new array
        for(int i = 0; i < courseRefSize; ++i)
            newRef[i] = courseRefs[i]; 
        // Add the new course to the end of the new array
        newRef[courseRefSize] = course;
        // Update the size of the array
        courseRefSize++;
        // Free memory allocated for the old array
        delete [] courseRefs;
        // Point to the new array
        courseRefs = newRef;
    }

    // Add a course to the system with a name and code
    void SchoolManagerSystem::addCourse(string name, string code)
	{
        addCourse(Course(name, code)); // Call the other addCourse function with a Course object
    }

    // Get a reference to a student with the same name and id as toGetStudent
    Student& SchoolManagerSystem::getStudent(const Student& toGetStudent)
	{
        int studentix = studentIx(toGetStudent);
        if(studentix != -1)
            return studentRefs[studentix];
        else
		{
            cout << ("no such student") << endl;
            exit(0);
        }
    }

    // Get a reference to a course with the same name and code as toGetCourse
    Course& SchoolManagerSystem::getCourse(const Course& toGetCourse)
	{
        int courseix = courseIx(toGetCourse);
        if(courseix != -1)
            return courseRefs[courseix];
        else
		{
            cout << ("no such course") << endl;
            exit(0);
        }
    }

    // Method to get a reference to the course with the given index in the courseRefs array
	Course& SchoolManagerSystem::getCourse(int ix)
	{
    	return courseRefs[ix];    
	}

	// Method to get the index of a course in the courseRefs array
	int SchoolManagerSystem::courseIx(const Course& course) const
	{
    	int ix = -1;

    	for(int i = 0; i < courseRefSize; ++i)
        	if(courseRefs[i] == course)
            	ix = i;

    	return ix;
	}

	// Method to get the index of a student in the studentRefs array
	int SchoolManagerSystem::studentIx(const Student& student) const
	{
    	bool ix  = -1;

    	for(int i = 0; i < studentRefSize; ++i)
        	if(studentRefs[i] == student)
            	ix = i;
                
    	return ix;
	}

	// Method to print all the students and courses in the system
	void SchoolManagerSystem::print() const
	{
    	for(int i = 0; i < studentRefSize; ++i)
        	studentRefs[i].print();
    	cout << endl;
    	for(int i = 0; i < courseRefSize; ++i)
        	courseRefs[i].print();
	}

	// Method to add a new student to the system
	void SchoolManagerSystem::add_student()
	{
    	Student to_add;
    	cin >> to_add;
    	addStudent(to_add);
	}

	// Method to select a student from the system
	Student& SchoolManagerSystem::select_student()
	{
    	Student to_select;
    	cin >> to_select;
    	return getStudent(to_select);
	}

	// Method to add a new course to the system
	void SchoolManagerSystem::add_course()
	{
    	Course to_add;
    	cin >> to_add;
    	addCourse(to_add);
	}

	// Method to select a course from the system
	Course& SchoolManagerSystem::select_course()
	{
    	Course to_select;
    	cin >> to_select;
    	return getCourse(to_select);
	}
	
	// Method to delete a student from the system
	void SchoolManagerSystem::deleteStudent(Student& student)
	{
    	// drop the student from all courses
    	for(int i = 0; i < courseRefSize; ++i)
        	courseRefs[i].dropStudent(student);

    	// find the index of the student in the studentRefs array
    	int stuix = studentIx(student);

    	// if the student is found
    	if(stuix != -1)
		{
        	// shift all references from the student index to the end of the array to the left
        	for(int i = stuix; i < studentRefSize - 1; ++i)
			{
            	studentRefs[i] = studentRefs[i+1];
        	}
        	// delete the duplicate last element (now empty)
        	delete &studentRefs[studentRefSize - 1];
        	// reduce the size of the array by one
        	studentRefSize -= 1;
    	}
	}
	
	// Method to delete a course from the system
    void SchoolManagerSystem::deleteCourse(Course& course)
	{
    	// Drop the course from all students who are registered for it
    	for(int i = 0; i < studentRefSize; ++i)
        	studentRefs[i].dropCourse(course);
    	// Get the index of the course being deleted
    	int courseix = courseIx(course);

    	if(courseix != -1)
    	{
        	// Shift the remaining courses in the array to fill the gap
        	for(int i = courseix; i < courseRefSize - 1; ++i)
        	{
            	courseRefs[i] = courseRefs[i+1];
        	}
        	// Delete the memory allocated for the deleted course
        	delete &courseRefs[courseRefSize - 1];
        	courseRefSize -= 1;
    	}
	}

	void SchoolManagerSystem::listAllStudents() const
	{
    	// Print out information for all students in the system
    	for(int i = 0; i < studentRefSize; ++i)
        	cout << i+1 << ": " << studentRefs[i] << endl;
	}

	void SchoolManagerSystem::listAllCourses() const
	{
    	// Print out information for all courses in the system
    	for(int i = 0; i < courseRefSize; ++i)
        	cout << i+1 << ": " <<  courseRefs[i] << endl;
	}

	int SchoolManagerSystem::menu() const
	{
    	// Display the main menu and get the user's choice
    	int choice;
    	cout << "Main Menu\n0 exit\n1 student\n2 course\n3 list_all_students\n4 list_all_courses\n>>";
    	cin >> choice;
    	return choice;
	}

	int SchoolManagerSystem::studentMenu() const
	{
    	// Display the student submenu and get the user's choice
    	int choice;
    	cout << "0 up\n1 add_student\n2 select_student\n>>";
    	cin >> choice;
    	return choice;
	}

	int SchoolManagerSystem::selectStudentMenu() const
	{
    	// Display the selected student submenu and get the user's choice
    	int choice;
    	cout << "0 up\n1 delete_student\n"
    	<<  "3 add_selected_student_to_a_course\n"
    	<<  "4 drop_selected_student_from_a_course\n>>";
    	cin >> choice;
    	return choice;
	}

	int SchoolManagerSystem::courseMenu() const
	{
    	// Display the course submenu and get the user's choice
    	int choice;
    	cout << "0 up\n1 add_course\n2 select_course\n>>";
    	cin >> choice;
    	return choice;
	}

	int SchoolManagerSystem::selectCourseMenu() const
	{
    	// Display the selected course submenu and get the user's choice
    	int choice;
    	cout << "0 up\n1 delete_course\n"
    	<< "2 list_students_registered_to_the_selected_course\n>>";
    	cin >> choice;
    	return choice;
	}
}
