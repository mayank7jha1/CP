#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {
	multiset<int>s{1, 2, 3, 3, 3, 3, 4, 6, 7, 8};

	//Lower bound of 5.

	cout << *(s.upper_bound(5)) << endl;//>
	cout << *(--s.lower_bound(5)) << endl;//>=


	s.erase(s.find(3));

	for (auto x : s) {
		cout << x << endl;
	}

}