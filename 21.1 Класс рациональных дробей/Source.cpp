// Fraction class by Rodion Kolovanov

#include <iostream>
#include <conio.h>
#include "fraction.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	fraction f1(15, 6);
	fraction f2(25, 4);
	fraction f3 = f1 + f2;

	cout << "ִנמבü f1 + f2 = " << f3 << endl;
	f3 = f1 - f2;
	cout << "ִנמבü f1 - f2 = " << f3 << endl;
	f3 = f1 * f2;
	cout << "ִנמבü f1 * f2 = " << f3 << endl;
	f3 = f1 / f2;
	cout << "ִנמבü f1 / f2 = " << f3 << endl;

	f3 = (f1 * f1) - (f2 / f1 * f1 * f2);
	cout << "ִנמבü f3 = " << f3 << endl;

	_getch();
	return 0;
}