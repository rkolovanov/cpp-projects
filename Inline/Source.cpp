#include <iostream>

using namespace std;

// inline помогает оптимизировать код

inline int sum(int a, int b) {
	return a + b;
}

int main() {
	cout << sum(8, 9); // Функция подставляет прямо сюда

	return 0;
}