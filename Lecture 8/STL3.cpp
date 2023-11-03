
#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {
	vector<pair<int, int>>v;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}

	sort(v.begin(), v.end());

	for (auto x : v) {
		cout << x.first << " " << x.second << endl;
	}

}


//STL: ALgorithm:
//{ELEMENT BY ELEMENT  left to right}

// {first,second,third,fourth,fifth}