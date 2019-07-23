#include "KalichTasks.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
	kalich::FastSetLocale();

	int Money = 0;
	string WhyNeedThisprogramm = " Программа определяет, какое окончание в слове рубль надо ставить при разном количестве рублей.";
	char Again = ' ';

	while (Again != 'N' || Again != 'n'){

		cout << "Введите количество рублей: ";
		cin >> Money;

		while (Money < 0)
		{
			cout << "Ваше значение отрицательное! Введите количество рублей заного: ";
			cin >> Money;
		}

		cout << endl;
	
		if (Money >= 11 && Money <= 19)
		{
			cout << "У вас " << Money << " рублей." << WhyNeedThisprogramm << endl;
		}
		else
		{
			switch (Money % 10)
			{
				case 1: cout << "У вас " << Money << " рубль." << WhyNeedThisprogramm << endl; break;
				case 0:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9: cout << "У вас " << Money << " рублей." << WhyNeedThisprogramm << endl; break;
				case 2:
				case 3:
				case 4: cout << "У вас " << Money << " рубля." << WhyNeedThisprogramm << endl; break;
			}
		}

		cout << endl << "Повторить ввод?(Y/N): ";
		cin >> Again;

		do
		{
			if (Again == 'N' || Again == 'n' || Again == 'Y' || Again == 'y')
				break;
			else
			{
				cout << "Выш символ \'" << Again << "\' не является символом Y/N или y/n!" << " Введите символ заного(Y/N): ";
				cin >> Again;
			}

		} while (Again != 'N' || Again != 'n' || Again != 'Y' || Again != 'y');

	}

	return 0;
}