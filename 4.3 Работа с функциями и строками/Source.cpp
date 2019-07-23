///////////////////////////////
///   By Rodion Kolovanov   ///
///                         ///
///////////////////////////////

#include <iostream>
#include <conio.h>
#include <string>
#include <cmath>
#include <stdio.h>

using namespace std;

int to_binary_sys(int);

int main(){
	setlocale(LC_ALL, "Russian");

	int a;

	cout << "Enter a number: ";
	cin >> a;

	cout << a << " in dec = " << to_binary_sys(a) << " in binary";


	_getch();
	return 0;
}

int to_binary_sys(int a){
	unsigned int b = 0;
	int i = 1;

	while(a != 0){
		b = b + ((a % 2) * i);
		a = a / 2;
		i = i * 10;
	}

	return b;
}