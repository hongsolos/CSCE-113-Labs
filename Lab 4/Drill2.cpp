//------------------------------------------------------
//*  Drill 2                By Han Hong      Lab 4     |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace	std;
void print_array(ostream& x, int*a, int n){
	for (int i = 0; i < n; i++) {
		x << a[i] << endl;
	}
}      
         

int main () {

//Question 1
	int interger = 7;
	int* p1 = &interger;
//Question 2
	cout << p1 << " " << interger << endl;
//Question 3	
	int* array = new int [7];
	for (int i = 0; i < 7; i++) {
		array[i] = pow(2, i);
	}
	int* p2 = array;
//Question 4
	cout << p2 << " " << endl;
	print_array(cout, array, 7);
//Question 5	
	int* p3 = p2;
//Question 6
	p1 = p2;
//Question 7
	p3 = p2;
//Question 8
	cout << p1 << " " << p2;
//Question 9
	delete[] array;
//Question 10	
	int* array10 = new int [10];
	for (int i = 0; i < 7; i++) {
		array10[i] = pow(2, i);
	}
	p1 = array10;
//Question 11	
	int* array11 = new int [10];
	p2 = array11;
//Question 12
	p2 = p1;
//Question 13
	vector<int>vector1(10);
	for (int i = 0; i < 10; i++) {
		vector1[i] = pow(2, i);
	}
	
	vector<int>vector2(11);
	
	p2 = p1;   
}      

