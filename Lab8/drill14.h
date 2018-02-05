#include <iostream>

using namespace std;

class B1 {
	public:
		virtual void vf() const { cout << "B1::vf";}
		void f() const { cout << "B1::f";}
}

class D1 : B1 {
	void vf() const override {cout << "D1::vf";}
	void f() const {cout << "D1::f";};
}

int main(){
	B1 a;
	a.vf();
	a.f();
	
	D1 b;
	b.vf();
	b.f();
	
	B1& c = b;
	c.vf();
	c.f();
	
	
}