#include <iostream>
#include <conio.h>

using namespace std;

class IntArray {
public:
	IntArray(int size) {
		data = new int[size];
	}
	IntArray(const IntArray& obj): size(obj.size), data(new int[size]) { // Конструктор копирования
		for (int i = 0; i < size; i++)
			data[i] = obj.data[i];
	}
	IntArray& operator=(const IntArray& obj) { // Оператор присваивания
		if (this != &obj) {
			this->size = obj.size;
			delete [] data;
			this->data = new int[this->size];
			for (int i = 0; i < size; i++)
				this->data[i] = obj.data[i];
		}
		return *this;
	}
private:
	int size;
	int* data;
};

int main() {
	/* 
	IntArray a1(10);
	IntArray a2(20);
	IntArray a3 = a1; - Копирование
	a2 = a1; - Присваивание
	Ошибка времени выполнения при стандартном операторе присваивания и конструкторе копирования
	*/
	_getch();
	return 0;
}