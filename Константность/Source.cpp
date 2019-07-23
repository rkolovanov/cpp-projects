#include <iostream>
#include <conio.h>

using namespace std;

class A {
private:
	int a;
	mutable int b = 0;
public:
	void print() const { // Константный метод, нельзя менять поля объекта. Можно менять поля с аттрибутом mutable.
		cout << "Hello";
		b++;
	}
};

int main() {
	const double Pi = 22.0 / 7.0; //Константа
	const int arr[10] = { 0 }; // Массив констант

	int var = 10; //Переменная
	int* ptr = &var; //Указатель
	const int* ptr1 = &var; //Указатель на константу
	int* const ptr2 = &var; //Константный указатель
	const int* const ptr3 = &var; //Константный указатель на константу
	
	int** ptr4 = &ptr; //Указатель на указатель на переменную
	/* Дальше все понятно */
	const int** ptr5 = &ptr;
	const int* const* ptr6 = &ptr;
	const int* const* const ptr7 = &ptr;
	int* const* ptr8 = &ptr;
	int* const* const ptr9 = &ptr;
	int** const ptr10 = &ptr;
	/* ------------------ */

	const int& a = var; // Ссылка на константу
	// int& const a = var; - Ошибка, ссылка сама по себе является константой
	// По ссылке на константу можно передавать rvalue



	_getch();
	return 0;
}