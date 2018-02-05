//============================================================================
// File Name   : Student.cpp
// Author      : Han Hong, Kyle Koiner
// Version     : 1.0
// Copyright   : All rights reserved c2014
// Description : C++ project 1 for CSCE 113
//============================================================================

//  Your code starts here
#include <string>
#include <iostream>
#include "Student.h"
using std::string;
using namespace std;

string Student:: get_first_name() const{
	return firstname;
}
string Student::get_last_name() const{
	return lastname;
}
string Student::get_id() const{
	return id;
}

//Display the student information ----------------------------------------------
void Student::display() const { 
	cout << "First Name: " << firstname << "\n" 
	     << "Last Name: " << lastname << "\n" 
		 << "ID: " << id << endl;
}
