///////////////////////////////
///   By Rodion Kolovanov   ///
///        ���������        ///
///////////////////////////////

#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	int A = 1;

	cout << "A = " << A << endl;
	cout << "����� ���������� � (&A) = 0x" << &A << endl << endl;


	int m[5];

	cout << "������ ������������� ��������� �� 4 �����: m[5] " << endl;
	for (int i = 0; i < 5; i++){
		cout << "����� m[" << i << "] = 0x" << &(m[i]) << endl;
	}
	cout << endl;


	double n[5];
	cout << "������ ������� ��������� �� 8 ����: n[5] " << endl;
	for (int i = 0; i < 5; i++){
		cout << "����� n[" << i << "] = 0x" << &(n[i]) << endl;
	}
	cout << endl;

	int x = 15;
	int *p = &x;

	cout << "x = " << x << endl;
	cout << "&x = 0x" << &x << endl;
	cout << "p = 0x" << p << endl;
	cout << "*p = " << *p << endl;
	cout << endl;

	int z[5] = { 1, 2, 3, 4, 5 };
	int *p2 = z;

	cout << "����� ������� �������� ������� z[5] = 0x" << z << ", ��� " << p2 << endl;
	cout << "�������� ������� �������� ������� z[5]= " << *z << ", ��� " << *p2 << ", ��� " << z[0] << endl;
	cout << endl;

	cout << "����� ������� �������� ������� z[5] = 0x" << ++p2 << ", ��� " << &z[1] << endl;
	cout << "�������� ������� �������� ������� z[5]= " << *(++p2) << ", ��� " << z[1] << endl;
	cout << endl;

	int *pEnd = &z[4];

	cout << "����� ���������� �������� ������� z[5] = 0x" << pEnd << ", ��� " << &z[4] << endl;
	cout << "�������� ������� �������� ������� z[5]= " << *pEnd << ", ��� " << z[4] << endl;
	cout << endl;

	int *p3 = new int;
	*p3 = 5;

	cout << "���������� ����� ��� p3 = 0x" << p3 << endl;
	cout << "p3 = " << *p3 << endl;

	delete p3;

	_getch();
	return 0;
}