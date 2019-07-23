///////////////////////////////
///   By Rodion Kolovanov   ///
///        Структуры        ///
///////////////////////////////

#include "stdafx.h"

enum status {boss = 1, calculator = 2, secretary = 3, IT = 4, office = 5};

struct employer{
	int id;
	string name;
	double salary;
	status Status;
};

int main(){
	setlocale(LC_ALL, "Russian");

	const int N = 5;

	employer emp[N];

	for (int i = 0; i < N; i++){
		emp[i].id = i + 1;

		cout << "Введите имя работника с id = " << emp[i].id << ": ";
		getline(cin, emp[i].name);

		cout << "Введите зарплату работника с id = " << emp[i].id << ": ";
		cin >> emp[i].salary;

		int st = 3;
		do{
			if (st < 1 || st > 5)
				cout << "Ошибка! Статус должен быть в диапазоне от 1 до 5!" << endl;

			cout << "Введите статус работника(1 -  5) с id = " << emp[i].id << ": ";
			cin >> st;
		} while (st < 1 || st > 5);

		emp[i].Status = (status)st;
		cin.get();
		system("cls");
	}

	cout << "ID\tИмя\tЗарпл.\tСтатус" << endl;

	for (int i = 0; i < N; i++){
		cout << emp[i].id << "\t" << emp[i].name << "\t" << emp[i].salary << "$\t";
		switch (emp[i].Status){
			case boss: cout << "Босс" << endl; break;
			case calculator: cout << "Бухгалтер" << endl; break;
			case secretary: cout << "Сектрктарь" << endl; break;
			case IT: cout << "IT-Специалист" << endl; break;
			case office: cout << "Офисный работник" << endl; break;
		}
	}

	_getch();
	return 0;
}

