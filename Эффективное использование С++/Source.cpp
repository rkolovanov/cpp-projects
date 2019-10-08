#include <iostream>


void main2();
void main3();


/* [ ������� 1 ] ������ ��������� explicit ��� �������������. */

struct Class {
	size_t size;
	explicit Class(size_t s) { size = s; }
};

void printClass(Class object) {
	std::cout << object.size << std::endl;
}

int main() {
	Class varClass(12);
	printClass(varClass);
	// Error: printClass(12);

	main2();

	std::cin.get();
	return 0;
}

/* [ ������� 2 ] ��������� const, enum, inline ������ #define */

struct Static {
	static const int global;
};

const int GLOBAL = 200;
const int Static::global = 100;

void main2() {
	std::cout << Static::global << " " << GLOBAL << std::endl;
	
	main3();
}

// ���� � Enum

class Enum {
	enum { ArraySize = 5 };
	int array[ArraySize];
};

/* [ ������� 3 ] �����, ��� ������ �����, ��������� const. ����������� mutable */

void main3() {

}