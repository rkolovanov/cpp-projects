///////////////////////////////
///   By Rodion Kolovanov   ///
///                         ///
///////////////////////////////

#include <iostream>
#include <conio.h>

using namespace std;

int per();
int raz();
int raz2(int, int);
int soch();
void error();
int factorial(int);

int main(){
	setlocale(LC_ALL, "Russian");

	int type;

	cout << "Введи нужную операцию(1 - Перестановки, 2 - Размещения, 3 - Сочетания): ";
	cin >> type;

	switch (type){
		case 1: cout << per(); break;
		case 2: cout << raz(); break;
		case 3: cout << soch(); break;
		default:	error();
	}

	_getch();
	return 0;
}

int per(){
	int N;
	cout << "Введите N: ";
	cin >> N;

	return factorial(N);
}

int raz(){
	int N, K, result = 1;
	cout << "Введите N: ";
	cin >> N;
	cout << "Введите K: ";
	cin >> K;

	for (int i = N; i > K; i--){
		result *= i;
	}

	return result;
}

int soch(){
	int N, K;
	cout << "Введите N: ";
	cin >> N;
	cout << "Введите K: ";
	cin >> K;

	return factorial(N) / (factorial(K) * factorial(N - K));
}

int raz2(int N, int K){
	int result = 1;
	for (int i = N; i > K; i--){
		result *= i;
	}

	return result;
}

int factorial(int a){
	int b = 1;
	for (int i = 1; i <= a; i++)
		b = b * i;
	return b;
}

void error(){
	cout << "Ошибка! Введите верное значение!";
	_getch();
	abort();
}