#include  <iostream>

using namespace std;

string cat_dot(const string& s1, const string& s2){
	string s3 = s1 + "." + s2;
	cout << s3;
	return s3;
}

int main (){
	cat_dot("Han", "Hong");
}
	
