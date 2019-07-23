// Complex Numbers class by Rodion Kolovanov

#include <iostream>
#include <conio.h>
#include "ComplexNumber.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	ComplexNumber cn1(1, 4);
	ComplexNumber cn2(9, 6);
	ComplexNumber cn3 = cn1 + cn2;

	cout << cn3 << endl;
	cn3 = cn1 - cn2;
	cout << cn3 << endl;
	cn3 = cn1 * cn2;
	cout << cn3 << endl;
	cn3 = cn1 / cn2;
	cout << cn3 << endl;

	_getch();
	return 0;
}