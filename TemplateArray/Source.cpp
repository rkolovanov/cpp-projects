#include <cstddef>
#include <iostream>

using namespace std;

#include <cstddef>

template <typename T>
class Array {
private:
	T* data_;
	size_t size_;

public:
	explicit Array(size_t size, const T& value = T()) : size_(size) {
		data_ = static_cast<T*>(operator new[](sizeof(T) * size_));

		for (size_t i = 0; i < size_; i++) {
			new (data_ + i) T(value);
		}
	}

	Array() {
		size_ = 0;
		data_ = nullptr;
	}

	Array(const Array& a) : size_(a.size_) {
		data_ = static_cast<T*>(operator new[](sizeof(T) * size_));

		for (size_t i = 0; i < size_; i++) {
			new (data_ + i) T(a.data_[i]);
		}
	}

	~Array() {
		for (size_t i = 0; i < size_; i++) {
			data_[i].~T();
		}

		operator delete[](data_);
	}

	Array& operator=(const Array& a) {
		if (this != &a) {
			delete[] data_;
			size_ = a.size_;
			data_ = static_cast<T*>(operator new[](sizeof(T) * size_));

			for (size_t i = 0; i < size_; i++) {
				new (data_ + i) T(a.data_[i]);
			}
		}
		return *this;
	}

	size_t size() const { return size_; }
	T& operator[](size_t i) { return data_[i]; }
	const T& operator[](size_t i) const { return data_[i]; }
};


template <typename T, typename U>
struct SameType {
	static const bool value = false;
};

template <typename X>
struct SameType<X, X> {
	static const bool value = true;
};

template <typename T, size_t N>
size_t array_size(T (&arr)[N]) {
	return N;
}


int main() {
	Array<int> arr(10, 228);
	int arr[3] = { 3, 3, 3 };



	if (SameType<int, int>::value) { cout << "h"; }
	if (SameType<int, float>::value) { cout << "h"; }

	for (size_t i = 0; i < arr.size(); i++) {
		int a = arr[i];
		cout << a << " ";
	}

	cin.get();
	return 0;
}