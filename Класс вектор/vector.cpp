#include "vector.h"



/*template<typename type>
vector<type>::vector(unsigned long long size): size_(size), begin_(nullptr), end_(nullptr) {
	
}*/

/*template <typename type>
vector<type>::~vector() {

}*/

/* Private Methods */
/*
template<typename type>
void vector<type>::set_private_variables_to_default() {
	this->begin_ = nullptr;
	this->end_ = nullptr;
	this->size_ = 0;
}

template<typename type>
void vector<type>::clean() {
	VectorElement<type>* ptr = this->begin_;

	while (ptr != this->end_) {
		delete ptr;
		ptr = ptr->next;
	}

	delete ptr;
}
*/
/* Public methods */
/*
template<typename type>
void vector<type>::push_back(type value) {
	if (this->size_ == 0) {
		this->begin_ = new VectorElement<type>;
		this->begin_->next = nullptr;
		this->begin_->prev = nullptr;
		this->begin_->value = value;
		this->end_ = this->begin_;
	}
}

template<typename type>
void vector<type>::set(ulli idx, type value) {
	vector<type>::iterator itr(this->begin_);
	itr + idx;
	itr.pointer_->value = value;
}

template<typename type>
type vector<type>::get(ulli idx) {
	vector<type>::iterator itr(this->begin_);
	itr + idx;
	return itr.pointer_->value;
}

template<typename type>
void vector<type>::remove_all() {
	this->clean();
	this->set_private_variables_to_default();
}

template<typename type>
void vector<type>::remove(ulli idx){
	if (idx + 1 > this->size_)
		return;

	vector<type>::iterator itr(this->begin_);
	itr + idx;
	itr.pointer_->prev.next = itr.pointer_->next;
	delete itr.pointer_;
}
*/

