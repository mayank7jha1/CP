#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {
	int n;
	cin >> n;

	//Unique Keys
	map<int, int>mp;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		mp.insert({x, y});
	}

	for (auto x : mp) {
		cout << x.first << " " << x.second << endl;
	}

	// mp[17] += 10;
}



/*

	Map: Ordered Map.

	KEY VALUE
	10   12
	14   19
	17   28
	14   26
	17   32



*/