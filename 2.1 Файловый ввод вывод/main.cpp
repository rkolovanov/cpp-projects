///////////////////////////////
///   By Rodion Kolovanov   ///
///   Файловый ВВОД/ВЫВОД   ///
///////////////////////////////

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	string str;
	int a;
	int arr[4];

	cout << "Введите строку: ";
	getline(cin, str);

	cout << "Введите число: ";
	cin >> a;

	cout << "Строка: " << str << ", число: " << a << endl;

	ofstream fout; // Можно еще так: ofstream fout("file.txt");

	fout.open("file.txt");
	fout << "Строка: " << str << ", число: " << a << endl;

	ifstream fin;

	fin.open("input.txt");

	if (!fin.is_open()){
		cout << "Error! File is not found!";
		_getch();
		return -1;
	}

	for (int i = 0; i < 4; i++){
		fin >> arr[i];
		cout << "a[" << i << "] = " << arr[i] << endl;
	}

	_getch();
	return 0;
}