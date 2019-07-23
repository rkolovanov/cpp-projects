#include <iostream>
#include <conio.h>
#include <fstream>
#include "time.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	time t1;
	time t2(4235234235);
	time t3(18, 34, 43);
	time t4(432, 432, 54);

	t1 = t2 + t3;

	cout << t2 << " + " << t3 << " = " << t1;
	cout << endl << "Время t4: " << t4;

	Vector v1(3, 4, Decart);
	cout << +v1;
	cout << endl << v1;

	_getch();
	return 0;
}