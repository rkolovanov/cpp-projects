///////////////////////////////
///   By Rodion Kolovanov   ///
///         ������          ///
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
	cin.get(); //��������� Enter � ������

	cout << "Enter str3(using cin.getline();): ";
	cin.getline(str3, 80);

	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3; */

	char info[80];
	char info2[80] = "���� ���: ";
	int lenght = 0;
	bool equal;

	cout << "������� ����� ������: ";
	cin.getline(info, 80);
	cout << endl;

	for (int i = 0; i < 80; i++){
		if(info[i] != '\0')
			lenght++;
		else break;
	}

	cout << "������ ������1: " << info << endl;
	cout << "������ ������1 �������� " << sizeof(info) << " bytes" << endl;
	cout << "� ������ ������1 " << lenght << " ��������" << endl;
	cout << "� ������ ������1 ����� " << strlen(info) << " ��������" << endl << endl;

	cout << "�������� ������1 � ������2..." << endl;
	strncpy(info2, info, 80);

	cout << "������2 = " << info2 << endl << endl;

	cout << "������� � ������2 ������1..." << endl;
	strcat(info2, info);

	cout << "������2 = " << info2 << endl << endl;

	cout << "������� ��� ������...(������1 = " << info << ", ������2 = " << info2 << ")" << endl;

	if (!strcmp(info, info2))
		cout << "��� �����!" << endl;
	else
		cout << "��� �� �����!" << endl;;

	_getch();
	return 0;
}