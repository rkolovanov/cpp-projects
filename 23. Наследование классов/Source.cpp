#include <iostream>

typedef unsigned int ui;

struct struct_for_list
{
	int key;
};

struct List
{
	struct_for_list srct;
	List* next;
};


class Stack2 {
private:
	List * next;
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