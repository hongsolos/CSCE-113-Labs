//======================================================================
//*  FILE NAME: sort.cpp       TTTTTTTTTT   A     M       M UU      UU |
//*  NAME: Han Hong                TT      A A    MM     MM UU      UU |
//*  Pre Lab                       TT     A   A   M M   M M UU      UU |
//*  CSCE 113 SECTION 501          TT    AAAAAAA  M  M M  M UU      UU |
//*  UIN: 824000237                TT   AA     AA M   M   M  UUUUUUUU  |
//======================================================================

#include "sort.h"
#include "flight.h"
#include <vector>

using namespace std;

//Selection sort =======================================================
//Reference:http://www.algolist.net/Algorithms/Sorting/Selection_sort
//Sorting time, descending order
void SelectionSort::sort(vector<Flight>& data){
	int pos_min;
	Flight temp;
	int n = data.size();
	for (int i = 0; i < n-1; i++){
	    pos_min = i;
		for (int j = i+1; j < n; j++){
			if (data[j].get_departure_time() < data[pos_min].get_departure_time())
				pos_min=j;
		}
        if (pos_min != i){
            temp = data[i];
            data[i] = data[pos_min];
            data[pos_min] = temp;
            }
	}
}

//Selection sort =======================================================
//Reference:http://www.algolist.net/Algorithms/Sorting/Bubble_sort
//Sorting time, descending order
void BubbleSort::sort(vector<Flight>& data){
    bool swapped = true;
    int j = 0;
    Flight tmp;
	int n = data.size();
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < n - j; i++) {
            if (data[i].get_departure_time() > data[i + 1].get_departure_time()) {
                tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
                swapped = true;
            }
        }
    }
}