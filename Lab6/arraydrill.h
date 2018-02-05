#include <iostream>

int ga[10] = {1,2,4,8,16,32,64,128,256,512};
void f(int []x, int y){
	int la[10];
	for (int i = 0; i < 10; i++)
		la[i] = ga[i];
	for (int i = 0; i < 10; i++)
		cout << la[i];
	int *p = new int [10];
	for (int i = 0; i < 10; i++)
		p[i] = la[i];
	for (int i = 0; i < 10; i++)
		cout << p[i];
	delete p[];
}
