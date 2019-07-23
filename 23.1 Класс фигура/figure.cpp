#include "figure.h"
#define M_PI 3,1415926535

figure::figure(): pIsSet(false) {
	points = 0;
	lenghts = NULL;
}

figure::figure(us p): pIsSet(true)  {
	points = p;
	lenghts = new double[p];
}

figure::figure(figure& f) : pIsSet(true) {
	points = f.points;
	lenghts = new double[points];
	for (int i = 1; i <= points; i++)
		lenghts[i - 1] = f.lenghts[i - 1];
}

circle::circle(): figure(1) {}

double figure::perimeter() {
	double p = 0.0;

	if (points == 1)
		p = 2 * M_PI * lenghts[0];
	else
		for (us i = 1; i <= points; i++)
			p += lenghts[i - 1];
	
	return p;
}

void figure::printInfo() {
	std::cout << "Количество точек: " << points << std::endl;
	for (us i = 0; i < points; i++)
		std::cout << "Длина №" << i + 1 << " = " << lenghts[i] << std::endl;
	std::cout << "Периметр равен " << perimeter();
}

double circle::yardage() {
	return M_PI * pow(getLenghts()[0], 2);
}

void circle::printInfo(){
	us p = getPoints();
	double* l = getLenghts();

	std::cout << "Количество точек: " << p << std::endl;
	for (us i = 0; i < p; i++)
		std::cout << "Длина №" << i + 1 << " = " << l[i] << std::endl;
	std::cout << "Периметр равен " << perimeter();
	std::cout << "Площадь равна " << yardage();
} 

us figure::getPoints() {
	return points;
}

double* figure::getLenghts() {
	return lenghts;
}

circle::~circle() {}

figure::~figure(){
	delete [] lenghts;
}

std::istream& operator>>(std::istream& is, figure& f){
	if (!f.pIsSet) {
		is >> f.points;
		f.lenghts = new double[f.points];
		f.pIsSet = true;
	} else {
		us p;
		is >> p;

		if(p != f.points){
			std::cout << "Неверная информация для фигуры.";
			return is;
		}
	}

	for (us i = 1; i <= f.points; i++)
		is >> f.lenghts[i-1];

	return is;
}

square::square(): figure(4) {}

double square::yardage(){
	return pow(getLenghts()[0], 2);
}


void square::printInfo(){
	us p = getPoints();
	double* l = getLenghts();

	std::cout << "Количество точек: " << p << std::endl;
	for (us i = 0; i < p; i++)
		std::cout << "Длина №" << i + 1 << " = " << l[i] << std::endl;
	std::cout << "Периметр равен " << perimeter();
	std::cout << "Площадь равна " << yardage();
}

square::~square() {}
