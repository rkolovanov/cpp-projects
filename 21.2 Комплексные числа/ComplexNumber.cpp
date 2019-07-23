#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double A, double B){
	a = A;
	b = B;
}


ComplexNumber operator+(ComplexNumber& a, ComplexNumber& b){
	return ComplexNumber(a.a + b.a, a.b + b.b);
}

ComplexNumber operator-(ComplexNumber& a, ComplexNumber& b) {
	return ComplexNumber(a.a - b.a, a.b - b.b);
}

ComplexNumber operator*(ComplexNumber& a, ComplexNumber& b) {
	return ComplexNumber(a.a * b.a - a.b * b.b, a.b * b.a + a.a * b.b);
}

ComplexNumber operator/(ComplexNumber& a, ComplexNumber& b) {
	return ComplexNumber((a.a * b.a + a.b * b.b) / (b.a * b.a + b.b * b.b), (a.b * b.a + a.a * b.b) / (b.a * b.a + b.b * b.b));
}

std::ostream& operator<<(std::ostream& os, ComplexNumber& cn){
	os << cn.a << " + " << cn.b << "i";
	return os;
}


ComplexNumber::~ComplexNumber() {
}