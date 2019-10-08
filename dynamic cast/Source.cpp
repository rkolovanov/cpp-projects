#include <iostream>

using namespace std;

class A {
	virtual void foo() {}
};
class B: public A {};
class C: public B {};

enum e { a = 1, b = 2, c = 3, d = 4 };

//void hfdgdf();

int main() {


	char chr = 250; // chr = -6
	cout << (int)(char)chr;
	cout << (int)static_cast<unsigned char>(chr);

	C* pC = new C;
	B* pB = dynamic_cast<B*>(pC);

	cout << typeid(pB).name() << endl;

	A* pA = dynamic_cast<A*>(pB);

	cout << typeid(pB).name() << endl;

	C* pC2 = dynamic_cast<C*>(pA);

	double a = 4.5;
	cout << endl << "Constcast: " << a << " -> ";
	const double& b = a;
	double& c = const_cast<double&>(b);
	c = 5.5;
	cout << c << endl;
	//hfdgdf();

	cin.get();
	return 0;
}

/*void hfdgdf() {
	int a = 27;
	int const b = 412;
	int * pa = &a;
	int const c = a;
	int d = b;
	int const * p1 = pa;
	int * const * p2 = &pa;
	int const ** p3 = &pa;
	int const * const * p4 = &pa;
}*/