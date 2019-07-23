///////////////////////////////
///   By Rodion Kolovanov   ///
///                         ///
///////////////////////////////

#include <iostream>
#include <string>
#include <locale>
#include <conio.h>

using namespace std;

const int size = 66;
const int dive = 6;
int c = 0;

void r(unsigned int i){
	if (i == 0)
		return;

	cout << "Начало функции " << i << endl;

	r(i - 1);

	cout << "Конец функции " << i << endl;
}

void rec(char* str, int min, int max, int level){
	if (level == 0)
		return;

	int middle = (min + max) / 2;
	str[middle] = '|';

	rec(str, min, middle, level - 1);
	rec(str, middle, max, level - 1);
}

long long factorial(int n){
	long long f = 1;

	if (n < 0)
		return -1;

	if (n == 0)
		return 1;

	for (int i = 2; i <= n; i++){
		f = f * i;
	}

	return f;
}

long long rec_factorial(int n){
	if (n < 0)
		return -1;

	else if (n == 0)
		return 1;

	else return n * rec_factorial(n - 1);
}

void star(int);

int main(){
	setlocale(LC_ALL, "Russian");

	r(10);

	char str[size];
	str[size - 1] = '\0';
	int min = 0, max = size - 2;

	str[min] = '|';
	str[max] = '|';

	for (int i = 1; i < size - 2; i++)
		str[i] = ' ';

	cout << str << endl;

	for (int i = 1; i <= dive; i++){
		rec(str, min, max, i);
		cout << str << endl;
		for (int i = 1; i < size - 2; i++)
			str[i] = ' ';
	}

	cout << endl << factorial(7) << " or " << rec_factorial(7) << endl;

	int num = 0;

	cout << "Enter высота горы: ";
	cin >> num;

	c = num;
	star(num);

	return 0;
}

void star(int n){
	if (n == 0)
		return;

	for (int i = 1; i <= c - (n - 1); i++){
		cout << "/\\";
	}
	cout << endl;
	star(n - 1);
}