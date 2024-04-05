#include "Student.h" 				// Include the header file for the Student class.
#include "Course.h"					// Include the header file for the Course class.
#include "SchoolManagerSystem.h"	// Include the header file for the SchoolManagerSystem class.
#include <iostream>					// Include the header file for input/output streams.

using namespace std;
using namespace PA4;

int main()
{
    SchoolManagerSystem system;

    // Show main menu and get user's choice
    int choice = system.menu();

    // Keep looping until user chooses to exit
    while(choice != 0)
	{
        if(choice == 1)
		{
            choice = system.studentMenu();
            while(choice != 0)
			{     
                if(choice == 1)	 // Add student
				{ 
                    cout << ">>";
                    system.add_student();
                }
                
                if(choice == 2)	 // Edit student
				{ 
                    system.listAllStudents(); // Show all students
                    cout << ">>";
                    Student& s = system.select_student(); // Select a student
                    choice = system.selectStudentMenu(); // Show edit options

                    if (choice == 0)
                        break;
                    else if(choice == 1)	// Delete student
					{ 
                        system.deleteStudent(s);
                    }
                    else if(choice == 3) // Assign student to course
					{ 
                        system.listAllCourses(); // Show all courses
                        cout << ">>";
                        int courseIx;
                        cin >> courseIx;
                        Course &c = system.getCourse(courseIx - 1);
                        s.assignCourse(c);
                    }
                    else if(choice == 4) // Drop student from course
					{ 
                        system.listAllCourses(); // Show all courses
                        cout << ">>";
                        Course &c = system.select_course();
                        s.dropCourse(c);
                    }
                }
                choice = system.studentMenu();
            }
        }
        
		else if(choice == 2) // Course menu
		{ 
            choice = system.courseMenu();
            while(choice != 0)
			{ 
                if(choice == 1) // Add course
				{ 
                    cout << ">>";
                    system.add_course();
                }
                else if(choice == 2) // Edit course
				{ 
                    system.listAllCourses(); // Show all courses
                    cout << ">>";
                    Course& c = system.select_course(); // Select a course
                    choice = system.selectCourseMenu(); // Show edit options

                    if (choice == 0)
                        break;
                    else if(choice == 1) // Delete course
					{ 
                        system.deleteCourse(c);
                    }
                    else if(choice == 2) // List registered students
					{ 
                        c.printRegistered();
                    }
                }

                choice = system.courseMenu();
            }
        }
        else if(choice == 3)  // List all students
		{
            system.listAllStudents();
        }
        else if(choice == 4) // List all courses
		{ 
            system.listAllCourses();
        }
        choice = system.menu();
    }

    return 0;
}
