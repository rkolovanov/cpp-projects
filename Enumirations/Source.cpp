#include <iostream>
#include <conio.h>

enum Subject {
	Math = 1,
	Physics,
	Biology,
	Russian,
	English,
	Informatics
};

int main() {
	Subject s1 = Russian;

	std::cout << s1 << std::endl;
	std::cout << Biology;

	_getch();
	return 0;
}