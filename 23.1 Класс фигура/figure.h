#pragma once
#include <iostream>
#include <cmath>

typedef unsigned short us;
typedef unsigned int ui;

class figure{
private:
	us points;
	double* lenghts;
	bool pIsSet;

public:
	figure();
	figure(us);
	figure(figure&);
	double perimeter();
	virtual void printInfo();
	us getPoints();
	double* getLenghts();
	~figure();
	
	friend std::istream& operator>>(std::istream& is, figure& f);
};

class circle: public figure {
public:
	circle();
	double yardage();
	virtual void printInfo();
	~circle();
};

class square: public figure {
public:
	square();
	double yardage();
	virtual void printInfo();
	~square();
};