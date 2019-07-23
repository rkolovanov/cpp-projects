///////////////////////////////
///   By Rodion Kolovanov   ///
///    fstream - �������    ///
///////////////////////////////

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

enum mark{ LADA = 1, MITSUBISHI, BMW, WOTSFAGEN, MERSEDES, RENO, SHKODA };

struct car{
	int id;
	mark marka;
	string model;
	int year;
	double ls;
};



int main(){
	setlocale(LC_ALL, "Russian");

	int N;

	cout << "\t*** ������� v 1.0 ***\n\n������� ���������� �����, ������� �� ������ ���������: ";
	cin >> N;

	car *cars = new car[N];

	for (int i = 0; i < N; i++){
		cars[i].id = i + 1;

		int a = 1;
		do{
			cout << "�����\t�����\n1\tLADA\n2\tMITSUBISHI\n3\tBMW\n4\tWOTSFAGEN\n5\tMERSEDES\n6\tRENO\n7\tSHKODA\n" << endl;

			if (a < 1 || a > 7)
				cout << "������! ����� ������ ���� � ��������� �� 1 �� 7!" << endl;

			cout << "������� ����� ������ � id = " << cars[i].id << ": ";
			cin >> a;
		} while (a < 1 || a > 7);

		cars[i].marka = (mark)a;
		cin.get();

		cout << "������� ������ ������ " << cars[i].marka << ": ";
		getline(cin, cars[i].model);

		cout << "������� ��� �������: ";
		cin >> cars[i].year;

		cout << "�������, ������� ���������� ��� � ���� ������: ";
		cin >> cars[i].ls;
		system("cls");
	}

	cout << "ID\t�����\t\t������\t\t���\t��" << endl;

	for (int i = 0; i < N; i++){
		cout << cars[i].id << "\t";
		switch (cars[i].marka){
		case LADA: cout << "LADA"; break;
		case MITSUBISHI: cout << "MITSUBISHI"; break;
		case BMW: cout << "BMW"; break;
		case WOTSFAGEN: cout << "WOTSFAGEN"; break;
		case MERSEDES: cout << "MERSEDES"; break;
		case SHKODA: cout << "SHKODA"; break;
		case RENO: cout << "RENO"; break;
		}
		cout << "\t\t" << cars[i].model << "\t\t" << cars[i].year << "\t" << cars[i].ls << endl;
	}

	bool save = false;
	string FileName;

	cout << "��������� ������� � ����? (1 - ��, 0 - ���)";
	cin >> save;

	ofstream fout;

	if (save == true){
		cin.get();
		cout << "������� ��� ����� ��� ������: ";
		getline(cin, FileName);

		FileName += ".txt";
		fout.open(FileName);

		fout << "ID\t�����\t\t������\t\t���\t��" << endl;
		for (int i = 0; i < N; i++){
			fout << cars[i].id << "\t";
			switch (cars[i].marka){
				case LADA: fout << "LADA"; break;
				case MITSUBISHI: fout << "MITSUBISHI"; break;
				case BMW: fout << "BMW"; break;
				case WOTSFAGEN: fout << "WOTSFAGEN"; break;
				case MERSEDES: fout << "MERSEDES"; break;
				case SHKODA: fout << "SHKODA"; break;
				case RENO: fout << "RENO"; break;
			}
			fout << "\t\t" << cars[i].model << "\t\t" << cars[i].year << "\t" << cars[i].ls << endl;
		}
	}

	_getch();

	delete[] cars;

	return 0;
}