//============================================================================
// File Name   : Courses.cpp
// Author      : Han Hong, Kyle Koiner
// Version     : 1.0
// Copyright   : All rights reserved c2014
// Description : C++ project 1 for CSCE 113
//============================================================================

//  Your code starts here
#include <iostream>
#include <vector>
#include "Courses.h"
using std::vector;
using namespace std;


//Calculating the final score -------------------------------------------------
void Courses::calc_final_score() {
	double avg_quiz = ((quiz[0]+quiz[1]+quiz[2]+quiz[3]+quiz[4]+quiz[5]+quiz[6]+quiz[7]+quiz[8]+quiz[9])/10)*0.05;
	double avg_homework = ((homework[0]+homework[1]+homework[2]+homework[3]+homework[4]+homework[5])/6)*0.5;
	double avg_test = ((test[0]+test[1]+test[2]+test[3])/4)*0.45;
	final_score = avg_quiz+avg_homework+avg_test;
}

//Giving the student a letter grade in accordance to the final score ----------
void Courses::calc_letter_grade(){
	if (0 <= final_score && final_score <= 59.99)
		letter_grade = 'F';
	else if (60 <= final_score && final_score <= 69.99)
		letter_grade = 'D';
	else if (70 <= final_score && final_score <= 79.99)
		letter_grade = 'C';	
	else if (80 <= final_score && final_score <= 89.99)
		letter_grade = 'B';
	else if (90 <= final_score && final_score <= 100)
		letter_grade = 'A';
}

double Courses::get_final_score() const {
	return final_score;
}

//Display the Courses information -------------------------------------------------
void Courses::display() const{
	cout << "The final score: " << final_score 
		 << "\n" << "Your letter grade: " << letter_grade << endl;
}