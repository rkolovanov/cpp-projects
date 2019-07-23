#pragma once

#include <ostream>

class ComplexNumber{
private:
	double a;
	double b;

public:
	ComplexNumber(double, double);

	friend ComplexNumber operator+(ComplexNumber&, ComplexNumber&);
	friend ComplexNumber operator-(ComplexNumber&, ComplexNumber&);
	friend ComplexNumber operator*(ComplexNumber&, ComplexNumber&);
	friend ComplexNumber operator/(ComplexNumber&, ComplexNumber&);

	friend std::ostream& operator<<(std::ostream&, ComplexNumber&);

	~ComplexNumber();
};

