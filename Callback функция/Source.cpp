#include <iostream>

using namespace std;

void doSmthAndRunFunc(int a, int b, void(*function)()) {
	cout << "A + B = " << a + b << endl;
	function();
}

void sayHello() {
	cout << "Hello!" << endl;
}

void sayBye() {
	cout << "Bye!" << endl;
}

int main() {
	doSmthAndRunFunc(4, 4, sayHello);
	doSmthAndRunFunc(5, 5, sayBye);

	cin.get();
	return 0;
}