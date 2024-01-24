#include<iostream>
using  namespace std;

void Solve() {
	char ch;
	int x;
	cin >> ch >> x;

	// string s;
	// cin >> s;

	//s[0] and s[1] and s[1] is a digit-'0'

	//Row par Iterate kar lete hain.
	for (int i = 1; i <= 8; i++) {
		if (i != x) {
			cout << ch << i << endl;
		}
	}

	//Column par Iterate kar lete hain.
	for (char i = 'a'; i <= 'h'; i++) {
		if (i != ch) {
			cout << i << x << endl;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		Solve();
	}
}