//============================================================================
// File Name   : GroupOfStudents.h
// Author      : Han Hong and Kyle Koiner
// Version     : 1.0
// Copyright   : Not applicable
// Description : C++ project 1 for CSCE 113
//============================================================================


#ifndef GROUPOFSTUDENTS_H_
#define GROUPOFSTUDENTS_H_

#include <vector>
#include "StudentCourses.h"

using std::vector;

class GroupOfStudents
{
private:
   vector<StudentCourses> stc_vec;
   void search_for_highest(vector<int>& indices_max) const;

public:
   const vector<StudentCourses>& get_student_courses() const
      { return stc_vec; }
   GroupOfStudents() {}
   GroupOfStudents(const vector< StudentCourses >& v);
   void display() const;
   void display_sorted();
   void display_highest() const;
};

#endif /*GROUPOFSTUDENTS_H_*/
