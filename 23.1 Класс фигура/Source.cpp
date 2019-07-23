// Figure class by Rodion Kolovanov

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include "figure.h"

using namespace std;

void InitFigure(figure& f) {
	bool WithFile = false, save = false;
	cout << "�� ������ ����� ���������� ������ � �����? (1 - ��, 0 - ���): ";
	cin >> WithFile;

	if (WithFile) {
		ifstream fin;
		string file;

		while (!fin.is_open()) {
			cout << "������� ��� �����: ";
			cin >> file;
			fin.open(file);
		}

		fin >> f;
	} else {
		cout << "������� ���������� ����� ������ � ����� ������: ";

		cin >> f;
	}
	
	if (!WithFile) {
		cout << "������ ��������� ������ � ������ � ����? (1 - ��, 0 - ���): ";
		cin >> save;
	}

	if (save) {
		ofstream fout;
		string file;

		while (!fout.is_open()) {
			cout << "������� ��� �����: ";
			cin >> file;
			fout.open(file);
		}

		unsigned short p = f.getPoints();
		double* arr = f.getLenghts();

		fout << p << endl;
		for (int i = 1; i <= p; i++)
			fout << arr[i - 1] << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	figure f1(4);
	figure f2;

	InitFigure(f1);
	cout << "\n";
	InitFigure(f2);

	cout << "\n";
	f1.printInfo();
	cout << "\n\n";
	f2.printInfo();

	square s;
	circle c;

	InitFigure(s);
	cout << "\n";
	InitFigure(c);

	cout << "\n";
	s.printInfo();
	cout << "\n\n";
	c.printInfo();

	_getch();
	return 0;
}