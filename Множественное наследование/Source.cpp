#include <iostream>

using namespace std;

struct Unit {};
struct Mage: Unit {};
struct Human: Unit {};
struct HumanMage: Mage, Human {};

// In computer memory:
/*//////////////////////////////////////////*/
/*                                          */
/* [[[Unit] Mage] [[Unit] Human] HumanMage] */
/*                                          */
/*//////////////////////////////////////////*/

class A {};
class B: A {};
class C {
public: 
	void foo() { cout << "foo"; } 
};
class D: A, C {};
class E: B, C, D {};

// Problems: Dublicating A, C => Can't call methods of class A and C

struct Main { size_t id; };
struct M1: virtual Main {};
struct M2: virtual Main {};
struct M3: M1, M2 {};

// Main doesn't dublicating

struct Base {
	int d;
	Base(int a) { d = a; }
};
struct D1 : Base { D1() : Base(1) {} };
struct D2: Base { D2() : Base(2) {} };
struct D3: D1, D2 {};

struct Unit
{
	explicit Unit(size_t id)
		: id_(id)
	{}

	size_t id() const { return id_; }

private:
	size_t id_;
};

struct Animal : virtual Unit {
	explicit Animal(std::string const & name, size_t id) : Unit(id) {
		name_ = name;
	}
	std::string const& name() const { return name_; }

private:
	std::string name_;
};

struct Man : virtual Unit {
	explicit Man(size_t id) : Unit(id) {}
};

struct Bear : Animal {
	explicit Bear(size_t id) : Unit(id), Animal("bear", id) {}
};

struct Pig : Animal {
	explicit Pig(size_t id) : Unit(id), Animal("pig", id) {}
};

struct ManBearPig : Man, Bear, Pig {
	ManBearPig(size_t id) : Unit(id), Man(id), Bear(id), Pig(id) {}
};

int main() {
	E* e = new E;
	D3* d3 = new D3;
	Base* b1 = (D1*)d3;

	D1* d1 = (D1*)b1;
	D3* d33 = (D3*)d1;
	D2* d2 = (D2*)d33;
	Base* b2 = (Base*)d2;

	cout << b1->d << " " << b2->d;

	delete d3;
	delete e;
	cin.get();
	return 0;
}