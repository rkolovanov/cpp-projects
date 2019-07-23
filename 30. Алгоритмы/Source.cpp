#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

template<typename ForwardIterator> void counting_sort(ForwardIterator begin,
	ForwardIterator end) {
	auto min_max = std::minmax_element(begin, end);
	if (min_max.first == min_max.second) {  // empty range
		return;
	}
	auto min = *min_max.first;
	auto max = *min_max.second;
	std::vector<unsigned> count((max - min) + 1, 0u);
	for (auto i = begin; i != end; ++i) {
		++count[*i - min];
	}
	for (auto i = min; i <= max; ++i) {
		for (auto j = 0; j < count[i - min]; ++j) {
			*begin++ = i;
		}
	}
}

using namespace std;

int main() {
	/*int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	counting_sort(begin(*a), end(*a));
	copy(begin(*a), end(*a), ostream_iterator<int>(std::cout, " "));
	*/
	int a[] = { 100, 2, 56, 200, -52, 3, 99, 33, 177, -199 };
	counting_sort(std::begin(a), std::end(a));
	copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}