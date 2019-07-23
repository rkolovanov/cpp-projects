// Tasks by Rodion Kolovanov

#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

typedef unsigned long long int ulli;
typedef unsigned short us;

// Factorial function (realised with recursion)
void factorial(ulli* v, us N, us i = 1) {
	if (i > N)
		return;

	*v = *v * i;
	factorial(v, N, i + 1);
}

// 2 variant
ulli factorial2(int N) {
	if (N == 0)
		return 1;

	return N * factorial2(N - 1);
}

// Function find element in sorted array
int* find(int* arr, int elem, int l, int r) {
	int middle = arr[(l + r) / 2];

	if (l == (l + r) / 2) {
		if (arr[l + 1] == elem)
			return &arr[l + 1];
		else if (arr[l] == elem)
			return &arr[l];
		else
			return NULL;
	}

	if (elem == middle)
		return &arr[(l + r) / 2];
	else if (elem < middle)
		return find(arr, elem, l, middle);
	else
		return find(arr, elem, middle, r);
}

int main() {
	int N;
	cout << "Enter N: ";
	cin >> N;

	ulli* value = new ulli;
	*value = 1;

	factorial(value, N);

	cout << "Factorial " << N << "! = " << *value << ".\n";
	cout << "Factorial2 " << N << "! = " << factorial2(N) << ".\n";

	N = 40000000;
	int* arr = new int[N];

	for(int i = 0; i < N; i++)
		arr[i] = i + 1;

	int* found = find(arr, 423423, 0, N-1);
	int index = 0;

	cout << "Found element: " << *found << " in 0x" << found << ".\n";

	for (int i = 0; i <= N - 1; i++) {
		if (found == arr + i)
			index = i;
	}
	
	cout << "Index of this element in array is " << index << ".";

	_getch();
	return 0;
}