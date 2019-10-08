#include <iostream>
using namespace std;

void func1() {
	cout << "Func1!" << endl;
}

void func2() {
	cout << "Func2!" << endl;
}

void call(void(*f)()) {
	f();
}

int main() {
	call(func1);
	call(func2);

	cin.get();
	return 0;
}