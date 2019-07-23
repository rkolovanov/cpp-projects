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

	int N;
	string FileName;
	bool SaveOrRead; //0 - save, 1 - read

	ofstream fout;
	ifstream fin;
	
	cout << "0 - ��������� � ����, 1 - ������� �� �����\n";
	cout << "�������� ��������: ";
	cin >> SaveOrRead;

	switch(SaveOrRead){
		case false: 
					system("cls");
					cin.get();
					cout << "������� ��� ����� ��� ������: ";
					getline(cin, FileName);

					FileName += ".txt";
					fout.open(FileName);

					while (cin >> N)
						fout << N << endl;

					break;

		case true: 
					system("cls");
					cin.get();
					cout << "������� ��� ����� ��� ������: ";
					getline(cin, FileName);

					FileName += ".txt";
					fin.open(FileName);

					if (!fin.is_open()){
						cout << "Error! File is not found!";
						_getch();
						return -1;
					}
					int a[5];

					for (int i = 0; i < 5; i++){
						fin >> a[i];
						cout << "a[" << i << "] = " << a[i] << endl;
					}

					break;
	}

	_getch();
	return 0;
}