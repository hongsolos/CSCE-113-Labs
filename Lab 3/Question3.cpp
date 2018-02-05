//------------------------------------------------------
//*  Question 3           By Han Hong         Lab 3    |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Create a new vector with reverse content
vector<double> reverseNew (vector<double>x){
	vector<double>y(x.size());
	int z = x.size()-1;
	for (int i = 0; i < x.size(); i++){
		y[i] = x[z - i];
	}
	return y;
}

//Reverse the content inside the vector without creating new vector
void swapInside(vector<double>& test, vector<double>y){
	test.swap(y);
}

//Print all elements inside a vector
void print(vector<double> x) {
	for (int i = 0; i < x.size(); i++){
		cout << x[i] << "\n";
	}
}

int main () {
	vector<double>test(5);
	test[0] = 5;
	test[1] = 4;
	test[2] = 3;
	test[3] = 2;
	test[4] = 1;
	
	vector<double> newVector(reverseNew(test));
	
	swapInside(test, newVector);
	cout << "First Reverse Function" << "\n";
	print (test);
	cout << "Second Reverse Function" << "\n";
	print (newVector);	
}
