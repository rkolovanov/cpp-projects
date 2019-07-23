#include <iostream>
#include <bitset>
#include <conio.h>

using namespace std;

int main() {
	bitset<8> a(54), b(194);
	bitset<8> c(a | b);

	std::cout << a << " " << b << std::endl;
	std::cout << c;

	_getch();
	return 0;
}