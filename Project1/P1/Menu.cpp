//============================================================================
// File Name   : Menu.cpp
// Author      : Han Hong, Kyle Koiner
// Version     : 1.0
// Copyright   : All rights reserved c2014
// Description : C++ project 1 for CSCE 113
//============================================================================

//  Your code starts here
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Menu.h"

using namespace std;
using std::string;

Menu::Menu() {}


//Checking if the value is an id -------------------------------------------
bool Menu::is_id_valid(string id) const{
	int idc = atoi(id.c_str());
	if (idc <= 99999999 || idc >= 1000000000)
		return false;
	return true;
}

void Menu::display_menu () const{
	cout << "Welcome :" << endl;
	cout << "  [1] Display this assignment information." << endl;
	cout << "  [2] Enter student data file name for input." << endl;
	cout << "  [3] Display all students." << endl;
	cout << "  [4] Display all students in alphabetical order." << endl;
	cout << "  [5] Display students with the highest score." << endl;
	cout << "  [6] Exit program." << endl;
}
void Menu::display_info() const{
	cout << "****************************" << endl;
	cout << "* HAN HONG AND KYLE COINER *" << endl;
	cout << "*         PROJECT 1        *" << endl;
	cout << "****************************" << endl;
}


//Read the students file in ----------------------------------------------
void Menu::read_students(){
	string file_name;
	vector<StudentCourses> vi;
	string line, thing1, thing2, thing3;
	vector<int> q(10);
	vector<int> h(6);
	vector<int> t(4);
	int j = 0;
	char d = 'd';
	cout << "Please enter the file name for input: ";
	cin >> file_name;
	
	ifstream infile;
	infile.open(file_name);
	while(!infile.eof()){
		d = 'd';
		thing1 = "";
		thing2 = "";
		thing3 = "";
		getline(infile, line);
//Read in student info ------------------------------------------------------------------
		for (int i = 0; d != ' '; ++i){
			d = line[i];
			if(d!=' ')
				thing1.push_back(d);
		}
		d = 'd';
		for (int i = 1; d != ' '; ++i){
			d = line[thing1.size()+i];
			if(d!=' ')
				thing2.push_back(d);
		}
		d = 'd';
		for (int i = 2; d != ' '; ++i){
			d = line[thing1.size()+thing2.size()+i];
			if(d != ' ')
				thing3.push_back(d);
		}
		Student s(thing1, thing2, thing3);
//Read in quiz grades ----------------------------------------------------------
		getline(infile, line);
		d = '0';
		j = 0;
		for (int i = 0; i < 10; ++i){
			thing1 = "";
			d = '0';
			while (d!= ' '){
				d = line[j];
				if(d!=' ')
					thing1.push_back(d);
				j++;	  
			}		  
			q[i] = atoi(thing1.c_str());
				  
		}
//Read in home works -----------------------------------------------------------
		getline(infile, line);
		d = '0';
		j = 0;
		for (int i = 0; i < 6; ++i){
			thing1 = "";
			d = '0';
			while (d!= ' '){
				d = line[j];
				if(d!=' '){
				thing1.push_back(d);
				}	
			j++;	  
			}		  
			h[i] = atoi(thing1.c_str());
				  
		}
//Read in tests -----------------------------------------------------------------
		getline(infile, line);
		d = '0';
		j = 0;
		for (int i = 0; i < 4; ++i){
			thing1 = "";
			d = '0';
			while (d!= ' '){
				d = line[j];
				if(d!=' '){
					thing1.push_back(d);
				}	
				j++;	  
			}		  
			t[i] = atoi(thing1.c_str());
			  
		}
		Courses c (q, h, t);
		c.calc_final_score();
		c.calc_letter_grade();
		StudentCourses v (s,c);
		vi.push_back(v);
	}
	GroupOfStudents test(vi);
	gs = test;
}

//Display all students ------------------------------------------------------
void Menu::display_students() const{
	gs.display();
}

//Display students in alphabetical order ------------------------------------
void Menu::display_students_sorted(){
	gs.display_sorted();
}

//Display all students who have the highest grades --------------------------
void Menu::display_highest_score() const{
	gs.display_highest();
}