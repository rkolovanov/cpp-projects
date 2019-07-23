///////////////////////////////
///   By Rodion Kolovanov   ///
///        Указатели        ///
///////////////////////////////

#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	int A = 1;

	cout << "A = " << A << endl;
	cout << "Адрес переменной А (&A) = 0x" << &A << endl << endl;


	int m[5];

	cout << "Массив целочисленных элементов по 4 байта: m[5] " << endl;
	for (int i = 0; i < 5; i++){
		cout << "Адрес m[" << i << "] = 0x" << &(m[i]) << endl;
	}
	cout << endl;


	double n[5];
	cout << "Массив дробных элементов по 8 байт: n[5] " << endl;
	for (int i = 0; i < 5; i++){
		cout << "Адрес n[" << i << "] = 0x" << &(n[i]) << endl;
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

	cout << "Адрес первого элемента массива z[5] = 0x" << z << ", или " << p2 << endl;
	cout << "Значение первого элемента массива z[5]= " << *z << ", или " << *p2 << ", или " << z[0] << endl;
	cout << endl;

	cout << "Адрес второго элемента массива z[5] = 0x" << ++p2 << ", или " << &z[1] << endl;
	cout << "Значение второго элемента массива z[5]= " << *(++p2) << ", или " << z[1] << endl;
	cout << endl;

	int *pEnd = &z[4];

	cout << "Адрес последнего элемента массива z[5] = 0x" << pEnd << ", или " << &z[4] << endl;
	cout << "Значение второго элемента массива z[5]= " << *pEnd << ", или " << z[4] << endl;
	cout << endl;

	int *p3 = new int;
	*p3 = 5;

	cout << "Выделенный адрес для p3 = 0x" << p3 << endl;
	cout << "p3 = " << *p3 << endl;

	delete p3;

	_getch();
	return 0;
}