#pragma once
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323844

typedef unsigned int ui;

ui calc_seconds(ui);

class time{
private:
	ui seconds;

	
public:
	time(void);
	time(ui);
	time(ui, ui, ui);

	short getTime(char);

	time operator+(const time&) const;
	friend std::ostream& operator<<(std::ostream&, time&);

	~time();
};

struct DekartVector {
	double x;
	double y;
};

struct PolarVector {
	double lenght;
	double angle;
};

enum VectorMode {Decart, Polar};

class Vector {
private:
	DekartVector dv;
	PolarVector pv;
	VectorMode mode;
	bool forward;

public:
	Vector(double opt1, double opt2, VectorMode vm, bool f = true) {
		if (vm == Decart) {
			dv.x = opt1;
			dv.y = opt2;
			pv.lenght = sqrt(opt1 * opt1 + opt2 * opt2);
			pv.angle = atan2(opt1, opt2);
		} else {
			pv.lenght = opt1;
			pv.angle = opt2;
			dv.x = cos(opt2) * opt1;
			dv.y = sin(opt2) * opt1;
		}
		forward = f;
	}
	PolarVector getPolarVector() {
		return pv;
	}
	DekartVector getDekartVector() {
		return dv;
	}
	double operator+(){
		return pv.lenght;
	}
	Vector operator+(const Vector& v) const {
		Vector result(dv.x + v.dv.x, dv.y + v.dv.y, Decart);
		return result;
	}
	Vector operator-() const {
		return Vector(-dv.x, -dv.y, Decart);
	}
	Vector operator*(double num) const {
		Vector result(pv.lenght * num, pv.angle, Polar);
		return result;
	}
	friend Vector operator*(double num, const Vector& v1) {
		Vector result(v1.pv.lenght * num, v1.pv.angle, Polar);
		return result;
	}
	friend std::ostream& operator<<(std::ostream& os, Vector& v1) {
		os << "X = " << v1.dv.x << ", Y = " << v1.dv.y << ", Lenght = " << v1.pv.lenght << ", angle = " << v1.pv.angle * (180 / M_PI) << ".";
		return os;
	}
	~Vector() {

	}
};

