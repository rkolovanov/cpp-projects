#include <iostream>
#include <conio.h>
#include <typeinfo>

using namespace std;

class A {
public:
	virtual void Print() { cout << "Print A"; }
	void A1() { cout << "A"; }
};

class B : public A {
	virtual void Print() { cout << "Print B"; }
	virtual void B1() { cout << "B"; }
};

class C : public B {
	virtual void Print() { cout << "Print C"; }
	virtual void B1() { cout << "C"; }
};

int main() {
	
	A* a;
	B* b;
	C* c;

	a = new C;
	b = dynamic_cast<C*>(a);

	b->A1();

	return 0;
}