//------------------------------------------------------
//*  Customer         By Han Hong      Lab 5           |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------


#include <iostream>
#include <fstream>
#include "dlinkedlist.h"
using namespace std;

//Creating a Customer object
class Customer{
private:
	string last_name;
	string first_name;
	int SSN;
	
public:
	Customer(){ //default constructor
		last_name = "";
		first_name = "";
		SSN = 0;
	}
	Customer(string ilast_name, string ifirst_name, int iSSN){
       last_name = ilast_name;
	   first_name = ifirst_name;
	   SSN = iSSN;
	}
	int getSSN() const { return SSN; }
	string getfirst_name() const { return first_name; }
	string getlast_name() const { return last_name; }
	void print_customer(){
		cout << last_name << endl;
		cout << first_name << endl;
		cout << SSN << endl;
	}
};
//Operator == overload
	bool operator==(const Customer& x, const Customer& y){
		return x.getSSN() == y.getSSN();
	}

//Input >> overload	
	istream& operator>>(istream &in, Customer &x){
		int SSN;
		string last_name, first_name;
		in >> last_name >> first_name >> SSN;
		x = Customer{last_name, first_name, SSN};
		return in;	
	}
//Output << overload
	ostream& operator<<(ostream& out, const Customer& x){
		return out << "Last name: " << x.getlast_name()
					<< "\nFirst name: " << x.getfirst_name() 
					<< "\nSSN:   " << x.getSSN();
	}
//Read a text file and input customer data into customer objects using overload
int main (){
	Customer d[10];
	int i = 0;
	ifstream read;
	read.open("customer.txt");
	while (read.good()){
		read >> d[i];
		i++;
	}
	
	for (int count = 0; count < 10; count++){
		cout << "Customer " << count+1 << endl;
		cout << d[count] << '\n' << endl;
	}
}

