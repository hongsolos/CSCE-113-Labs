//======================================================================
//*  FILE NAME: flight.cpp     TTTTTTTTTT   A     M       M UU      UU |
//*  NAME: Han Hong                TT      A A    MM     MM UU      UU |
//*  Pre Lab                       TT     A   A   M M   M M UU      UU |
//*  CSCE 113 SECTION 501          TT    AAAAAAA  M  M M  M UU      UU |
//*  UIN: 824000237                TT   AA     AA M   M   M  UUUUUUUU  |
//======================================================================

#include <string>
#include <iostream>
#include <algorithm>
#include "flight.h"

using std::string;
using namespace std;

string Flight::get_flight_number() const{
	return flight_number;
}
string Flight::get_destination() const{
	return destination;
}

//Slice the semicolon off the formatted departure =====================
//A copy of the "sliced" data is return
int Flight::get_departure_time() const{
	int temp;
	char colon = ':';
	string temps = departure_time;
	temps.erase(std::remove(temps.begin(), temps.end(), colon), temps.end());
	temp = stoi(temps);
	return temp;
}
string Flight::get_gate_number() const{
	return gate_number;
}

//Formatted display with detailed information ========================
void Flight::display() const{

	cout << "Flight number: " << flight_number << '\n'
		 << "Destination: " << destination << '\n'
		 << "Departure Time : " << departure_time << '\n'
		 << "Gate Number: " << gate_number << '\n' << endl;
}	