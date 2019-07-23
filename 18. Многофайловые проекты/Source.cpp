// Многофайловые проекты

#include <iostream>
#include <conio.h>
#include <cmath>


using namespace std;

inline void func() {
	static int N = 1;
	cout << N;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");

	cout << "Argc = " << argc;

	for (int i = 0; i < argc; i++) {
		cout << "Argv[" << i << "] = " << argv[i];
	}



	_getch();
	return 0;
}
