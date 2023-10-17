#include<bits/stdc++.h>
using namespace std;
const int N = 0;


int Noise(string &s) {

	int ans = 0;//Noise kitni hain.
	int count = 0;//Current h tak s ka count.

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 's') {
			count++;
		} else {
			ans += count;
		}
	}

	return ans;
}


bool compare(string &x, string &y) {

	//It is comparing every pair possible.
	string s = x + y;
	string t = y + x;

	if (Noise(s) > Noise(t)) {
		return true;
	} else {
		return false;
	}
}


int main() {
	int n;
	cin >> n;

	vector<string>v;

	//Sort: On the basis of noise.

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);

	string st;

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v.size(); i++) {
		st = st + v[i];
	}

	cout << Noise(st) << endl;


}



