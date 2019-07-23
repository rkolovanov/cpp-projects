///////////////////////////////
///   By Rodion Kolovanov   ///
///    Строки - Задания     ///
///////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <cstring>

//Дополнительные классы
#include <string> //Строка
#include <array>  //Массив
#include <vector> //Вектор

using namespace std;

enum color{red, green, blue};

typedef int kalich;

int main(){

	setlocale(LC_ALL, "Russian");

	string str = "Hello";

	cout << str << endl;
	getline(cin, str);
	cout << str << endl;

	for (int i = 0; i < str.size(); i++)
		cout << str[i] << endl;
	
	array<int, 5> arr = { 1, 2, 3, 4, 5 };

	cout << "Размер массива: " << arr.size() << endl;

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;

	vector<int> vctr;

	int i = 0;
	while (cin >> i){
		if (i == -1)
			break;
		vctr.push_back(i);
	}

	for (int i = 0; i < vctr.size(); i++)
		cout << vctr[i] << endl;

	kalich a = 1;

	cout << a << endl;

	int c;

	cout << "Введите c(0, 1, 2): ";
	cin >> c;

	color b = (color)c;

	switch (b){
		case red: cout << "Red" << endl; break;
		case green: cout << "Green" << endl; break;
		case blue: cout << "Blue" << endl; break;
		default: cout << "Error!" << endl;
	}

	_getch();
	return 0;
}