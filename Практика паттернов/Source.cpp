#include <iostream>
#include <vector>
#include <array>

using namespace std;

template <class T>
struct Type {
	typedef T valueType;
};

template <typename T, template <typename, typename> class Container, typename U>
Container<T, allocator<T>> convert(const Container<U, allocator<U>>& container) {
	Container<T, allocator<T>> result(container.size());

	for (int i = 0; i < container.size(); i++) {
		result[i] = (T)container[i];
	}

	return result;
}

template <template <typename, typename> class Container, typename T, typename U>
void test(const Container<T, allocator<T>>& container1, const Container<U, allocator<U>>& container2) {
	for (int i = 0; i < container1.size(); i++) {
		cout << container1[i] << " to " << container2[i] << endl;
	}
}

int main() {
	vector <double> a1(5);
	
	Type<int>::valueType a = 4;

	double v = 1.3;
	for (int i = 0; i < 5; i++, v += 0.2) {
		a1[i] = v;
	}

	vector<int> a2 = convert<int>(a1);

	cout << "Vector<double> to vector<int>:" << endl;
	test(a1, a2);

	cin.get();
	return 0;
}