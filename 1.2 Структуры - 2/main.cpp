///////////////////////////////
///   By Rodion Kolovanov   ///
///      Структуры - 2      ///
///////////////////////////////

#define CS_MY 1	 //1
#define CS_MY2 2 //10
#define CS_MY3 3 //11

#include "stdafx.h"

enum status { boss = 1, calculator = 2, secretary = 3, IT = 4, office = 5 };

struct employer{
	int id;		   //4
	string name;   //32
	double salary; //8
	status Status; //4
}vasa;

union employe{
	int id;		   
	char name[80];   
	double salary; 
	status Status; 
}vasa3;

struct number{
	unsigned p1 : 1;
	unsigned p2 : 1;
	unsigned p3 : 1;
	unsigned p4 : 1;
	unsigned p5 : 1;
	unsigned p6 : 1;
	unsigned p7 : 1;
	unsigned p8 : 1;
}a;

struct window{
	unsigned style : 3; //8
	unsigned color : 3; //8
	unsigned show : 1;  //1
}b;

int main(){
	setlocale(LC_ALL, "Russian");

	employer* vasa2 = &vasa;

	vasa2->id = 1;

	cout << sizeof(employer) << endl << endl;

	vasa3.id = 2;

	cout << vasa3.id << endl;

	vasa3.salary = 22231;

	cout << vasa3.salary << endl;
	cout << vasa3.id << endl << endl;

	a.p1 = 1;
	a.p2 = 1;
	a.p3 = 1;
	a.p4 = 0;
	a.p5 = 0;
	a.p6 = 0;
	a.p7 = 0;
	a.p8 = 0;

	printf("%d", a);
	cout << endl << endl;

	b.style = CS_MY | CS_MY2;

	_getch();
	return 0;
}

