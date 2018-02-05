//============================================================================
// File Name   : Menu.cpp
// Author      : Han Hong and Kyle Koiner
// Version     : 1.0
// Copyright   : Not applicable
// Description : C++ project 1 for CSCE 113
//============================================================================

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
//This function checks if the Student's ID is a valid ID; it is valid if it has 9 digits
bool Menu::is_id_valid(string id) const{ 
	int idc = atoi(id.c_str());
	bool true_size;
	bool all_int = true;
	if (id.size() == 9)//checks if there are 9 characters
		true_size = true;
		
	char c;
	for(int i = 0; i < id.size(); ++i){//checks if those characters are all digits
		c = id[i];
		if(isdigit(c))
			all_int = true;
		else{
			all_int = false;
			i = id.size();
		}	
	}
	
	if (all_int == true && true_size == true)
		return true;
	else
		return false;
}
int Menu::check (vector<int> x) const{
	string temp = "";
	for (int i = 0; i < x.size(); i++){
		temp = x[i];
		for (int j = 0; j < temp.length() - 1; j++){
			if ((int)temp[j] > 10)
				throw invalid_argument("One of the value is not a digit");
			if (x[i] < 0 || x[i] > 100)
				throw invalid_argument("Out of bound");
		}
	}
}

//Shows the user what their options are; Displays Menu options
void Menu::display_menu () const{
	cout << "Welcome :" << endl;
	cout << "  [1] Display this assignment information." << endl;
	cout << "  [2] Enter student data file name for input." << endl;
	cout << "  [3] Display all students." << endl;
	cout << "  [4] Display all students in alphabetical order." << endl;
	cout << "  [5] Display students with the highest score." << endl;
	cout << "  [6] Exit program." << endl;
}
//The function that is called when 1 is inputed into the Menu
void Menu::display_info() const{
	cout << "****************************" << endl;
	cout << "* HAN HONG AND KYLE KOINER *" << endl;
	cout << "*         PROJECT 1        *" << endl;
	cout << "****************************" << endl;
}
//The function that is called when 2 is inputed into the Menu; reads in data from a file
void Menu::read_students(){
	vector<StudentCourses> vi;//A vector that will contain all the StudentCourses gained from the file; will be pushed back into the stc_vec member of a GroupOfStudents object
	string line, thing1, thing2, thing3;//4 strings, 1 represents the lines read in, the other 3 represent certain parts of that line
	vector<int> q(10);//A vector of quizzes
	vector<int> h(6);//A vector of quizzes
	vector<int> t(4);//A vector of quizzes
	int j = 0;//An iterator for the while loop that only iterates in a certain part
	char d = 'd';//A character variable that will be used to read in individual characters
	
	cout << "Please insert a file name.\n";//A prompt
	string name;//Name of the file the user chooses
	cin >> name;
	ifstream infile;//The input file stream
	
	if(!ifstream(name))//If there is no file with the name the user gave, throw a function the outputs an error message
		throw Menu::InvalidFile();
	else//Otherwise, open the file
		infile.open(name);	
	while(!infile.eof()){//Until the end of the file has been met, do the following code
		d = 'd';//This and the next 3 lines are initializers
		thing1 = "";
		thing2 = "";
		thing3 = "";
		getline(infile, line);//Get a line
//Read in student info ------------------------------------------------------------------
		for (int i = 0; d != ' '; ++i){//Reads in characters and puts them into one of the thing strings until a space is found
			d = line[i];
			if(d!=' ')
				thing1.push_back(d);
		}
		d = 'd';
		for (int i = 1; d != ' '; ++i){//Reads in characters (starting from after the last space found) and puts them into the next thing string until a space is found
			d = line[thing1.size()+i];
			if(d!=' ')
				thing2.push_back(d);
		}
		d = 'd';
		for (int i = thing1.size()+thing2.size()+2; i < line.size()-1; ++i){//Reads in characters (starting from the last space found) and puts them into the next string until the end of the line
			d = line[i];
			if(d != ' ')
				thing3.push_back(d);
		}
		Student s(thing1, thing2, thing3);//Put first name, last name, and ID into a student
//Read in quiz grades ----------------------------------------------------------
		getline(infile, line);//Get the next line
		d = '0';
		j = 0;
		for (int i = 0; i < 10; ++i){
			thing1 = "";
			d = '0';
			while (isdigit(d)){//While d is a digit, put it into a string, then when it no longer equals a digit, convert that string into an integer and put it into the vector of quizzes
				d = line[j];
				if(isdigit(d))
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
			while (isdigit(d)){//While d is a digit, put it into a string, then when it no longer equals a digit, convert that string into an integer and put it into the vector of homework
				d = line[j];
				if(isdigit(d)){
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
		for(int i = 0; i < 4; ++i){//While d is a digit, put it into a string, then when it no longer equals a digit, convert that string into an integer and put it into the vector of tests
			thing1 = "";
			d = '0';
			while (isdigit(d)){
				d = line[j];
				if(isdigit(d)){
					thing1.push_back(d);
				}	
				j++;	  
			}		  
			t[i] = atoi(thing1.c_str());
		}	
		Courses c (q, h, t);//Put the list of quizzes, homework, and tests into a courses object
	//Check if all is is digit
		try {
			check (q);
			check (h);
			check (t);
		}
		catch (const invalid_argument& e){
			throw e;
		}
		
		c.calc_final_score();//Calculate the final score and letter grade of student so it gets saved
		c.calc_letter_grade();
		StudentCourses v (s,c);//Put the data of student and courses into one location by putting the two objects into a StudentCourses object
		
		if (is_id_valid(thing3) == false /*|| enough_grades(q, 10) == false || enough_grades(h, 6) == false || enough_grades(t, 4) == false*/)//If the ID is invalid, output an error
		{
			cout << "This student: \n\n"; v.display(); cout << endl << "has invalid information.\n\n";
			if (is_id_valid(thing3) == false)//Specifies the error
				if (thing3.size() != 9)//If the ID had an incorrect number of digits, output that
					cout << thing3[9] << ' ' << "The student's ID did not have 9 digits.\n\n";
				else//If not, then output that there must have been a non-digit character
					cout << "Even though there were 9 characters in the ID, not all were digits.\n\n";
		}

		else
			vi.push_back(v);//If all the data is valid, puts the StudentCourses object into an object of GroupOfStudents, which contains a vector of StudentCourses
		
	}
	GroupOfStudents test(vi);//Create a GroupOfStudents object and puts the vector of the information into it
	gs = test;
}
void Menu::display_students() const{
	gs.display();
}
void Menu::display_students_sorted(){
	gs.display_sorted();
}
void Menu::display_highest_score() const{
	gs.display_highest();
}