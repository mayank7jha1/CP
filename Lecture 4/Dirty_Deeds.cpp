#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
vector<int>f;
vector<int>s;

//What does this x and y  represent:
//Index of the pairs.
//Sequence 1 me sorting on the basis of second element in dec order.
bool compare1(int &x, int &y) {
	if (s[x] > s[y]) {
		return true;
	} else {
		return false;
	}
}

//Sequence 2 ka part: sorting on the basis of first element in asc. order
bool compare2(int &x, int &y) {
	if (f[x] < f[y]) {
		return true;
	} else {
		return false;
	}
}


int32_t main() {
	int n;
	cin >> n;
	vector<int>s1, s2;
	vector<int>ans;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		f.push_back(x);
		s.push_back(y);

		if (f[i] < s[i]) {
			s1.push_back(i);
		} else {
			s2.push_back(i);
		}
	}


	if (s1.size() > s2.size()) {
		sort(s1.begin(), s1.end(), compare1);
		ans = s1;
	} else {
		sort(s2.begin(), s2.end(), compare2);
		ans = s2;
	}

	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x + 1 << " ";
	}

}
