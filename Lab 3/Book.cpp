//------------------------------------------------------
//*  Question 4     By Han Hong                Lab 3   |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <limits>
#include <list>
#include <sstream>

using namespace std;
class Book 
{
  public: 
    string isbn;
	string title;
	string author;
	string copyrightdate;
	bool checkout = false; 

//Show the title of the book	
    void show_title(void){
		cout << "Title: " << title << "\n"; 
	};
//Show the author of the book		
    void show_author(void){
		cout << "Author: " << author << "\n";
	};
//Show the copy right date of the book		
	void show_copyrightdate (void){
		cout << "Copy Right Date: " << copyrightdate << "\n";
	};
//Show the ISBN of the book		
	void show_ISBN (void) {
		cout << "ISBN: " << isbn << "\n";
	};
//Show the status of the book, checked out or not.		
	void show_checkBookOut (void) {
		if (checkout == false) {
			cout << "In stock";
		} else {
			cout << "Checked Out";
		}
	}
//The function to check out/in the books	
	void checkBook (void) {
		if (checkout == false){
		checkout = true;
		} else {
		checkout = false;
		}
	}

//Declare the use of show_book
	void show_book (void);
};

//Collectively use all show functions to return the attribute of the book	
	void Book::show_book(void) { 
    show_title(); 
    show_author();
	show_copyrightdate();
	show_ISBN();
	show_checkBookOut();
	};
	
//Check if a number entered is a number
int checkValid(){
	bool inFail;
	int x;
	cin >> x;
	inFail = cin.fail();
 	while (inFail == true || (x > 9)){
		cout << "Invalid Re-enter";
		cin >> x;
		inFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
   
    return x;
}

//Print all books entered
void print (Book booklist []){
   for (int i = 0; i < 5; i++) {
	cout << "Book number " << i+1 << " :" << endl;
	booklist[i].show_book();
	cout << "\n" << endl;
	}
}

int main(void)
{
   int count,d1, d2, d3, booknum = 0, booknum2 = 0;
   string d4;
   int ind = 0;
   string cut;
   
   Book booklist [5];

//All books in the class   
   booklist[0].title = "Gone with the wind";
   booklist[0].author = "Margaret Mitchell";
   booklist[0].copyrightdate = "1936";
   booklist[0].isbn = "None";
   
   booklist[1].title = "Tuesday with Morrie";
   booklist[1].author = "Mitch Albom";
   booklist[1].copyrightdate = "1997";
   booklist[1].isbn = "None";
   
   booklist[2].title = "Frankenstein";
   booklist[2].author = "Mary Shelley and Bernie Wrightson";
   booklist[2].copyrightdate = "1818";
   booklist[2].isbn = "None";
   
   booklist[3].title = "Harry Potter and Sorcerer's Stone";
   booklist[3].author = "JK Rowling";
   booklist[3].copyrightdate = "1997";
   booklist[3].isbn = "None";
   
   booklist[4].title = "Principle of Programming and Practice C++";
   booklist[4].author = "Bjarne Stroustrup";
   booklist[4].copyrightdate = "2014";
   booklist[4].isbn = "None";
   
   cout << "Available books are: " << "\n";
   
   print(booklist);

//Prompt user to enter the ISBN for the specified books   
	cout << "ISBN are missing from these books, do you want to enter it in? Enter 1 for Yes: ";
	cin >> count;
	if (count == 1) {
		while (ind < 5){
		cout << "Which book number? Enter 100 to quit: ";
		cin >> ind;
		int actualnumber = ind - 1;
			if (ind < 5){
			cout << "Enter the ISBN: " << "\n";
			cout << "First number:" << "\n";
			d1 = checkValid();
			cout << "Second number:" << "\n";
			d2 = checkValid();
			cout << "Third number:" << "\n";
			d3 = checkValid(); 
			cout << "Fourth number:" << "\n";
			cin >> d4;
			std::stringstream stm;
			stm<<d1<<d2<<d3<<d4;
			booklist[actualnumber].isbn = stm.str();
			}
		}
	}
	
	print(booklist);

//Ask the user if they want to check out a book, and which book?	
	cout << "Do you want to check a book out/in? Enter for 1 for Yes: ";
	cin >> count;
	if (count == 1) {
		while (booknum < 5){
		cout << "Which book number? Enter 100 to quit: ";
		cin >> booknum;
		int actualnumber = booknum - 1;
			if (ind < 5){
				booklist[actualnumber].checkBook();
			}
		}
	}
	
    print(booklist);

//Comparing 2 book's ISBN	
    cout << "Do you want to compare ISBN between two books? Enter 1 for Yes ";
	cin >> count;
	if (count == 1) {
		cout << "Which book number is the first one to compare? Enter 100 to quit: ";
		cin >> booknum;
		cout << "Which book number is the second one to compare? Enter 200 to quit: ";
		cin >> booknum2;
		int actualnumber = booknum - 1;
		int actualnumber2 = booknum2 - 1;
			if (booknum < 5 && booknum2 < 5){
				if (booklist[actualnumber].isbn == booklist[actualnumber2].isbn){
					booklist[actualnumber].show_book();
					cout << "\n" << endl;
					booklist[actualnumber2].show_book();
					cout << "The two books have the same ISBN.";
				} else {
					booklist[actualnumber].show_book();
					cout << "\n" << endl;
					booklist[actualnumber2].show_book();
					cout << "The two books doesn't have the same ISBN.";
				}
			}
	}

}