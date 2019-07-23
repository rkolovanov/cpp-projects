///////////////////////////////
///   By Rodion Kolovanov   ///
///                         ///
///////////////////////////////

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

#define N(x) x*x

inline int sum(int a, int b){
	return a + b;
}

void f(int a){
	cout << "1" << endl;
}

void f(double a){
	cout << "2" << endl;
}

void f(char a){
	cout << "3" << endl;
}

void f(string a){
	cout << "4" << endl;
}

int main(){
	setlocale(LC_ALL, "Russian");

	cout << N(5) << endl;
	cout << N(6 + 1) << endl; // 6 + 1 * 6 + 1 = 6 + 6 + 1 = 13!

	cout << sum(2, 78) << endl;

	f(5);
	f(5.2);
	f('c');
	f("lol");

	_getch();
	return 0;
}