#include "KalichTasks.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
	kalich::FastSetLocale();

	int Money = 0;
	string WhyNeedThisprogramm = " ��������� ����������, ����� ��������� � ����� ����� ���� ������� ��� ������ ���������� ������.";
	char Again = ' ';

	while (Again != 'N' || Again != 'n'){

		cout << "������� ���������� ������: ";
		cin >> Money;

		while (Money < 0)
		{
			cout << "���� �������� �������������! ������� ���������� ������ ������: ";
			cin >> Money;
		}

		cout << endl;
	
		if (Money >= 11 && Money <= 19)
		{
			cout << "� ��� " << Money << " ������." << WhyNeedThisprogramm << endl;
		}
		else
		{
			switch (Money % 10)
			{
				case 1: cout << "� ��� " << Money << " �����." << WhyNeedThisprogramm << endl; break;
				case 0:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9: cout << "� ��� " << Money << " ������." << WhyNeedThisprogramm << endl; break;
				case 2:
				case 3:
				case 4: cout << "� ��� " << Money << " �����." << WhyNeedThisprogramm << endl; break;
			}
		}

		cout << endl << "��������� ����?(Y/N): ";
		cin >> Again;

		do
		{
			if (Again == 'N' || Again == 'n' || Again == 'Y' || Again == 'y')
				break;
			else
			{
				cout << "��� ������ \'" << Again << "\' �� �������� �������� Y/N ��� y/n!" << " ������� ������ ������(Y/N): ";
				cin >> Again;
			}

		} while (Again != 'N' || Again != 'n' || Again != 'Y' || Again != 'y');

	}

	return 0;
}