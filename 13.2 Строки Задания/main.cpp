///////////////////////////////
///   By Rodion Kolovanov   ///
///    Строки - Задания     ///
///////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	char str[80];
	char str_rev[80];
	char wordsa[80];
	int j = 0;
	int words = 0;
	int l;
	bool a = false;

	cout << "Введите строку: ";
	cin.getline(str, 80);

	l = strlen(str);

	for (int i = 0; i < l; i++){
		str_rev[i] = str[(l - 1) - i];
	}

	str_rev[l] = '\0';


	cout << "Перевернем строку: " << str_rev << endl;

	for (int i = 0; i < 20; i++){
		if (str[i] != '\0' && str[i] != ' '){
			if (a == false)
				words++;

			a = true;
		}

		if (str[i] == ' ' && a == true)
			a = false;
	}

	cout << "Кол-во слов в строке: " << words;


	_getch();
	return 0;
}