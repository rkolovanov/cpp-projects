#include "kalichtasks.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

	struct struct_for_list
	{
		int key;
	};

	struct List
	{
		struct_for_list srct;
		List* next;
	};

	void Print(List *b)
	{
		List *temp_list = b;

		while (temp_list)
		{
			cout << temp_list->srct.key << " -> ";
			temp_list = temp_list->next;

		}

		cout << "NULL" << endl;
	}

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


int main()
{
	kalich::FastSetLocale();

	List* begin = NULL;
	
	InitList(&begin);
	Print(begin);

	struct_for_list kek;
	kek.key = -13;

	AddNewBegin(&begin, kek);

	Print(begin);
	
	struct_for_list kek2;
	kek2.key = -14;
	
	InsertList(&begin, kek2);
	
	Print(begin);
	
	_getch();
	return 0;
}
