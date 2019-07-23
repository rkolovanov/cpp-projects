///////////////////////////////
///   By Rodion Kolovanov   ///
///         Строки          ///
///////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	/*char str[] = "ujgfijidsjiojvfdiojsdfiojvisfsv fijgjdf";
	char str2[80];
	char str3[80];

	cout << "str = " << str << endl;

	cout << "Enter str2(using cin): ";
	cin >> str2;
	cin.get(); //Обработка Enter в потоке

	cout << "Enter str3(using cin.getline();): ";
	cin.getline(str3, 80);

	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3; */

	char info[80];
	char info2[80] = "Твое имя: ";
	int lenght = 0;
	bool equal;

	cout << "Введите любую строку: ";
	cin.getline(info, 80);
	cout << endl;

	for (int i = 0; i < 80; i++){
		if(info[i] != '\0')
			lenght++;
		else break;
	}

	cout << "Данная строка1: " << info << endl;
	cout << "Данная строка1 занимает " << sizeof(info) << " bytes" << endl;
	cout << "В данной строке1 " << lenght << " символов" << endl;
	cout << "В данной строке1 точно " << strlen(info) << " символов" << endl << endl;

	cout << "Копируем строку1 в строку2..." << endl;
	strncpy(info2, info, 80);

	cout << "Строка2 = " << info2 << endl << endl;

	cout << "Добавим в строку2 строку1..." << endl;
	strcat(info2, info);

	cout << "Строка2 = " << info2 << endl << endl;

	cout << "Сравним эти строки...(Строка1 = " << info << ", Строка2 = " << info2 << ")" << endl;

	if (!strcmp(info, info2))
		cout << "Они равны!" << endl;
	else
		cout << "Они не равны!" << endl;;

	_getch();
	return 0;
}