///////////////////////////////
///   By Rodion Kolovanov   ///
///        ���������        ///
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

		cout << "������� ��� ��������� � id = " << emp[i].id << ": ";
		getline(cin, emp[i].name);

		cout << "������� �������� ��������� � id = " << emp[i].id << ": ";
		cin >> emp[i].salary;

		int st = 3;
		do{
			if (st < 1 || st > 5)
				cout << "������! ������ ������ ���� � ��������� �� 1 �� 5!" << endl;

			cout << "������� ������ ���������(1 -  5) � id = " << emp[i].id << ": ";
			cin >> st;
		} while (st < 1 || st > 5);

		emp[i].Status = (status)st;
		cin.get();
		system("cls");
	}

	cout << "ID\t���\t�����.\t������" << endl;

	for (int i = 0; i < N; i++){
		cout << emp[i].id << "\t" << emp[i].name << "\t" << emp[i].salary << "$\t";
		switch (emp[i].Status){
			case boss: cout << "����" << endl; break;
			case calculator: cout << "���������" << endl; break;
			case secretary: cout << "����������" << endl; break;
			case IT: cout << "IT-����������" << endl; break;
			case office: cout << "������� ��������" << endl; break;
		}
	}

	_getch();
	return 0;
}

