#pragma once

typedef unsigned long long int ulli;


template<typename type>
class vector {
private:
	

	//void set_private_variables_to_default();
	//void clean();
public:
	/*struct VectorElement {
		type value;
		vector<type>::VectorElement* next;
		vector<type>::VectorElement* prev;
	};*/

	ulli size_;
	//vector<type>::VectorElement* begin_;
	//vector<type>::VectorElement* end_;
	/*class iterator {
	private:
		VectorElement<type>* pointer_;
	public:
		iterator(VectorElement<type>*);
		void operator+(ulli);
		void operator-(ulli);
		~iterator();
	};*/

	vector();
	//vector(unsigned long long);
	~vector() {}
	/*1
	void push_back(type);
	void set(ulli, type);
	type get(ulli);
	void remove_all();
	void remove(ulli);
	*/
};
/*
template<typename type>
inline vector<type>::iterator::iterator(VectorElement<type>* ptr){
	this->pointer_ = ptr;
}

template<typename type>
inline void vector<type>::iterator::operator+(ulli num){
	VectorElement<type>* ptr = this->pointer_;

	for (int i = 0; i < num; i++)
		ptr = ptr->next;

	pointer_ = ptr;
}

template<typename type>
inline void vector<type>::iterator::operator-(ulli num) {
	VectorElement<type>* ptr = this->pointer_;

	for (int i = 0; i < num; i++)
		ptr = ptr->prev;

	pointer_ = ptr;
}

template<typename type>
inline vector<type>::iterator::~iterator() {
	delete this->pointer_;
}
*/