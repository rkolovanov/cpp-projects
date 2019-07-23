///////////////////////////////
///   By Rodion Kolovanov   ///
///                         ///
///////////////////////////////

#include <iostream>
#include <conio.h>
#include <string>
#include <cmath>

using namespace std;

#define M_PI	3.14159265358979323846

struct point{
	float x, y;
};

struct polar{
	float distance, angle;
};

int calculator(int, int, int (*p)(int, int));
int sum(int, int);
int raz(int, int);
int umn(int, int);
int del(int, int);

void show(const polar*);
polar convert(const point*);

int main(){
	setlocale(LC_ALL, "Russian");

	point p1 = { 10, 7 };
	polar p2 = convert(&p1);

	show(&p2);

	cout << "2 + 3 = " << calculator(2, 3, sum);

	_getch();
	return 0;
}

void show(const polar* p){
	cout << "Distance = " << p->distance << endl;
	cout << "Angle (C°) = " << (p->angle * 180) / M_PI << endl;
}

polar convert(const point* p){
	polar po;
	po.distance = sqrt(pow(p->x, 2) + pow(p->y, 2));
	po.angle = atan2(p->x, p->y);

	return po;
}

int sum(int a, int b){
	return a + b;
}
int raz(int a, int b){
	return a - b;
}

int umn(int a, int b){
	return a * b;
}

int del(int a, int b){
	return a / b;
}

int calculator(int a, int b, int (*p)(int, int)){
	return (*p)(a, b);
}