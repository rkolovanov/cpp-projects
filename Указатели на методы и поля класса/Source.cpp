#include <iostream>
#include "Header.h"

using namespace std;
typedef unsigned long long Count;

struct Unit {
	virtual Count id() { return id_; }
	virtual Count hp() { return hp_; }

	Count id_;
	Count hp_;

	Unit(Count i, Count h): id_(i), hp_(h) {}
};

typedef Count (Unit::*UnitMethod)();
typedef Count Unit::*UnitField;

void call(Unit& object, UnitMethod method) {
	cout << (object.*method)() << endl;
}

void print(Unit& object, UnitField field) {
	cout << object.*field << endl;
}

template<typename T, typename U>
bool compare(const T& a, const T& b, U(T::*mptr)() const) {
	return (a.*mptr)() > (b.*mptr)() ? true : false;
}

int main() {
	Unit u(10, 20);
	string a("ddd");
	string b("ddd");

	call(u, &Unit::id);
	call(u, &Unit::hp);
	print(u, &Unit::id_);
	print(u, &Unit::hp_);

	bar();

	compare(a, b, &string::size);

	cin.get();
	return 0;
}