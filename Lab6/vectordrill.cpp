//------------------------------------------------------
//*  Vector Drill        By Han Hong      Lab 6        |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

vector<int>gv {1, 2, 4,8, 16, 32, 64, 128, 256, 512};

void f(vector<int> &x){
	vector<int> lv;
	for (int i = 0; i < x.size(); i++){
		lv.push_back(x[i]);
	}
	for (int i = 0; i < lv.size(); i++){
		cout << lv[i] << endl;
	}
	vector<int> vw = x;
	for (int i = 0; i < vw.size(); i++){
		cout << vw[i] << endl;
	}
}
int main(){
	f(gv);
	vector<int>vv;
	vv.push_back(1);
	for (int i = 1; i < 10; i++){
		vv.push_back(vv[i-1]*(i+1));
	}
	f(vv);
}

