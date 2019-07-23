#pragma once

template<typename T>
class VectorArray {
private:

	struct VectorArrayElement {
		T* value;
		VectorArrayElement* prev;
		VectorArrayElement* next;
	};

	VectorArrayElement* begin_;
	VectorArrayElement* end_;
	size_t size_;

	void clean() {
		VectorArrayElement* ptr = this->begin_;

		if (this->size_ != 0) {
			for (size_t i = 1; i != this->size_; i++) {
				ptr = ptr->next;
				delete ptr->prev->value;
				delete ptr->prev;
			}

			delete ptr->value;
			delete ptr;
		}
	}

	void set_private_variables_to_default() {
		this->begin_ = nullptr;
		this->end_ = nullptr;
		this->size_ = 0;
	}

	VectorArrayElement* get_element_ptr(size_t idx) {
		VectorArrayElement* curr = this->begin_;
		for (int i = 0; i < idx; i++)
			curr = curr->next;
		return curr;
	}

public:

	class iterator {
	private:
		VectorArrayElement* current_;

		void next_element(size_t n) {
			for (int i = 0; i < n; i++)
				current_ = current_->next;
		}

		void prev_element(size_t n) {
			for (int i = 0; i < n; i++)
				current_ = current_->prev;
		}

	public:
		iterator(iterator& obj) {
			current_ = obj.current_;
		}
		iterator(VectorArrayElement* ptr) {
			current_ = ptr;
		}
		bool operator==(VectorArrayElement* ptr) {
			return ptr == current_;
		}
		bool operator!=(VectorArrayElement* ptr) {
			return ptr != current_;
		}
		void operator=(iterator& obj) {
			current_ = obj.current_;
		}
		T& operator*() {
			return *(current_->value);
		}
		iterator& operator+(size_t n) {
			next_element(n);
			return *this;
		}
		void operator++() {
			next_element(1);
		}
		iterator& operator-(size_t n) {
			prev_element(n);
			return *this;
		}
		void operator--() {
			prev_element(1);
		}
	};

	VectorArray() {
		this->size_ = 0;
		this->begin_ = nullptr;
		this->end_ = nullptr;
	}
	VectorArray(size_t size) {
		this->size_ = size;
		this->begin_ = nullptr;
		this->end_ = nullptr;

		if (size != 0) {
			VectorArrayElement* prev = nullptr;
			VectorArrayElement* next = new VectorArrayElement;
			next->prev = nullptr;
			next->value = new T;
			this->begin_ = next;

			for (size_t i = 1; i != size; i++) {
				next->next = new VectorArrayElement;
				prev = next;
				next = prev->next;
				next->prev = prev;
				next->value = new T;
			}

			next->next = nullptr;
			this->end_ = next;
		}
	}
	VectorArray(size_t size, T value) {
		this->size_ = size;
		this->begin_ = nullptr;
		this->end_ = nullptr;

		if (size != 0) {
			VectorArrayElement* prev = nullptr;
			VectorArrayElement* next = new VectorArrayElement;
			next->prev = nullptr;
			next->value = new T;
			*(next->value) = value;
			this->begin_ = next;

			for (size_t i = 1; i != size; i++) {
				next->next = new VectorArrayElement;
				prev = next;
				next = prev->next;
				next->prev = prev;
				next->value = new T;
				*(next->value) = value;
			}

			next->next = nullptr;
			this->end_ = next;
		}
	}
	~VectorArray() {
		this->clean();
	}

	void remove_all() {
		this->clean();
		this->set_private_variables_to_default();
	}
	size_t size() {
		return this->size_;
	}
	VectorArrayElement* begin() {
		return this->begin_;
	}
	VectorArrayElement* end() {
		return this->end_;
	}
	T get(size_t idx) {
		VectorArrayElement* curr = this->begin_;
		for (int i = 0; i < idx; i++)
			curr = curr->next;
		return *(curr->value);
	}
	T& operator[](size_t idx) {
		return get_element_ptr(idx);
	}
	void push_back(T value) {
		VectorArrayElement* vae = new VectorArrayElement;
		vae->next = nullptr;
		vae->prev = this->end_;
		vae->value = new T;
		*(vae->value) = value;
		this->end_->next = vae;
		this->end_ = vae;
		this->size_++;
	}
};