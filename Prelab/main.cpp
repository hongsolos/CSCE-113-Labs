//======================================================================
//*  FILE NAME: main.cpp       TTTTTTTTTT   A     M       M UU      UU |
//*  NAME: Han Hong                TT      A A    MM     MM UU      UU |
//*  Pre Lab                       TT     A   A   M M   M M UU      UU |
//*  CSCE 113 SECTION 501          TT    AAAAAAA  M  M M  M UU      UU |
//*  UIN: 824000237                TT   AA     AA M   M   M  UUUUUUUU  |
//======================================================================

#include <string>
#include <iostream>
#include <vector>
#include "sort.h"
#include "flight.h"

using namespace std;

int main(){
//Create flight objects contents of vi vector to test the sort =========
	Flight a ("AA223", "LAS VEGAS", "21:15", "A3");
	Flight b("BA036", "DALLAS", "21:00", "A3");
	Flight c("AA220", "LONDON", "20:30", "B4");
	Flight d("VI303", "MEXICO", "19:00", "B4");
	Flight e("BA087", "LONDON", "17:45", "B4");
	Flight f("AA342", "PARIS", "16:00", "A7");
	Flight g("VI309", "PRAGUE", "13:20", "F2");
	Flight h("QU607", "TORONTO", "8:30", "F2");
	Flight i("AA224", "SYDNEY", "8:20", "A7");
	Flight j("AF342", "WASHINGTON", "7:45", "A3");
	
	vector <Flight> vi;
	vi.push_back(a);
	vi.push_back(b);
	vi.push_back(c);
	vi.push_back(d);
	vi.push_back(e);
	vi.push_back(f);
	vi.push_back(g);
	vi.push_back(h);
	vi.push_back(i);
	vi.push_back(j);
	
	for (int i = 0; i < vi.size(); i++){
		vi[i].display();
	}
//Selection sort ==========================================================
	cout << "Selection sort -------------" << endl;
	SelectionSort s;
	s.sort(vi);
	for (int i = 0; i < vi.size(); i++){
		vi[i].display();
	}
//Bubble sort =============================================================
	cout << "Bubble sort ----------------" << endl;
	BubbleSort z;
	z.sort(vi);
	for (int i = 0; i < vi.size(); i++){
		vi[i].display();
	}	
}
