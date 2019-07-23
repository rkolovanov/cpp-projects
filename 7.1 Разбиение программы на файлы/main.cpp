#include <iostream>
#include <conio.h>
#include "kalich.h"

using namespace std;

extern int a;

int main(){
	setlocale(LC_ALL, "Russian");

	kalich();

	cout << a << endl;

	_getch();
	return 0;
}