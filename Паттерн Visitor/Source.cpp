#include <iostream>

class A;
class B;
class C;

class Visitor {
public:
	virtual void visit(A&) = 0;
	virtual void visit(B&) = 0;
	virtual void visit(C&) = 0;
	virtual ~Visitor() = default;
};

class Element {
public:
	virtual void accept(Visitor&) = 0;
	virtual ~Element() = default;
};

class A: public Element {
public:
	void accept(Visitor& v) override {
		v.visit(*this);
	}
};

class B: public Element {
public:
	void accept(Visitor& v) override {
		v.visit(*this);
	}
};

class C: public Element {
public:
	void accept(Visitor& v) override {
		v.visit(*this);
	}
};

class GetType: public Visitor {
public:
	void visit(A& e) {
		std::cout << "Class A" << std::endl;
	}
	void visit(B& e) {
		std::cout << "Class B" << std::endl;
	}
	void visit(C& e) {
		std::cout << "Class C" << std::endl;
	}
};

int main() {
	Element* elements[3] = { new A, new B, new C };

	for (auto element : elements) {
		GetType visitor;
		element->accept(visitor);
	}

	std::cin.get();
	return 0;
}