#pragma once

#include <ostream>
#include <cmath>

typedef long long int lli;

class fraction{
private:
	lli numerator;
	lli denominator;

public:
	fraction(lli, lli);

	void setFraction(lli, lli);
	bool reduce();
	
	friend fraction operator+(const fraction&, const fraction&);
	friend fraction operator-(const fraction&, const fraction&);
	friend fraction operator*(const fraction&, const fraction&);
	friend fraction operator/(const fraction&, const fraction&);

	friend std::ostream& operator<<(std::ostream&, fraction&);

	~fraction();
};

