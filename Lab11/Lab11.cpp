//======================================================================
//*  FILE NAME: Lab11.cpp                        |* * * * * |##########|
//*  NAME: Han Hong                              | * * * * *|##########|
//*  Lab 11                                      |* * * * * |##########|
//*  CSCE 113 SECTION 501                        |#####################|
//*  UIN: 824000237                              |#####################|
//======================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <boost/regex.hpp>

using namespace std;

int main(){
	string temp;
	ifstream read;

	read.open("data.txt"); //Open the desired here

	if(read.good()){
		boost :: regex format("\\d{3}-\\d{3}-\\d{3}"); //UIN format ###-###-###
		while(getline(read,temp)){
			boost :: smatch found;
			if(boost :: regex_search(temp, found, format)){
				cout << boost :: regex_replace(temp,format, "XXX-XXX-XXX") << endl; //Replacing the found format with XXX-XXX-XXX
			} else {
				cout << temp << endl;
			}
		}
	}
	read.close();
}