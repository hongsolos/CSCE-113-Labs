//============================================================================
// File Name   : GroupOfStudents.cpp
// Author      : Han Hong, Kyle Koiner
// Version     : 1.0
// Copyright   : All rights reserved c2014
// Description : C++ project 1 for CSCE 113
//============================================================================

//  Your code starts here
#include <vector>
#include "StudentCourses.h"
#include "GroupOfStudents.h"

using std::vector;
using namespace std;

GroupOfStudents::GroupOfStudents(const vector<StudentCourses>& v) : stc_vec(v){}

//Display each element of the GroupOfStudents vector ---------------------------
void GroupOfStudents::display() const{
	for (int i = 0; (unsigned)i < stc_vec.size(); i++){
		cout << "Student: " << (i + 1) << endl;
		stc_vec[i].display();
	}
}

//Sorting using bubble sort ----------------------------------------------------
void GroupOfStudents::display_sorted(){
	vector<StudentCourses> v2 (stc_vec.size());
	for (int i = 0; (unsigned)i < stc_vec.size(); ++i){
		for (int j = 0; (unsigned)j < stc_vec.size()-1; ++j){
			if (stc_vec[j].get_last_name() < stc_vec[j+1].get_last_name()){
				v2[j] = stc_vec[j];
				v2[j+1] = stc_vec[j+1];	
			}
			if (stc_vec[j].get_last_name() > stc_vec[j+1].get_last_name()){
				v2[j] = stc_vec[j+1];
				v2[j+1] = stc_vec[j];
				for (int k = j+2; (unsigned)k < stc_vec.size(); ++k)
					v2[k] = stc_vec[k];
				stc_vec = v2;
			} 
			if (stc_vec[j].get_last_name() == stc_vec[j+1].get_last_name()){
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
	for (int i = 0; (unsigned)i < v2.size(); i++){
		v2[i].display();
	}
}

//Linear search the highest grade, then retrieve all students that have that highest grade ---------
void GroupOfStudents::display_highest() const{
	double highest_score = 0;
	for (int i = 0; (unsigned)i < stc_vec.size(); i++){
		if (highest_score < stc_vec[i].get_final_score())
			highest_score = stc_vec[i].get_final_score();
	}
	for (int i = 0; (unsigned)i < stc_vec.size(); i++){
		if (stc_vec[i].get_final_score() == highest_score){
			cout << "Students with highest score: \n" << endl;
			stc_vec[i].display();
		}
	}
}