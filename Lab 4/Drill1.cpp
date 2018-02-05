//------------------------------------------------------
//*  Drill 1                By Han Hong      Lab 4     |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>

using namespace	std;

//Question 4
void print_array10(ostream& x, int*a){
	for (int i = 0; i < 10; i++) {
		x << a[i] << endl;
	}
}     

//Question 7
void print_array(ostream& x, int*a, int n){
	for (int i = 0; i < n; i++) {
		x << a[i] << endl;
	}
}      

void print_vector(vector<int> x) {
	for (int i = 0; i < x.size(); i++){
		cout << x[i] << "\n";
	}
}              

int main () {
//Question 1
	int* array = new int [10];

//Question 2	
	for (int i = 0; i < 10; i++) {
		cout << array [i] << endl;
	}
	cout << "\n" << endl;

//Question 3
	delete [] array;

//Question 5	
	int* array5 = new int [10];
	for (int i = 0; i < 10; i++) {
		array5[i] = 100+i;
	}
	print_array10(cout, array5);

//Question 6
	int* array6 = new int [11];
	for (int i = 0; i < 11; i++) {
		array6[i] = 100+i;
	}
	print_array(cout, array6, 11);
	
//Question 8
	int* array8 = new int [20];
	for (int i = 0; i < 20; i++) {
		array8[i] = 100+i;
	}
	print_array(cout, array8, 20);

//Question 9 - YES

//Question 10
	vector<int>vector1(10);
	for (int i = 0; i < 10; i++) {
		vector1[i] = 100+i;
	}
	print_vector(vector1);
	
	vector<int>vector2(11);
	for (int i = 0; i < 11; i++) {
		vector2[i] = 100+i;
	}
	print_vector(vector2);
	
	vector<int>vector3(20);
	for (int i = 0; i < 20; i++) {
		vector3[i] = 100+i;
	}
	print_vector(vector3);
}      

