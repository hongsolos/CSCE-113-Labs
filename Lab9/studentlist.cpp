//------------------------------------------------------
//*  Student with list    By Han Hong      Lab 9       |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------

#include <iostream>
#include <list>
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
//Input overload
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
	bool compareName(const Student &x, const Student &y){
		return x.getlastname() < y.getlastname();
	}

	bool compareUIN(const Student &x, const Student &y){
		return x.getUIN() < y.getUIN();
	}
//UIN Searcher --------------------------------------------------------
    Student binary_search(list <Student> &x, int target){
		list<Student>::iterator it = x.begin();
		int low = 0;
	    int hi = x.size();
		int mid = 0;
		while (low <= hi){
			mid = low + (hi-low)/2;
			advance(it, mid);
			if (it->getUIN() == target)
				return *it;           
			else if (it->getUIN() < target){
				it = x.begin();
				low = mid+1;
				}
			else {
				hi = mid-1;
				it = x.begin();
			}
		}
		throw std::runtime_error("Not found");
	}
//REMOVER --------------------------------------------------------------
	void remove (list <Student> &x, string name){
		list<Student>::iterator it;
		for(it = x.begin(); it != x.end(); ++it){
			Student temp = *it;
			if (temp.getlastname().compare(name) == 0){
				cout << "Removed : \n" << temp;
				x.erase(it);
				it = x.begin();
			}
		}
	}
//GPA SEARCHER ---------------------------------------------------------
	void gpasearch (list <Student> &vi, double target){
		list<Student>::iterator i;
		for( i = vi.begin(); i != vi.end(); ++i){
			Student temp = *i;
			if (temp.getGPA() == target){
				cout << "GPA search result: " << endl;
				cout << temp << '\n' << endl;
			}
		}
	}
//Printing -------------------------------------------------------------
	void print(list<Student> &vi){
		list<Student>::iterator i;
		for( i = vi.begin(); i != vi.end(); ++i){
			cout << *i << endl;
		}
	}
//MAIN METHOD ----------------------------------------------------------
int main (){
	list <Student> vi;
	Student temp;

//Read student object into vector----------------------------------------
	ifstream read;
	read.open("students.txt"); //Text file name
	while (read.good()){
		read >> temp;
		vi.push_back(temp);
	}
//PART A SORTING BY NAME-------------------------------------------------
	cout << "Sorted by name: " << endl;
	vi.sort(compareName);
	print(vi);
//PART B SORTING BY UIN--------------------------------------------------
	cout << "\nSorted by UIN: " << endl;
	vi.sort(compareUIN);
	print(vi);
//PART C FIND STUDENT BY UIN---------------------------------------------
	try { 
		Student found = binary_search(vi,824000237); //The UIN to be searched
		cout << "\nUIN Founded: " << endl;
		cout << found << '\n' << endl;
	}
	catch(const std::exception& e) {
       std::cout << "\nUIN Search result: " << e.what() << '\n'<< endl;;
   }
//PART D FIND ALL STUDENT WITH GIVEN GPA----------------------------------
	gpasearch(vi, 3.3);
//PART E INSERT ---------------------------------------------------------
	Student extra("Smith", 204394130, 3.4);
	vi.push_back(extra);
//PART F REMOVE A STUDENT RECORD BY LAST NAME-----------------------------
	remove(vi, "Hong");
}