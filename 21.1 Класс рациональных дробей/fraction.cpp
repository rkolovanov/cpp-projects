#include "fraction.h"

fraction::fraction(lli n, lli d){
	numerator = n;
	denominator = d;
	this->reduce();
}


void fraction::setFraction(lli n, lli d) {
	numerator = n;
	denominator = d;
	this->reduce();
}

bool fraction::reduce() {
	lli min = abs((abs(numerator) < abs(denominator)) ? numerator : denominator);
	bool result = false;

	for (int i = 2; i <= min; i++) {
		if (abs(numerator) % i == 0 && abs(denominator) % i == 0) {
			numerator /= i;
			denominator /= i;
			this->reduce();
			result = true;
			break;
		}
	}

	return result;
}


fraction operator+(const fraction& f1, const fraction& f2){
	return fraction(f1.numerator * f2.denominator + f1.denominator * f2.numerator, f1.denominator * f2.denominator);
}

fraction operator-(const fraction& f1, const fraction& f2){
	return fraction(f2.denominator * f1.numerator - f2.numerator * f1.denominator, f1.denominator * f2.denominator);
}

fraction operator*(const fraction& f1, const fraction& f2){
	return fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
}

fraction operator/(const fraction& f1, const fraction& f2){
	return fraction(f1.numerator * f2.denominator, f1.denominator * f2.numerator);
}


std::ostream & operator<<(std::ostream& os, fraction& fr){
	os << fr.numerator << "/" << fr.denominator;
	return os;
}


fraction::~fraction(){

}
