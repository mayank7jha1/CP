#include<iostream>
#include<stack>
#include<vector>
using  namespace std;


void Solve() {
	string s;
	cin >> s;
	stack<int>st1, st2;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'b') {
			if (st1.size() > 0) {
				st1.pop();
			}

		} else if (s[i] == 'B') {
			if (st2.size() > 0) {
				st2.pop();
			}

		} else {

			if (s[i] >= 'a' and s[i] <= 'z') {
				st1.push(i);
			} else {
				st2.push(i);
			}
		}
	}

	vector<int>visited(s.length(), 0);

	while (st1.size()) {
		visited[st1.top()] = 1;
		st1.pop();
	}
	while (st2.size()) {
		visited[st2.top()] = 1;
		st2.pop();
	}

	for (int i = 0; i < s.size(); i++) {
		if (visited[i] == 1) {
			cout << s[i];
		}
	}

	cout << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		Solve();
	}
}







