#include <iostream>

using namespace std;

// inline �������� �������������� ���

inline int sum(int a, int b) {
	return a + b;
}

int main() {
	cout << sum(8, 9); // ������� ����������� ����� ����

	return 0;
}