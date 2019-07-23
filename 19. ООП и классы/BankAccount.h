#pragma once
#include <iostream>

typedef unsigned int ui;

namespace prog 
{

	class BankAccount{
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

	class Stack1 {
	private:
		int* arr;
		int max;
		int index;

	public:
		Stack1(int num, int max_elem = 1000) {
			max = max_elem;
			index = 0;

			if (num <= max) {
				arr = new int[num];
				max = num;
			} else
				std::cout << "Переполнение стека!";
		}
		~Stack1() {
			delete [] arr;
		}
		bool Push(int n) {
			if (index == max)
				return false;
			else {
				arr[index] = n;
				index++;
				return true;
			}
		}
		int Pop(void) {
			if (index < 0)
				return 0;
			else {
				return arr[--index];
			}
		}
		bool Is_empty() {
			if (index <= 0)
				return true;
			else
				return false;
		}
		bool Is_full() {
			if (index >= max)
				return true;
			else
				return false;
		}
	};
	
	struct struct_for_list
	{
		int key;
	};

	struct List
	{
		struct_for_list srct;
		List* next;
	};	



	void InitList(List **begin)
	{
		*begin = new List;
		List* end = *begin;

		(*begin)->srct.key = 0;
		(*begin)->next = NULL;

		struct_for_list a[5] = { 12, 24, 321, 404, 5543 };

		for (int i = 0; i < 5; i++)
		{
			end->next = new List;
			end = end->next;
			end->srct = a[i];
			end->next = NULL;
		}
	}

	void AddNewBegin(List **begin, const struct_for_list &NewStruct)
	{
		List *newBegin = new List;
		newBegin->srct = NewStruct;
		newBegin->next = *begin;
		*begin = newBegin;
	}

	void InsertList(List **begin, const struct_for_list &a)
	{
		List *ins = new List;
		ins->srct = a;

		if (*begin == NULL)
		{
			ins->next = NULL;
			*begin = ins;
			return;
		}

		List *t = *begin;

		if (t->srct.key >= ins->srct.key)
		{
			ins->next = t;
			*begin = ins;
			return;
		}
	}

	class Stack2 {
	private:
		List* next;
	public:
		Stack2() {}

		void Print()
		{
			List *temp_list = next;

			while (temp_list)
			{
				cout << temp_list->srct.key << " -> ";
				temp_list = temp_list->next;

			}

			cout << "NULL" << endl;
		}

		void InsertList(List **begin, const struct_for_list &a)
		{
			List *ins = new List;
			ins->srct = a;

			if (*begin == NULL)
			{
				ins->next = NULL;
				*begin = ins;
				return;
			}

			List *t = *begin;

			if (t->srct.key >= ins->srct.key)
			{
				ins->next = t;
				*begin = ins;
				return;
			}
		}
	};
}