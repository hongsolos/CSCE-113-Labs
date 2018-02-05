//============================================================================
// File Name   : Student.cpp
// Author      : Han Hong and Kyle Koiner
// Version     : 1.0
// Copyright   : Not applicable
// Description : C++ project 1 for CSCE 113
//============================================================================

//  Your code starts here
#include <string>
#include <iostream>
#include "Student.h"
using std::string;
using namespace std;

string Student:: get_first_name() const{//this is a getter function to get the first name member of student
	return firstname;
}
string Student::get_last_name() const{//this is a getter function to get the last name member of student
	return lastname;
}
string Student::get_id() const{//this is a getter function to get the ID member of student
	return id;
}
void Student::display() const {//this function displays all 3 members of a student
	cout << "First Name: " << firstname << "\n" 
	     << "Last Name: " << lastname << "\n" 
		 << "ID: " << id << endl;
}
