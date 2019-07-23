#include <iostream>

constexpr double GetPi(){ return 22.0 / 7.0; }

int main() {
	std::cout << GetPi();
	std::cin.get();
	return 0;
}