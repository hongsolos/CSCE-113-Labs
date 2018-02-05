//============================================================================
// File Name   : StudentCourses.cpp
// Author      : Han Hong and Kyle Koiner
// Version     : 1.0
// Copyright   : Not applicable
// Description : C++ project 1 for CSCE 113
//============================================================================

// Your code starts here
#include "Student.h"
#include "Courses.h"
#include "StudentCourses.h"

 StudentCourses::StudentCourses(Student s, Courses c): student(s), courses(c){}//This is the constructor for a StudentCourses object

double StudentCourses::get_final_score() const{//this is a getter function to get the final score member of courses
	return courses.get_final_score();
}
string StudentCourses::get_last_name() const{//this is a getter function to get the last name member of student
	return student.get_last_name();
}
string StudentCourses::get_first_name() const{//this is a getter function to get the first name member of student
	return student.get_first_name();
}
void StudentCourses::display() const{//This is the display function for StudentCourses; it calls on the display functions from its members, Student and Courses
	student.display();
	courses.display();
}
