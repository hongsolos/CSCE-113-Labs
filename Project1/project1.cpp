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

class Student {
	private:
		string last_name; 
		string first_name;
		int ID;
	public:
		Student(){
			last_name = "";
			first_name = "";
			ID = 0;
		}
		Student(string inputlastname, string inputfirstname, int inputid){
			last_name = inputlastname;
			first_name = inputfirstname;
			ID = inputid;
		}
		void display() const { cout << first_name << " " << last_name << "  " << ID;}
};

class Menu {
	public:
/* 		GroupOfStudents x;
		Student y; */
		
		void displayMenu (){
			cout << "Welcome :" << endl;
			cout << "  [1] Provide the name of input file." << endl;
			cout << "  [2] Display a student's score and grades." << endl;
			cout << "  [3] Student with the highest score." << endl;
			cout << "  [4] Display all students in alphabetical order." << endl;
			cout << "  [5] Exit program." << endl;
		}
		
		void inputData (string filename) {
			StudentCourses temp;
			ifstream read;
			read.open("students.txt");
			while (read.good()){
				read >> temp;
				vi.push_back(temp);
			}
		}
		
		void option (int input){
			switch ( input ) {
			case 1:{
				string name;
				cout << "Enter file name: ";
				cin >> name;
				break;
			}
			case 2:{
				cout << "Option 2 selected.";
				//Student.display();
				break;
			}
			case 3:{
				cout << "Option 3 selected.";
				//GroupOfStudents.display_highest();
				break;
			}
			case 4:{
				cout << "Option 4 selected.";
				//GroupOfStudents.display_sorted();
				break;
			}
			case 5:{
				cout << "Exiting the program \n";
				break;
			}
			default:{
				cout<<"Error, bad input, quitting\n";
				break;
			}
			}
		}
		friend istream& operator>>(istream &in, StudentCourses &x){
			string last_name;
			string first_name;
			int ID;
			int quizz1, quizz2, quizz3, quizz4, quizz5, quizz6, quizz7, quizz8, quizz9, quizz10;
			int homework1, homework2, homework3, homework4, homework5, homework6;
			int test1, test2, test3, test4;
			in.getline(last_name, first_name, ID,'\n');
			
			in.getline(quizz1, quizz2, quizz3, quizz4, quizz5, quizz6, quizz7, quizz8, quizz9, quizz10,'\n');
			int quiz [10] = {quizz1, quizz2, quizz3, quizz4, quizz5, quizz6, quizz7, quizz8, quizz9, quizz10};
			
			in.getline(homework1, homework2, homework3, homework4, homework5, homework6,'\n');
			int homework [6] = {homework1, homework2, homework3, homework4, homework5, homework6};
			
			in.getline(test1, test2, test3, test4,'\n');
			int test [4] = {test1, test2, test3, test4};
			
			x = (Student{last_name, first_name, ID},Courses (quiz, homework, test));
			
			return in;	
		}
//Output overload	
/* 		friend inline ostream& operator<<(ostream& out, Student& x){
			return out << "Last name: " << x.getlastname()
					<< "\nUIN: " << x.getUIN() 
					<< "\nGPA:   " << setprecision(3) << x.getGPA();
		}
};
 */

class Courses{
	private:
		int quizzes [10];
		int homeworks [6];
		int tests [4];
		double final_score;
		char letter_grade;
	public:
		void setquizzes(int quiz []){ std::copy(quiz, quiz + 10, quizzes);}
		void sethomeworks(int homework []){ std::copy(homework, homework + 10, homeworks);}
		void settests(int test []){ std::copy(test, test + 10, tests);}
		
		void calc_final_score()
		void calc_letter_grade()
		void display()
};

class StudentCourses{
	private:
		Student student;
		Courses courses;
	public:
		StudentCourses (string lastname, string firstname, string ID, int quiz [], int homework [], int test []){
			courses.setquizzes(quiz);
			courses.sethomeworks(homework);
			courses.settest(test);
			student.setfirstname(firstname);
			student.setlastname(lastname);
			student.setID(ID);
		}
		int get_final_score()
		void display();
};

class GroupOfStudents{
	private:
		vector <StudentCourses> stvec
	public:
		void display()
		void display_sorted()
		void display_highest()

}