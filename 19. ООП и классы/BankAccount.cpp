#include "BankAccount.h"

namespace prog {

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

	BankAccount::BankAccount(){
		ID = "";
		name = "";
		balance = 0;
	}

	BankAccount::BankAccount(const char* id, const char* Name, ui Balance) {
		ID = id;
		name = Name;
		balance = Balance;
	}


	BankAccount::~BankAccount(){
	}

}