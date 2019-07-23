#include <iostream>

using namespace std;

class A {
	virtual void foo() {}
};
class B: public A {};
class C: public B {};

enum e { a = 1, b = 2, c = 3, d = 4 };

int main() {
	float a = 3;
	// e g = a; - error
	e g = static_cast<e>((int)a);

	char chr = 250; // chr = -6
	cout << (int)(char)chr;
	cout << (int)static_cast<unsigned char>(chr);

	C* pC = new C;
	B* pB = dynamic_cast<B*>(pC);

	cout << typeid(pB).name() << endl;

	A* pA = dynamic_cast<A*>(pB);

	cout << typeid(pB).name() << endl;

	C* pC2 = dynamic_cast<C*>(pA);

	cin.get();
	return 0;
}