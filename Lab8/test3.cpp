#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdexcept>
using namespace std;

void sortIn(int x[]){
	int pos_min;
	int n = 100;
	int temp;
	for (int i = 0; i < n-1; i++){
	    pos_min = i;
		for (int j = i+1; j < n; j++){
			if (x[j] < x[pos_min])
				pos_min=j;
		}
        if (pos_min != i){
            temp = x[i];
            x[i] = x[pos_min];
            x[pos_min] = temp;
		}
	}
}

void sortDe(int x[]){
	int pos_min;
	int n = 100;
	int temp;
	for (int i = 0; i < n-1; i++){
	    pos_min = i;
		for (int j = i+1; j < n; j++){
			if (x[j] > x[pos_min])
				pos_min=j;
		}
        if (pos_min != i){
            temp = x[i];
            x[i] = x[pos_min];
            x[pos_min] = temp;
		}
	}
}

int binary_search(int x[], int target){
		int low = 0;
	    int hi = x.size();
		int mid = 0;
		while (low <= hi){
			mid = low + (hi-low)/2;
			if (x[mid] == target)
				return x[mid];           
			else if (x[mid].getUIN() < target)
				low = mid+1;
			else
				hi = mid-1;
		}
		throw std::runtime_error("Not found");
	}
// Populate an array of size 100 with integers >=0 and <=1000


int main()
{
	int num, n, prime_num, size = 100;
	int time[size];
	vector <int> holding;
	for (int count = 0; count <= size; count++){
		time [count] = rand() %1000;
	}
	
	sortIn (time);
	cout << binary_search(time, 867);
}