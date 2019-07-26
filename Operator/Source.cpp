#include <iostream>

using namespace std;

struct A {
	struct B {
		int n;
		B(int a) { n = a; }
		int operator[](int a) {
			return a + n;
		}
	};
	B operator[](int a) {
		return B(a);
	}
};

int main() {
	A a;

	cout << a[2][2];

	cin.get();
	return 0;
}