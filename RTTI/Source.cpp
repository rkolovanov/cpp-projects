#include <iostream>

using namespace std;

struct Base { virtual ~Base() {} };
struct A: Base {};

int main() {
	A a;
	Base& ref = a;
	Base* ptr = &a;

	cout << typeid(a).name() << endl;
	cout << typeid(ref).name() << endl;
	cout << typeid(ptr).name() << endl;
	cout << typeid(*ptr).name() << endl;
	cout << typeid(Base).name() << endl;
	cout << typeid(A).name() << endl;

	cout << (typeid(A) == typeid(ref)) << endl;

	cin.get();
	return 0;
}