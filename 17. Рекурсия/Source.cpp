// Рекурсия, урок 17.
// By Родион Колованов

#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>

using namespace std;

void Print(char* str, int l, int r, int level) {
	if (level == 0)
		return;

	int middle = (l + r) / 2;
	str[middle] = '|';
	Print(str, l, middle, level - 1);
	Print(str, middle, r, level - 1);
}

template<typename T>
void quickSort(T arr, int l, int r) {
	int i = l, j = r;
	int middle = arr[(i + j) / 2];

	do {
		while (middle > arr[i]) i++;
		while (middle < arr[j]) j--;

		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i < j);

	if (i < r) quickSort(arr, i, r);
	if (j > l) quickSort(arr, l, j);
}

int main() {

	srand(time(NULL));

	/* char str[66];
	str[65] = '\0';

	int min = 0, max = 64;
	str[min] = str[max] = '|';

	for(int i = 1; i < 64; i++)
		str[i] = ' ';

	cout << str << endl;

	for (int i = 1; i <= 6; i++) {
		Print(str, min, max, i);
		cout << str << endl;

		for (int i = 1; i < 64; i++)
			str[i] = ' ';
	} */

	int N = 100000000;
	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		arr[i] = rand();
	}

	double t1 = clock();
	quickSort(arr, 0, N - 1);
	double t2 = clock() - t1;

	cout << t2 / CLOCKS_PER_SEC;


	delete[] arr;
	_getch();
	return 0;
}