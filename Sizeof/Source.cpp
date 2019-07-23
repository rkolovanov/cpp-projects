#include <iostream>

using namespace std;

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };

	cout << "\tSize: " << sizeof(arr) / sizeof(int) << endl;
	cout << "\tSize: " << sizeof(int*) << " " << sizeof(int&) << endl;

	cin.get();
	return 0;
}