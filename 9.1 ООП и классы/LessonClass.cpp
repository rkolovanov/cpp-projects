#include "LessonClass.h"
#include <iostream>

namespace kalich{

	Bank::Bank(unsigned int n, const std::string str, double m)
	{
		Name = str;
		Money = m;
		Number = n;
	}

	Bank::Bank()
	{
		Name = "";
		Money = 0;
		Number = 0;
	}

	Bank::~Bank(){
		std::cout << "Destructor has been started" << std::endl;
	}

	void Bank::AddMoney(double m)
	{
		Money += m;
	}

	bool Bank::SubMoney(double m)
	{
		if (m > Money)
			return false;
		else 
		{
			Money -= m;
			return true;
		}
	}

	void Bank::Show()
	{
		std::cout << "Bank account number: " << Number << "\nOwner: " << Name << "\nMoney: " << Money << "\n\n";
	}

	const Bank& Bank::BiggerMoney(const Bank& acc){
		if (Money < acc.Money)
			return acc;
		else
			return *this;
	}

	Stack::Stack(int l)
	{
		data = new Data[l];
		top = 0;
		limit = l;
	}

	Stack::~Stack()
	{
		delete[] data;
	}

	bool Stack::Push(const Data& i)
	{
		if (top == limit)
			return false;
		else
		{
			data[top] = i;
			top++;
			return true;
		}
	}

	bool Stack::Poop(Data& i){
		if (top == 0)
			return false;
		else 
		{
			i = data[--top];
			return true;
		}


	}
}
