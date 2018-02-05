//============================================================================
// File Name   : GroupOfStudents.cpp
// Author      : Han Hong and Kyle Koiner
// Version     : 1.0
// Copyright   : Not applicable
// Description : C++ project 1 for CSCE 113
//============================================================================

#include <vector>
#include "StudentCourses.h"
#include "GroupOfStudents.h"

using std::vector;
using namespace std;

GroupOfStudents::GroupOfStudents(const vector<StudentCourses>& v) : stc_vec(v){} //Constructor for GroupOfStudents that creates an empty vector for the stc_vec member

//Displays the information in the GroupOfStudents object by calling on the display function for StundentCourses for the ith element of the StudentCourses vector and iterates i
void GroupOfStudents::display() const{
	for (int i = 0; (unsigned)i < stc_vec.size(); i++){
		cout << "Student: " << (i + 1) << endl;
		stc_vec[i].display();
		cout << endl;
	}
	
	if (stc_vec.size() == 0)
		cout << "No data\n";
}
//Sorts the vector member of GroupOfStudents by the last_name member of the StudentCourses inside the vector with a bubble sort; if the last names are equal, sorts by first name
void GroupOfStudents::display_sorted(){
	vector<StudentCourses> v2 (stc_vec.size());//A temporary vector to hold values and places with the same size as the vector you want to sort
	for (int i = 0; (unsigned)i < stc_vec.size(); ++i){
		for (int j = 0; (unsigned)j < stc_vec.size()-1; ++j){
			if (stc_vec[j].get_last_name() < stc_vec[j+1].get_last_name()){//If the next element is larger than the element you are on, their places are the same in the temp vector
				v2[j] = stc_vec[j];
				v2[j+1] = stc_vec[j+1];	
			}
			if (stc_vec[j].get_last_name() > stc_vec[j+1].get_last_name()){//If the next element is smaller than the element you are on, their places are switched in the temp vector, but the other positions are the same
				v2[j] = stc_vec[j+1];
				v2[j+1] = stc_vec[j];
				for (int k = j+2; (unsigned)k < stc_vec.size(); ++k)
					v2[k] = stc_vec[k];
				stc_vec = v2;
			} 
			if (stc_vec[j].get_last_name() == stc_vec[j+1].get_last_name()){//If the next element is equal to the element you are on, do this sort by first name
				for (int a = 0; (unsigned)a < stc_vec.size(); ++a){
					for (int b = 0; (unsigned)b < stc_vec.size()-1; ++b){
						if (stc_vec[b].get_first_name() < stc_vec[b+1].get_first_name()){
							v2[b] = stc_vec[b];
							v2[b+1] = stc_vec[b+1];	
						}
						if (stc_vec[b].get_first_name() > stc_vec[b+1].get_first_name()){
							v2[b] = stc_vec[b+1];
							v2[b+1] = stc_vec[b];
							for (int c = b+2; (unsigned)c < stc_vec.size(); ++c)
								v2[c] = stc_vec[c];
							stc_vec = v2;
						} 
					}
				}
			}
		}
	}
	for (int i = 0; (unsigned)i < v2.size(); i++){//After sorting them, the students are displayed in the now sorted order
		v2[i].display();
		cout << endl;
	}
}
//Goes through the vector member of a GroupOfStudents object and prints the students with the highest final score
void GroupOfStudents::display_highest() const{
	double highest_score = 0;
	for (int i = 0; (unsigned)i < stc_vec.size(); i++){
		if (highest_score < stc_vec[i].get_final_score()) //if the element is greater than highest_score, then highest_score will now have that element's value
			highest_score = stc_vec[i].get_final_score();
	}
	cout << "Students with highest score: \n" << endl;
	for (int i = 0; (unsigned)i < stc_vec.size(); i++){//Prints students with the highest score
		if (stc_vec[i].get_final_score() == highest_score){
			stc_vec[i].display();
			cout << endl;
		}
	}
}