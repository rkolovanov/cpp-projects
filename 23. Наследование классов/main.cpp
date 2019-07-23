#include <iostream>
#include <conio.h>

using namespace std;

typedef unsigned int ui;


class BankAccount {
private:
	const char* ID;
	const char* name;
	ui balance;
public:
	BankAccount(void);
	BankAccount(const char*, const char* = "", ui = 0);
	void setID(const char*);
	void setName(const char*);
	void setBalance(ui);
	const char* getID(void);
	const char* getName(void);
	ui getBalance(void);
	~BankAccount();
};
void BankAccount::setID(const char* id) {
	ID = id;
}
void BankAccount::setName(const char* Name) {
	name = Name;
}
void BankAccount::setBalance(ui Balance) {
	balance = Balance;
}
const char* BankAccount::getID(void) {
	return ID;
}
const char* BankAccount::getName(void) {
	return name;
}
ui BankAccount::getBalance(void) {
	return balance;
}
BankAccount::BankAccount() {
	ID = "";
	name = "";
	balance = 0;
	cout << "CONSTRUCTOR1 DEFA \n";
}
BankAccount::BankAccount(const char* id, const char* Name, ui Balance) {
	ID = id;
	name = Name;
	balance = Balance;
	cout << "CONSTRUCTOR2 DEFA \n";
}
BankAccount::~BankAccount() {
	cout << "DESTRUCTOR DEFA \n";
}


class PremiumAccount: public BankAccount {
private:

public:
	PremiumAccount() { cout << "CONSTRUCTOR1 PREM \n";  }
	PremiumAccount(const char* id, const char* Name, ui Balance): BankAccount(id, Name, Balance) { cout << "CONSTRUCTOR2 PREM \n"; }

	friend ostream& operator<<(ostream& os, PremiumAccount& ps){
		os << "ID: " << ps.getID() << "\nИмя: " << ps.getName() << "\nБаланс: " << ps.getBalance() << endl;
		return os;
	}

	~PremiumAccount() { cout << "DESTRUCTOR PREM \n"; }
};



int main() {
	setlocale(LC_ALL, "Russian");

	PremiumAccount pa1;
	PremiumAccount pa2("#43820412314", "Rodion", 12290);

	cout << pa1;

	pa1.setID("#43820412314");
	pa1.setName("Rodion");
	pa1.setBalance(12290);

	cout << pa1;
	cout << pa2;

	_getch();
	return 0;
}