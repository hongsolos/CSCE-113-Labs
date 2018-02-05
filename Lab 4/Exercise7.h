#include <iostream>
#include <string>

using namespace	std;

int main () {
   char c;
   int i = 0;
   char* array = new char[1000];
   while (std::cin >> c && c != '!' ) {
	array[i] = c;
	i++;
   }
}