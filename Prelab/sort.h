//======================================================================
//*  FILE NAME: sort.h         TTTTTTTTTT   A     M       M UU      UU |
//*  NAME: Han Hong                TT      A A    MM     MM UU      UU |
//*  Pre Lab                       TT     A   A   M M   M M UU      UU |
//*  CSCE 113 SECTION 501          TT    AAAAAAA  M  M M  M UU      UU |
//*  UIN: 824000237                TT   AA     AA M   M   M  UUUUUUUU  |
//======================================================================

#ifndef SORT_H_
#define SORT_H_

#include "flight.h"
#include <vector>

using namespace std;

class Sort {
protected:
   unsigned long num_cmps; // number of comparisons performed in sort function
public:
   virtual void sort(vector<Flight>& data) = 0;    // main entry point
   bool testIfSorted(const vector<Flight>& data);        // returns false if not sorted
                                                // true otherwise
   unsigned long getNumCmps() { return num_cmps; }        // returns # of comparisons
   void resetNumCmps() { num_cmps = 0; }
};

class SelectionSort:public Sort {	// SelectionSort class
public:
  void sort(vector<Flight>& data);		// main entry point
};

class BubbleSort:public Sort {		// BubbleSort class
public:
  void sort(vector<Flight>& data);		// main entry point
};

#endif //SORT_H_

