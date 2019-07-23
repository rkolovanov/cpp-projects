// Queue by Rodion Kolovanov

#include <iostream>
#include <conio.h>
#include "queue.h"

using namespace std;

int main() {
	person p1 = { 123, "Mike" };
	person p2 = { 904, "Paul" };
	person p3 = { 263, "Vasya" };
	person p4 = { 35, "Nikon" };
	person p5 = { 124233, "Vlad" };

	queue q1(10);

	q1.print();
	q1.add(p3);
	q1.add(p1);
	q1.add(p5);
	q1.print();
	q1.add(p4);
	q1.add(p2);
	q1.print();
	cout << (q1.takeaway()).human.name << " take away from queue.\n";
	cout << (q1.takeaway()).human.name << " take away from queue.\n";
	q1.print();
	cout << (q1.takeaway()).human.name << " take away from queue.\n";
	cout << (q1.takeaway()).human.name << " take away from queue.\n";
	cout << (q1.takeaway()).human.name << " take away from queue.\n";
	q1.print();
	cout << endl << endl;

	queue2 q2;

	q2.print();
	q2.add(p3);
	q2.add(p1);
	q2.add(p5);
	q2.print();
	q2.add(p4);
	q2.add(p2);
	q2.print();
	cout << (q2.takeaway()).human.name << " take away from queue.\n";
	cout << (q2.takeaway()).human.name << " take away from queue.\n";
	q2.print();
	cout << (q2.takeaway()).human.name << " take away from queue.\n";
	cout << (q2.takeaway()).human.name << " take away from queue.\n";
	cout << (q2.takeaway()).human.name << " take away from queue.\n";
	q2.print();
	cout << endl << endl;

	_getch();
	return 0;
}