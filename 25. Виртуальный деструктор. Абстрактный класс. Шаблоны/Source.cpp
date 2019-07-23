#include <iostream>
#include <conio.h>

using namespace std;

class Abstract {
protected:
	double radius;
public:
	virtual void draw() = 0;
};

template<typename T>
class Array {
	T* array;
	int size;
public:
	Array(int s) {
		size = s;
		array = new T[s];
	}

	T operator[](int index) {
		if (index < 0 || index > (size - 1)) {
			return -1;
		} else
			return arr[index];
	}

	virtual ~Array() {
		delete [] array;
	}
};

class A {
public:
	A() { cout << "Constructor A"; }
	virtual ~A() { cout << "Destructor A"; }
};

class B: public A {
public:
	B() { cout << "Constructor B"; }
	virtual ~B() { cout << "Destructor B"; }
};

int main() {
	setlocale(LC_ALL, "Russian");

	A* p = new B[1];

	delete [] p;

	_getch();
	return 0;
}