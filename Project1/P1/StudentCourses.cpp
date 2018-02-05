//============================================================================
// File Name   : StudentCourses.cpp
// Author      : Han Hong, Kyle Koiner
// Version     : 1.0
// Copyright   : All rights reserved c2014
// Description : C++ project 1 for CSCE 113
//============================================================================

// Your code starts here
#include "Student.h"
#include "Courses.h"
#include "StudentCourses.h"

//Redefining the constructor -------------------------------------------------
StudentCourses::StudentCourses(Student s, Courses c): student(s), courses(c){} 

double StudentCourses::get_final_score() const{
	return courses.get_final_score();
}
string StudentCourses::get_last_name() const{
	return student.get_last_name();
}
string StudentCourses::get_first_name() const{
	return student.get_first_name();
}

//Display the StudentCourses information, via display methods of Student and Courses class
void StudentCourses::display() const{
	student.display();
	courses.display();
}
