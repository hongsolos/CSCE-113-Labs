//============================================================================
// File Name   : Menu.h
// Author      : Han Hong, Kyle Koiner
// Version     : 1.0
// Copyright   : All rights reserved c2014
// Description : C++ project 1 for CSCE 113
//============================================================================


#ifndef MENU_H_
#define MENU_H_

#include <string>
#include <stdexcept>
#include "GroupOfStudents.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using std::string;

class Menu{
public:
   struct InvalidData : std::runtime_error {
      InvalidData(): runtime_error("Invalid input data format") {}
   };

   struct InvalidFile : std::runtime_error {
      InvalidFile(): runtime_error("Invalid input file name") {}
   };

   enum OPTIONS{ INFO=1, READ_FILE=2, DISPLAY=3, DISPLAY_SORTED=4, HIGHEST=5, EXIT=6}; 
		
private:
   GroupOfStudents gs;
			
public:
   Menu();
   
   bool is_id_valid(string id) const;
   void display_menu() const;
   void display_info() const;
   void read_students();
   void display_students() const;
   void display_students_sorted();
   void display_highest_score() const;
};

#endif /*MENU_H_*/
