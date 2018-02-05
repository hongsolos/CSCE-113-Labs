//------------------------------------------------------
//*  Exercise 7             By Han Hong      Lab 4     |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------

#include <iostream>
#include <string>

using namespace	std;

int main () {
   char c;
   int i = 0;
   char* array = new char[1000];
   cout << "Enter characters, ! to stop:" << endl;
   while (std::cin >> c && c != '!' ) {
	array[i] = c;
	i++;
   }
}