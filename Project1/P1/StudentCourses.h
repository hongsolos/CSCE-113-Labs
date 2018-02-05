//============================================================================
// File Name   : StudentCourses.h
// Author      : Han Hong, Kyle Koiner
// Version     : 1.0
// Copyright   : All rights reserved c2014
// Description : C++ project 1 for CSCE 113
//============================================================================


#ifndef _STUDENTCOURSES_H_
#define _STUDENTCOURSES_H_

#include "Student.h"
#include "Courses.h"

class StudentCourses
{
public:
   Student student;
   Courses courses;

   Student get_student() const { return student; }
   StudentCourses() {}
   StudentCourses(Student s, Courses c);
   double get_final_score() const;
   string get_first_name() const;
   string get_last_name() const;
   void display() const;
};

#endif
