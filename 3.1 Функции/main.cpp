///////////////////////////////
///   By Rodion Kolovanov   ///
///         Функции         ///
///////////////////////////////

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

void hello2();

void hello(){
	cout << "Hello!" << endl;
} 

int number(){
	return 100;
}

int pluss(int a){
	return a + 1;
}

int pow(int a, int b){
	int c;
	c = a;
	for (int i = 2; i <= b; i++){
		c = c * a;
	}
	return c;
}

int factorial(int a){
	int b = 1;
	for (int i = 1; i <= a; i++)
		b = b * i;
	return b;
}

double Swap(int a, int b){
	if (a > b)
		return a;
	else
		return b;
}

int main(){
	setlocale(LC_ALL, "Russian");

	hello();
	hello();
	hello2();
	hello2();

	cout << number() << endl;
	cout << pluss(number());


	int c, d;

	cout << endl << "Enter number: ";
	cin >> c;
	cout << "Enter степень: ";
	cin >> d;
	cout << "pow = " << pow(c, d) << endl;
	cout << "swap = " << Swap(c, d) << endl;
	cout << "factorial = " << factorial(c);

	_getch();
	return 0;
}


void hello2(){
	cout << "How are you?" << endl;
}