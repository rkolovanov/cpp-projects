///////////////////////////////
///   By Rodion Kolovanov   ///
///                         ///
///////////////////////////////

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

template<typename type> void sorti(type a, int low, int high){
	int i = low,
	int	j = high;
	int x = a[(low + high) / 2];

	do{
		while (a[i] < x) ++i;
		while (a[j] > x) --j;
		if (i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; j--;
		}
	} while (i < j);
	if (low < j) sorti(a, low, j);
	if (i < high) sorti(a, i, high)
}

int main(){
	setlocale(LC_ALL, "Russian");

	int N;
	
	cout << "Enter size of array: ";
	cin >> N;

	int *arr = new int[N];

	for (int i = 0; i < N; i++){
		cout << "Enter a " << i + 1 << " element of array: ";
		cin >> arr[i];
	}

	cout << endl << "Введенный массив: ";

	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";

	sorti(arr, 0, (N - 1));

	cout << endl << "Отсортированный массив: ";

	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";

	delete [] arr;

	_getch();
	return 0;
}


