//======================================================================
//*  FILE NAME: Map.cpp        TTTTTTTTTT   A     M       M UU      UU |
//*  NAME: Han Hong                TT      A A    MM     MM UU      UU |
//*  Lab 10                        TT     A   A   M M   M M UU      UU |
//*  CSCE 113 SECTION 501          TT    AAAAAAA  M  M M  M UU      UU |
//*  UIN: 824000237                TT   AA     AA M   M   M  UUUUUUUU  |
//======================================================================

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

//CALCULATE THE AVERAGE ----------------------------------------------------
void average_GPA(map <int,double> &mid){
	double average = 0.0;
	map <int, double>::iterator it;
	
	for(it = mid.begin(); it != mid.end(); it++)
		average += it->second;
	average = (average/mid.size());
	cout<< "Students' average GPA: "<< average << endl;
}

//COPY VALUES FROM MID TO MDI, REVERSE UIN ---------------------------------
void copy_change_key(map <int,double> &mid, map <double, int> &mdi){
	typedef map <int,double>::const_iterator It;
	int reverse = 0;
	
	for (It p = mid.begin(); p!= mid.end(); ++p){
		string normal = to_string(p->first);
		string reverseStr(normal.rbegin(), normal.rend());
		int reverse = std::atoi(reverseStr.c_str());
		mdi[p->second] = reverse;
	}
}

//PRINT THE MAP
//CAN ONLY BE USED FOR MID --------------------------------------------------
void print (map <int,double> &mid){
	typedef map <int,double>::const_iterator It;
	cout << "\nStudents' UIN and GPA: " << endl;
	for (It p = mid.begin(); p!= mid.end(); ++p)
		cout << "UIN: " << p->first << '\n'
			 << "GPA: " << p->second << endl;
}

int main(){
	map <int,double> mid;
	map <double,int> mdi;
	string last_name;
	int UIN;
	double GPA;
	
//PART A READ VALUE INTO MAP -------------------------------------------------
	ifstream read;
	read.open("students.txt");
	while(read.good()){
		read >> last_name >> UIN >> GPA;
		mid[UIN] = GPA;
	}
//PART B DISPLAY THE MAP -----------------------------------------------------
	print(mid);
	
//PART C AVERAGE GPA ---------------------------------------------------------
	average_GPA(mid);
	
//PART D REMOVE THE LAST PAIR ------------------------------------------------
	mid.erase(--mid.rbegin().base());
	cout <<"\nLast pair has been removed." << endl;
	print(mid);
	
//PART E AND F COPY VALUES, GPA FIRST REVERSE UIN ----------------------------
	copy_change_key(mid,mdi);
	typedef map <double,int>::const_iterator It;
	cout << "\nStudents' UIN and GPA in mdi: " << endl;
	for (It p = mdi.begin(); p!= mdi.end(); ++p)
		cout << "UIN " << p->second << '\n'
			 << "GPA " << p->first << endl;
}