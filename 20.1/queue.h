#pragma once
#include <iostream>

struct person {
	unsigned long long id;
	const char* name;
};

struct element {
	person human;
	element* next;
};

struct anwser {
	person human;
	bool success;
	const char* error;
};

class queue {
private: 
	person* array;
	unsigned int size;
	unsigned int index;

public:
	queue(int);
	bool add(person);
	anwser takeaway();
	void print();
	~queue();
};

class queue2 {
private:
	element* begin;
	unsigned int size;

public:
	queue2();
	bool add(person);
	anwser takeaway();
	void print();
	~queue2();
};


