#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include "Lab2.h"

using namespace std;

//Check if an input is number, if it is not a number then force user to re enter
//Code block was obtained from and authorized for educational purpose through a YouTube tutorial video by SchoolFreeware: https://www.youtube.com/watch?v=gzzXVX6s4w8
int checkValid(){
	bool inFail;
	int x;
	cin >> x;
	inFail = cin.fail();
 	while (inFail == true){
		cout << "Error, NOT A NUMBER! ENTER AGAIN: ";
		cin >> x;
		inFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
   
    return x;
}

//Check if an input is 0
//In this particular case, is meant for checking variable a is a non zero
double checkZero (double x) {
	while (x == 0){
			cout << "Invalid, please re-enter A: ";
			cin >> x;
	}
	return x;
}

//Function to calculate roots with given quadratic formula
double root (double a, double b, double c){
	if ((b*b - 4*a*c) < 0){
		double d = sqrt((b*b - 4*a*c)*(-1))/(2*a);
		if (d == 0) {//Avoid attaching i to a 0 number
			cout << "First root = " << (b/(2*a)*(-1)) << " + " << d << " \n";
			cout << "Second root = " << (b/(2*a)*(-1)) << " - " << d;
		}
		else {//Avoid square root of a negative number
		cout << "First root = " << (b/(2*a)*(-1)) << " + " << d << "i " << " \n";
		cout << "Second root = " << (b/(2*a)*(-1)) << " - " << d << "i ";
		}
	}
	else {
		double d = sqrt(((b*b) - (4*a*c)))/(2*a);
		cout << "First root = " << (b/(2*a)*(-1)) + d << " \n";
		cout << "Second root = " << (b/(2*a)*(-1)) + d;
	}
}

//Check to see if the user enter Yes or No to repeat the program
bool repeatFunction (string x){
	if (x == "Yes" || x == "Y" || x == "y"){
		return true;
	} else {
	return false;
	}
}