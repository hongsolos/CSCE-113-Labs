#include <iostream>
#include <string>

using namespace std;

int main(){
	String first;
	String second;
	cout << "Enter first string: ";
	cin >> first;
	cout << "Enter second string: ";
	cin >> second;
	
	char concat = new char [first, second];
	
	cout << concat;
}