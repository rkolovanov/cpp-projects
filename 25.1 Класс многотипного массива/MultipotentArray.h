#pragma once

#include <iostream>

#define ARRAY_MAX_SIZE 4

typedef unsigned long long int ull_int;

template<typename T>
class MultipotentArray {
public:
	struct Element {
		T element;
		Element* next;
	};

	MultipotentArray(): _maxSize(ARRAY_MAX_SIZE) {
		_begin = nullptr;
		_size = 0;
	}

	MultipotentArray(T element): _maxSize(ARRAY_MAX_SIZE) {
		_begin = new Element;
		_begin->element = element;
		_begin->type = typeid(T);
		_begin->next = nullptr;

		_size = 1;
	}

	~MultipotentArray() {
		Element* currentElement = _begin;
		Element* nextElement = nullptr;

		while (currentElement != nullptr) {
			nextElement = currentElement->next;
			delete currentElement;
			currentElement = nextElement;
		}
	}

	bool addElement(T element) {
		if (_size >= _maxSize) {
			throw "Excetion in object of class 'MultipotentArray', in method 'addElement': _size >= _maxSize, out of range";
			return false;
		}

		if (_begin != nullptr) {
			Element* lastElement = getLastElement();
			lastElement->next = new Element;
			lastElement->next->element = element;
			lastElement->next->next = nullptr;
		}
		else {
			_begin = new Element;
			_begin->element = element;
			_begin->next = nullptr;
		}

		_size++;

		return true;
	}

	bool insertElement(T element, ull_int index = _size - 1) {
		if (_size >= _maxSize)
			return false;

		if (_size < index + 1)
			return false;

		if (index != 0) {
			Element* previousElement = getElement(index - 1);
			Element* nextElement = previousElement->next;
			previousElement->next = new Element;
			previousElement->next->next = nextElement;
			previousElement->element = element;
			previousElement->type = typeid(T);
		}
		else {
			if (_begin != nullptr) {
				Element* nextElement = _begin;
				_begin = new Element;
				_begin->element = element;
				_begin->type = typeid(T);
				_begin->next = nextElement;
			}
			else {
				_begin = new Element;
				_begin->element = element;
				_begin->type = typeid(T);
				_begin->next = nullptr;
			}
		}

		_size++;

		return true;
	}

	bool deleteElement(ull_int index) {
		if (_size < index + 1)
			return false;

		if (index > 0) {
			Element* previousElement = getElement(index - 1);
			Element* deletingElement = previousElement->next;
			previousElement->next = deletingElement->next;
			delete deletingElement;
		}
		else {
			Element* deletingElement = _begin;
			_begin = _begin->next;
			delete deletingElement;
		}

		_size--;

		return true;
	}

	Element* getLastElement() {
		Element* e = _begin;

		for (int i = 1; i < _size; i++) {
			e = e->next;
		}

		return e;
	}

	Element* getFirstElement() {
		return _begin;
	}

	Element* getElement(ull_int index) {
		if (_size < index + 1)
			return nullptr;

		Element* e = _begin;

		for (int i = 0; i < index; i++) {
			e = e->next;
		}

		return e;
	}

	ull_int getSize() {
		return _size;
	}

	T operator[](ull_int index) {
		return (getElement(index))->element;
	}

protected:
	Element* _begin;
	ull_int _size;
	const ull_int _maxSize;
};