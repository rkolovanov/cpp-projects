// ООП и классы

#include <iostream>
#include <conio.h>
#include <string>
#include "BankAccount.h"

using namespace std;
using prog::BankAccount;
using prog::Stack1;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");

	/* BankAccount acc1("#812773", "Rodion", 12387);

	cout << acc1.getID() << " " << acc1.getName() << " " << acc1.getBalance(); */
	
	Stack1 stack(132);

	for (int i = 0; !stack.Is_full(); i++) {
		stack.Push(i+1);
	}

	for (int i = 0; !stack.Is_empty(); i++) {
		cout << stack.Pop() << endl;
	}


	_getch();
	return 0;
}