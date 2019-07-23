///////////////////////////////
///   By Rodion Kolovanov   ///
///   Файловый ВВОД/ВЫВОД   ///
///////////////////////////////

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	int N;
	string FileName;
	bool SaveOrRead; //0 - save, 1 - read

	ofstream fout;
	ifstream fin;
	
	cout << "0 - Сохранить в файл, 1 - Считать из файла\n";
	cout << "Выберите действие: ";
	cin >> SaveOrRead;

	switch(SaveOrRead){
		case false: 
					system("cls");
					cin.get();
					cout << "Введите имя файла для записи: ";
					getline(cin, FileName);

					FileName += ".txt";
					fout.open(FileName);

					while (cin >> N)
						fout << N << endl;

					break;

		case true: 
					system("cls");
					cin.get();
					cout << "Введите имя файла для чтения: ";
					getline(cin, FileName);

					FileName += ".txt";
					fin.open(FileName);

					if (!fin.is_open()){
						cout << "Error! File is not found!";
						_getch();
						return -1;
					}
					int a[5];

					for (int i = 0; i < 5; i++){
						fin >> a[i];
						cout << "a[" << i << "] = " << a[i] << endl;
					}

					break;
	}

	_getch();
	return 0;
}