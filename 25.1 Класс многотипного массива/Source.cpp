#include <iostream>
#include <conio.h>
#include "MultipotentArray.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	MultipotentArray<int> arr1;

	try {
		arr1.addElement(4);
		arr1.addElement(32);
		arr1.addElement(4322);
		arr1.addElement(435);
		arr1.addElement(543);
		arr1.addElement('c');
	}
	catch (const char* str) {
		cout << str << endl;
	}

	for (int i = 1; i <= arr1.getSize(); i++)
		cout << "Array[" << i - 1 << "] = " << arr1[i - 1] << endl;

	_getch();
	return 0;
}