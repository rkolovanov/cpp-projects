///////////////////////////////
///   By Rodion Kolovanov   ///
///                         ///
///////////////////////////////

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void SWAP(int &a, int &b){
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main(){
	setlocale(LC_ALL, "Russian");

	int a, b;

	cout << "¬веди а и б: ";
	cin >> a >> b;

	cout << "A = " << a << ", B = " << b << endl;
	SWAP(a, b);
	cout << "A = " << a << ", B = " << b << endl;


	_getch();
	return 0;
}