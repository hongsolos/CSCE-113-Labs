//============================================================================
// File Name   : pa1main.cpp 
// Author      : Han Hong and Kyle Koiner
// Version     : 1.0
// Copyright   : Not applicable
// Description : C++ project 1 for CSCE 113
//============================================================================

#include "Menu.h"
#include <iostream>

using namespace std;

int main() {
   Menu m;
   int option;
   m.display_menu();
   do {
      cout << "> ";
      while (!(cin >> option) || option < 1 || option > Menu::EXIT) {
         if (cin.fail()) {    // we found something that wasn’t an integer 
            cin.clear();      // we’d like to look at the characters
            char ch;
            while (cin>>ch && !isdigit(ch)) {
               cerr << ch <<" was an invalid input; please try again" << endl;
               cout << "> ";
            }
            cin.unget();
         } else {  // option < 1 || option > Menu::EXIT
		    cout << "> ";
            cerr << "Invalid input; please try again" << endl;
            cout << "> ";
         }
      } 
			
      switch(option) { 
      case Menu::INFO:
         m.display_info();
         break;
      case Menu::READ_FILE:
         try {
            m.read_students();
         } catch (const Menu::InvalidFile& excp) {
            cerr << excp.what() << endl;
         } catch (const Menu::InvalidData& excp) {
            cerr << excp.what() << endl;
         }
         break;
      case Menu::DISPLAY:
         m.display_students();
         break;
      case Menu::DISPLAY_SORTED:
         m.display_students_sorted();
         break;   
      case Menu::HIGHEST:
         m.display_highest_score();
         break;
      }
      m.display_menu();
   } while (option != Menu::EXIT);
   return 0;
}
