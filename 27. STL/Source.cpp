// STL

#include <iostream>
#include <conio.h>
#include <string>
#include <array>
#include <memory>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iterator>


using namespace std;

void Show(int a) {
	cout << a << ' ';
}

int main() {
	setlocale(LC_ALL, "Russian");

	int ar[5] = { 1, 2, 3, 4, 5 };
	string str("Hello");
	array<int, 10> arr;
	auto_ptr<string> p(new string("dddd"));
	shared_ptr<string> p2(new string("dddd2"));
	vector<int> a;

	cout << *p << " " << p.get() << " ";
	cout << *p2 << " " << p2.get() << endl;

	for (int i = 0; i < 10; i++)
		a.push_back(i + 1);

	for (vector<int>::iterator ia = a.begin(); ia != a.end(); ia++)
		cout << *ia << ' ';
	cout << endl;

	random_shuffle(a.begin(), a.end());

	for_each(a.begin(), a.end(), Show);
	cout << endl;

	sort(a.rbegin(), a.rend());
	for_each(a.begin(), a.end(), Show);
	cout << endl;

	vector<int>::reverse_iterator ia3;
	vector<int>::iterator ia2 = find(a.begin(), a.end(), 6);
	queue<int> q;
	list<int> l;

	cout << *ia2 << endl;

	set<int> s;
	set<int> s2;

	s.insert(2);
	s.insert(432);
	s.insert(43289);
	s.insert(34);
	
	s2.insert(4324234324);
	s2.insert(0);
	s2.insert(9);
	s2.insert(228337);

	set_union(s.begin(), s.end(),s2.begin(), s2.end(), inserter(s, s.begin()));

	for (auto i : s)
		cout << i << ' ';

	map<int, string> m;
	pair<int, string> par(12, "Hello");

	m.insert(par);
	m.insert(pair<int, string>(3, "Mmmmm"));

	auto res = m.find(3);

	cout << endl;
	list<int> vvv(3, 5);
	vector<int> lll(10);

	back_insert_iterator<vector<int>> bii(lll);

	lll[0] = 12;

	copy(vvv.begin(), vvv.end(), bii);

	for (auto i : lll)
		cout << i << ' ';

	_getch();
	return 0;
}