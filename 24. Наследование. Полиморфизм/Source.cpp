#include <iostream>
#include <conio.h>

using namespace std;

class A {
public:
	virtual void print() { cout << "A"; }
};

class B: public A {
public:
	virtual void print() { cout << "B"; }
};

int main() {
	setlocale(LC_ALL, "Russian");

	A a;
	B b;

	A* *p = new A*[2];
	p[0] = &a;
	p[1] = &b;

	for (int i = 0; i < 2; i++)
		p[i]->print();

	_getch();
	return 0;
}