//============================================================================
// File Name   : Courses.cpp
// Author      : Han Hong and Kyle Koiner
// Version     : 1.0
// Copyright   : Not applicable
// Description : C++ project 1 for CSCE 113
//============================================================================

//  Your code starts here
#include <iostream>
#include <vector>
#include "Courses.h"
using std::vector;
using namespace std;

//Calculates the final score by averaging the quiz, homework, and test grades, weighting them, and then rounding them to the nearest integer
void Courses::calc_final_score() {
	double avg_quiz = ((quiz[0]+quiz[1]+quiz[2]+quiz[3]+quiz[4]+quiz[5]+quiz[6]+quiz[7]+quiz[8]+quiz[9])/10)*0.05;
	double avg_homework = ((homework[0]+homework[1]+homework[2]+homework[3]+homework[4]+homework[5])/6)*0.5;
	double avg_test = ((test[0]+test[1]+test[2]+test[3])/4)*0.45;
	int rounded_avg;
	double dec_avg; 
	dec_avg = avg_quiz+avg_homework+avg_test;
	rounded_avg = dec_avg;
	if (dec_avg > rounded_avg + 0.5)
	  final_score = rounded_avg+1;
	else if (dec_avg = rounded_avg + 0.5)
	  final_score = rounded_avg+1;  
	else if (dec_avg < rounded_avg + 0.5)
	  final_score = rounded_avg;   
}
//Compares the final score to different ranges to determine the letter grade of the student
void Courses::calc_letter_grade(){
	if (0 <= final_score && final_score <= 59)
		letter_grade = 'F';
	else if (60 <= final_score && final_score <= 69)
		letter_grade = 'D';
	else if (70 <= final_score && final_score <= 79)
		letter_grade = 'C';	
	else if (80 <= final_score && final_score <= 89)
		letter_grade = 'B';
	else if (90 <= final_score && final_score <= 100)
		letter_grade = 'A';
}
//A getter function for the final score
double Courses::get_final_score() const {
	return final_score;
}
//Displays the final score and the letter grade of the Courses object
void Courses::display() const{
	cout << "The final score: " << final_score 
		 << "\n" << "Your letter grade: " << letter_grade << endl;
}