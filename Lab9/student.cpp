//------------------------------------------------------
//*  Student with vector    By Han Hong      Lab 9     |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <string>

using namespace std;

struct Student {
	private:
		string last_name; 
		int UIN; 
		double GPA;
	public:
		Student(){
			last_name = "";
			UIN = 0;
			GPA = 0.0;
	}
		Student(string inputname, int inputUIN, double inputGPA){
			last_name = inputname;
			UIN = inputUIN;
			GPA = inputGPA;
		}
		
		string getlastname() const {return last_name;}
		int getUIN() const {return UIN;}
		double getGPA() const {return GPA;}
//Input overload ------------------------------------------------------
		friend istream& operator>>(istream &in, Student &x){
			int UIN;
			double GPA;
			string last_name;
			in >> last_name >> UIN >> GPA;
			x = Student{last_name, UIN, GPA};
			return in;	
		}
//Output overload	
		friend inline ostream& operator<<(ostream& out, Student& x){
			return out << "Last name: " << x.getlastname()
					<< "\nUIN: " << x.getUIN() 
					<< "\nGPA:   " << setprecision(3) << x.getGPA();
		}
};

//Sorting -------------------------------------------------------------
struct sorter {
	string what;
	sorter (string input){
		what = input;
	}
	bool operator() (const Student& x, const Student& y){
		if (what == "UIN")
			return x.getUIN() < y.getUIN();
		if (what == "Name")
			return x.getlastname() < y.getlastname();	
	}
};

//UIN Searcher --------------------------------------------------------
    Student binary_search(vector <Student> &x, int target){
		int low = 0;
	    int hi = x.size();
		int mid = 0;
		while (low <= hi){
			mid = low + (hi-low)/2;
			if (x[mid].getUIN() == target)
				return x[mid];           
			else if (x[mid].getUIN() < target)
				low = mid+1;
			else
				hi = mid-1;
		}
		throw std::runtime_error("Not found");
	}
//GPA SEARCH -----------------------------------------------------------	
	void gpasearch (vector <Student> &vi, double target){
		for (int i = 0; i < vi.size(); i++){
			if (vi[i].getGPA() == target){
				cout << "GPA search result: " << endl;
				cout << vi[i] << '\n' << endl;
			}
		}
	}
//REMOVER --------------------------------------------------------------
	void remove (vector <Student> &x, string name){
		for (int i = 0; i < x.size(); i++){
			if (x[i].getlastname().compare(name) == 0){
				cout << "Removed : \n" << x[i];
				x.erase(x.begin() + i);
				i = 0;
			}
		}
	}
//Printing --------------------------------------------------------------	
	void print (vector <Student> &vi){
		for (int i = 0; i < vi.size(); i++){
			cout << "Student " << i+1 << endl;
			cout << vi[i] << '\n' << endl;
		}
	}
//MAIN METHOD ----------------------------------------------------------
int main (){
	vector <Student> vi;
	Student temp;

//Read student object into vector----------------------------------------
	ifstream read;
	read.open("students.txt"); //Text file name
	while (read.good()){
		read >> temp;
		vi.push_back(temp);
	}
//PART A SORTING BY NAME-------------------------------------------------
	std::sort(vi.begin(), vi.end(), sorter("Name") );
	print(vi);
//PART B SORTING BY UIN--------------------------------------------------
	std::sort(vi.begin(), vi.end(), sorter("UIN") );
	print(vi);
//PART C FIND STUDENT BY UIN---------------------------------------------
	try { 
		Student found = binary_search(vi, 824000237); //The UIN to be searched
		cout << "Founded: " << endl;
		cout << found << '\n' << endl;
	}
	catch(const std::exception& e) {
       std::cout << "Search result: " << e.what() << '\n'<< endl;;
   }
//PART D FIND ALL STUDENT WITH GIVEN GPA----------------------------------
	gpasearch(vi, 3.3);
//PART E INSERT A STUDENT
	Student extra("Smith", 204394130, 3.4);
	vi.push_back(extra);
//PART F REMOVE A STUDENT RECORD BY LAST NAME-----------------------------
	remove(vi, "Hong");
}