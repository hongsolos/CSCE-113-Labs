//============================================================================
// File Name   : Student.h
// Author      : Han Hong and Kyle Koiner
// Version     : 1.0
// Copyright   : Not applicable
// Description : C++ project 1 for CSCE 113
//============================================================================


#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>

using std::string;

class Student//A class containing 3 members that individualize a student; their first name, last name, and student id
{
private:
   string firstname;
   string lastname;
   string id;

public:
   Student () {}
   Student(const string& l, const string& f, const string& i) :
      lastname(l), firstname(f), id(i) {} //The constructor of a Student
   string get_first_name() const;
   string get_last_name() const;
   string get_id() const;
   void display() const;
};

#endif /*STUDENT_H_*/
