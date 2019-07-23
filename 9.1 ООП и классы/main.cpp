#include <iostream>
#include <conio.h>
#include "LessonClass.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
	setlocale(LC_ALL, "Russian");

	using kalich::Bank;

	Bank user1(3748273849, "Rodion", 100000);

	
	user1.Show();

	user1.AddMoney(5000);
	user1.Show();
	user1.AddMoney(2567);
	user1.Show();
	user1.SubMoney(5000);
	user1.Show();
	if (!user1.SubMoney(750000))
		cout << "Bank account don't have enought money!" << endl;
	user1.Show();
	if (!user1.SubMoney(900000))
		cout << "Bank account don't have enought money!" << endl;
	user1.Show();

	cout << endl << endl;

	Bank a[5] = { Bank::Bank(1, "a", 474334), Bank::Bank(2, "b", 54), Bank::Bank(3, "c", 4734), Bank::Bank(4, "d", 4743342), Bank::Bank(5, "e", 4743) };

	Bank c = a[0];

	for (int i = 1; i < 5; i++){
		c = c.BiggerMoney(a[i - 1]);

	}

	c.Show();

	using kalich::Stack;

	Stack stack1(5);

	for (int i = 0; i < stack1.Limit(); i++){
		stack1.Push(i + 1);
		cout << "In stack entered " << i + 1 << endl;
	}

	int j;
	for (int i = 0; i < stack1.Limit(); i++){
		stack1.Poop(j);
		cout << "From stack poop " << j << endl;
	}

	_getch();
	return 0;
}