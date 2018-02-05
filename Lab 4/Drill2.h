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
	int p2 = array;
	cout << p2 << " " << endl;
	print_array(cout, array, 7);
	
	int* p3 = p2;
	p1 = p2;
	p3 = p2;
	cout << p1 << " " << p2;
	delete[] array;
	
	int* array10 = new int [10];
	for (int i = 0; i < 7; i++) {
		array10[i] = pow(2, i);
	}
	p1 = array10;
	
	int* array11 = new int [10];
	for (int i = 0; i < 7; i++) {
		array11[i] = pow(2, i);
	}
	p2 = array11;
	
	p2 = &p1;
}      

