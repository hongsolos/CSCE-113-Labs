//------------------------------------------------------
//*  Chapter 14 Drill     By Han Hong      Lab 8       |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------

#include <iostream>

using namespace std;

class B1 {
	public:
		virtual void vf() const { cout << "B1::vf\n";}
		void f() const { cout << "B1::f\n";}
		virtual void pvf() = 0;
};

class D1 : public B1 {
	public:
		void vf() const override {cout << "D1::vf\n";}
		void f() const { cout << "D1::f\n";}
		void pvf() override {cout << "D1::pvf\n";}
};

class D2 : public D1 {
	public:
		void pvf() override {cout << "D2::pvf\n";}
};

class B2 {
	public:
		virtual void pvf() = 0;
};

class D21 : public B2 {
	public:
		string x;
		D21 (string input){x = input;}
		void pvf() override {cout << x;}
};

class D22 : public B2 {
	public:
		int x;
		D22 (int input){x = input;}
		void pvf() override {cout << x;}
};

void f(B2& x){
	x.pvf();
}

int main(){
/* 	B1 a;
	a.vf();
	a.f();
	a.pvf(); */
	
	//Question 5: Because B1 called pure virtual function pvf, class B1 becomes abstract
	D1 b;
	b.vf();
	b.f();
	b.pvf();
	
	B1& c = b;
	c.vf();
	c.f();
	c.pvf();
	//Question 4: function f() in D1 is not suppose to override the derived function from B1
	
	D2 d;
	d.vf();
	d.f();
	d.pvf();
	
	D21 e("Han");
	D22 g(8);
	
	f(e);
	f(g);

}

