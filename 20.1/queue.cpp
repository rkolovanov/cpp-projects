#include "queue.h"

queue::queue(int l_size){
	size = l_size;
	array = new person[size];
	index = 0;
	person nohuman = { 0, "Free space" };
	for (int i = 0; i < size; i++)
		array[i] = nohuman;
}

bool queue::add(person p) {
	if (index >= size)
		return false;
	else {
		array[index++] = p;
		return true;
	}
}

anwser queue::takeaway() {
	anwser anw;

	if (index <= 0) {
		anw.success = false;
		anw.error = "index <= 0";
		return anw;
	}

	anw.human = array[0];

	for (int i = 0; i < index - 1; i++)
		array[i] = array[i + 1];

	person nohuman = { 0, "Free space" };
	array[--index] = nohuman;

	anw.error = "";
	anw.success = true;
	return anw;
}

void queue::print() {
	for (int i = 0; i < index; i++) {
		std::cout << array[i].id << ":" << array[i].name;

		if (i != index - 1)
			std::cout << " <--- ";
	}

	if (index == 0)
		std::cout << "Queue is empty!";
	std::cout << std::endl;
}

queue::~queue(){
	delete [] array;
	std::cout << "Memory cleaned!\n";
}

queue2::queue2(){
	begin = NULL;
	size = 0;
}

bool queue2::add(person p) {
	static element* prev_e = NULL;
	element* e = new element { p, NULL };

	if (begin == NULL)
		begin = e;
	else
		prev_e->next = e;

	size++;
	prev_e = e;
	return true;
}

anwser queue2::takeaway() {
	anwser anw;
	element* begin_e = begin;
	
	anw.human = begin_e->human;
	begin = begin_e->next;
	delete begin_e;

	size--;
	anw.error = "";
	anw.success = true;
	return anw;
}

void queue2::print() {
	if (size == 0)
		std::cout << "Queue is empty!";
	else {
		element* temp = begin;

		for (int i = 1; i <= size; i++) {
			std::cout << temp->human.id << ":" << temp->human.name;

			if (i != size)
				std::cout << " <--- ";

			temp = temp->next;
		}
	}

	std::cout << std::endl;
}

queue2::~queue2() {
	if (size > 0) {
		element* temp = begin;
		element* temp2;
		delete begin;

		for (int i = 1; i <= size; i++) {
			temp2 = temp;
			delete temp;
			temp = temp2->next;
		}
	}

	std::cout << "Memory cleaned!\n";
}
