///////////////////////////////
///   By Rodion Kolovanov   ///
///   �������� ����/�����   ///
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

	cout << "������� ������: ";
	getline(cin, str);

	cout << "������� �����: ";
	cin >> a;

	cout << "������: " << str << ", �����: " << a << endl;

	ofstream fout; // ����� ��� ���: ofstream fout("file.txt");

	fout.open("file.txt");
	fout << "������: " << str << ", �����: " << a << endl;

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