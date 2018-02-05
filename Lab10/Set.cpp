//======================================================================
//*  FILE NAME: Set.cpp        TTTTTTTTTT   A     M       M UU      UU |
//*  NAME: Han Hong                TT      A A    MM     MM UU      UU |
//*  Lab 10                        TT     A   A   M M   M M UU      UU |
//*  CSCE 113 SECTION 501          TT    AAAAAAA  M  M M  M UU      UU |
//*  UIN: 824000237                TT   AA     AA M   M   M  UUUUUUUU  |
//======================================================================

#include <iostream>
#include <list>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <set>

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
		
		string get_last_name() const {return last_name;}
		int get_UIN() const {return UIN;}
		double get_GPA() const {return GPA;}
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
			return out << "Last name: " << x.get_last_name()
					<< "\nUIN: " << x.get_UIN() 
					<< "\nGPA:   " << setprecision(3) << x.get_GPA();
		}
};

struct classcomp {
	bool operator() (const Student& x, const Student& y) const{
		return x.get_UIN() < y.get_UIN();
	}
};

//UIN Searcher --------------------------------------------------------
Student binary_search(set <Student, classcomp> &x, int target){
	set<Student>::iterator it = x.begin();
	int low = 0;
	int hi = x.size();
	int mid = 0;
	while (low <= hi){
		mid = low + (hi-low)/2;
		advance(it, mid);
		if (it->get_UIN() == target)
			return *it;           
		else if (it->get_UIN() < target){
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

//GPA SEARCH -----------------------------------------------------------	
void gpasearch (set <Student, classcomp> &vi, double target){
	set<Student>::iterator it;
	for (it = vi.begin();it != vi.end();it++){
		if (it->get_GPA() == target){
			Student temp = *it;
			cout << "GPA search result: " << endl;
			cout << temp << '\n' << endl;
		}
	}
}

//REMOVER --------------------------------------------------------------
void remove (set <Student, classcomp> &x, string name){
	set <Student>::iterator it;
	for(it = x.begin(); it != x.end(); ++it){
		Student temp = *it;
		if (temp.get_last_name().compare(name) == 0){
			cout << "Removed : \n" << temp;
			x.erase(it);
			it = x.begin();
		}
	}
}

//Printing --------------------------------------------------------------	
void print(set<Student, classcomp> &vi){
	set<Student>::iterator i;
	int count = 0;
	cout << "----------- Start of List -----------" << endl;
	for(i = vi.begin(); i != vi.end(); ++i){
		count++;
		cout << "Student " << count << endl;
		Student temp = *i;
		cout << temp << endl;
	}
	cout << "----------- End of List -------------" <<'\n' << endl;
}

//MAIN METHOD ----------------------------------------------------------
int main (){
	vector <Student> vi;
	Student temp;
	set <Student, classcomp> h;
	set<Student>::iterator eit;

//Read student object into vector----------------------------------------
	ifstream read;
	read.open("students.txt"); //Text file name
	while (read.good()){
		read >> temp;
		vi.push_back(temp);
	}
	for (int i = 0; i < vi.size(); i++)
		h.insert(vi[i]);
	print (h);
	
//PART C FIND STUDENT BY UIN---------------------------------------------
	try { 
		Student found = binary_search(h,824000237); //The UIN to be searched
		cout << "UIN Founded: " << endl;
		cout << found << '\n' << endl;
	}
	catch(const std::exception& e) {
       std::cout << "\nUIN Search result: " << e.what() << '\n'<< endl;;
   }
   
//PART D FIND ALL STUDENT WITH GIVEN GPA----------------------------------
	gpasearch(h, 3.3);
	
//PART E INSERT ---------------------------------------------------------
	Student extra("Smith", 204394130, 3.4);
	cout << "Inserted: " << endl;
	cout << extra << '\n' << endl;
	h.insert(extra);
	
//PART F REMOVE A STUDENT RECORD BY LAST NAME-----------------------------
	remove(h, "Hong");
}