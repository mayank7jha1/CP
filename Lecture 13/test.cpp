#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {
	// map<int, string>mp;
	/*map<pair<int, int>, string>mp;

	//Searching (Logn)---->Key is a pair.
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x; string y;
		cin >> x >> y;

		mp.insert({{i, x}, y});

		// mp.insert(make_pair(x, y));
	}

	for (auto x : mp) {
		cout << x.first.first << " ---> " << x.first.second << " " << x.second << endl;
	}

	cout << endl;

	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << (*it).first.first << " ---> " << (*it).first.second << " " << (*it).second << endl;
	}*/

	unordered_multimap<int, string>mp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; string y;
		cin >> x >> y;

		mp.insert({x, y});
	}


	for (auto x : mp) {
		cout << x.first << " ---> " << x.second << endl;
	}

	multiset<int>st;



}