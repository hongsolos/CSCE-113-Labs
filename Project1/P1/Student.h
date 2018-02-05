//============================================================================
// File Name   : Student.h
// Author      : Han Hong, Kyle Koiner
// Version     : 1.0
// Copyright   : All rights reserved c2014
// Description : C++ project 1 for CSCE 113
//============================================================================


#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>

using std::string;

class Student
{
private:
   string firstname;
   string lastname;
   string id;

public:
   Student () {}
   Student(const string& f, const string& l, const string& i) :
      firstname(f), lastname(l), id(i) {}
   string get_first_name() const;
   string get_last_name() const;
   string get_id() const;
   void display() const;
};

#endif /*STUDENT_H_*/
