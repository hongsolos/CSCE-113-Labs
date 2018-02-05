//------------------------------------------------------
//*  Array Drill        By Han Hong      Lab 6         |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------

#include <iostream>

using namespace std;

int ga[10] = {1,2,4,8,16,32,64,128,256,512};
void f(int x[], int y){
	int la[10];
	for (int i = 0; i < 10; i++)
		la[i] = ga[i];
	for (int i = 0; i < 10; i++)
		cout << la[i] << endl;
	int *p = new int [10];
	for (int i = 0; i < 10; i++)
		p[i] = x[i];
	for (int i = 0; i < 10; i++)
		cout << p[i] << endl;
	delete []p;
}

int main (){
	f(ga, 10);
	int aa[10];
	for (int i = 1; i < 11; i++){
		aa[0] = 1;
		aa[i] = aa[i-1]*(i+1);
	}
	f(aa, 10);
}
