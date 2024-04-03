#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define int long long


/*

	dp[i][j]= Distribute j candies amoung i children.

*/

int Solve(vector<int>&a, int n, int k) {

	int dp[n + 2][k + 2];


	/*
		dp[1][k] = 1 if k <= a1;
		dp[1][k] = 0 if k > a1;
	*/

	for (int j = 0; j <= k; j++) {

		if (j <= a[1]) {
			dp[1][j] = 1;
		} else {
			dp[1][j] = 0;
		}
	}

	//dp[2][]----->dp[n][]

	for (int i = 2; i <= n; i++) {

		for (int j = 0; j <= k; j++) {

			if (j == 0) {

				dp[i][j] = dp[i - 1][j];
				dp[i][j] %= mod;

			} else {

				//O(1): Transition Time.
				int A = dp[i][j - 1] % mod;
				int B = dp[i - 1][j] % mod;
				int C;

				if ((j - a[i] - 1) >= 0) {
					C = dp[i - 1][j - a[i] - 1] % mod;
				} else {
					C = 0;
				}

				dp[i][j] = (A + B - C + mod) % mod;
			}


		}

	}

	return dp[n][k];
}

int32_t main() {
	int n, k;
	cin >> n >> k;
	//cout << n << k << endl;

	vector<int>a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << Solve(a, n, k) << endl;
}