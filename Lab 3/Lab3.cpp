//------------------------------------------------------
//*  Question 1     By Han Hong      Lab 3             |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  cout << "Loop A (for version)" << endl;
  for (int i=0;i<7;i++) {
    cout << i << endl;
  }
 
// ---------------------------While Version and Do While Version PART A------------------------
  cout <<"Loop A (while version)" << endl;
  int x = 0;  
  while (x != 7) {
	cout << x << endl;
	x++;
  }
  
  cout <<"Loop A (do while loop)" << endl;
  int y = 0;
  do {
	cout << y << endl;
	y++;
  } while (y!=7);
 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  cout << "Loop B (do while version)" << endl;
  int i;
  do {
    cout << "Enter a number greater than 100" << endl;
    cin >> i;
    cout << i << endl;
  } while (i<100);
  
//-----------------------------While Version and For Version PART B-----------------------------
  cout <<"Loop B (for version)" << endl;
  int z = 0;
  for (int j = 0; z < 100;j++){
	cout <<"Enter a number greater than 100" << endl;
	cin >> z;
	cout << z << endl;
	}

  cout <<"Loop B (while version)" << endl;
int d = 0;	
  while (d<100){
	cout << "Enter a number greater than 100" << endl;
	cin >> d;
	cout << d << endl;
	}
}

