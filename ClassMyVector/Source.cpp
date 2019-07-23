#include <iostream>
#include <conio.h>
#include "VectorArray.h"
#include <vector>

using namespace std;

template<typename T>
void printArr(VectorArray<T>& a) {
	for (int i = 0; i < a.size(); i++)
		cout << "arr[" << i << "] = " << a[i] << endl;
	cout << "----------" << endl;
}

int main() {
	VectorArray<int> va(3, 5);
	for (VectorArray<int>::iterator ia = va.begin(); ia != va.end(); ia+1)
		cout << *ia << ' ';
	_getch();
	return 0;
}