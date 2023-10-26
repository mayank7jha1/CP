#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int main() {

	//By Default String is of 0-based indexing but in question it is 1 based.
	string s;
	cin >> s;

	int Count_Index[N] = {0};

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		Count_Index[x - 1]++;
	}

	//Prefix Sum.
	for (int i = 1; i < s.length() / 2; i++) {
		Count_Index[i] = Count_Index[i - 1] + Count_Index[i];
	}

	for (int i = 0; i < s.length() / 2; i++) {
		if (Count_Index[i] % 2 == 1) {
			swap(s[i], s[s.length() - i - 1]);
		}
	}

	cout << s << endl;
}
