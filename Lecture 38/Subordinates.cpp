#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
vector<int>gr[N];


//O(n):
void Solve(int scr, int parent, vector<int>&dp) {

	int subordinates = 0;
	for (int child : gr[scr]) {
		if (child != parent) {
			Solve(child, scr, dp);
			subordinates += (1 + dp[child]);
		}
	}

	dp[scr] = subordinates;//Store is Important.
}


int main() {
	int n;
	cin >> n;
	vector<int>dp(n + 1);//No of Subordinates.

	for (int i = 2; i < n + 1; i++) {
		int x;
		cin >> x;
		gr[x].push_back(i);
		gr[i].push_back(x);
	}

	Solve(1, 0, dp);

	for (int i = 1; i < n + 1; i++) {
		cout << dp[i] << " ";
	}
}