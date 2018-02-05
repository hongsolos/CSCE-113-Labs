//======================================================================
//*  FILE NAME: flight.h       TTTTTTTTTT   A     M       M UU      UU |
//*  NAME: Han Hong                TT      A A    MM     MM UU      UU |
//*  Pre Lab                       TT     A   A   M M   M M UU      UU |
//*  CSCE 113 SECTION 501          TT    AAAAAAA  M  M M  M UU      UU |
//*  UIN: 824000237                TT   AA     AA M   M   M  UUUUUUUU  |
//======================================================================

#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
class Flight
{
	private:
		string flight_number;
		string destination;
		string departure_time;
		string gate_number;
	public:
		Flight() {}
		Flight(const string &a, const string &b, const string &c, const string &d) :
			flight_number(a), destination(b), departure_time(c), gate_number(d){}
		
		string get_flight_number() const;
		string get_destination() const;
		int get_departure_time() const;
		string get_gate_number() const;
		void display() const;
};
#endif