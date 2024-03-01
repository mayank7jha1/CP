#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int K = 101;
int dp1[N][K];
int dp2[N];
int dp3[N];

//O(N)
//O(N)*O(K): O(10^5*101): O(10^7):


// dp[i][k]: Min Cost from ith stone  to (n - 1)th stone.

// dp[i]= Min Cost from ith stone to (n-1)th stone.

int Solve1(int index, vector<int>&height, int k) {

	if (index == height.size() - 1) {
		return 0;
	}

	if (dp1[index][k] != -1) {
		return dp1[index][k];
	}
	int ans = INT_MAX;

	for (int jump = 1; jump <= k; jump++) {

		int Option = INT_MAX;
		if (index + jump <= height.size() - 1) {
			Option = abs(height[index] - height[index + jump]) + Solve1(index + jump, height, k);
		}
		ans = min(ans, Option);

	}
	return dp1[index][k] = ans;
}

int Solve2(int n, vector<int>&height, int k) {
	if (n == 0) {
		return 0;
	}

	if (dp2[n] != -1) {
		return dp2[n];
	}

	int ans = INT_MAX;

	for (int jump = 1; jump <= k; jump++) {

		int Option = INT_MAX;
		if (n - jump >= 0) {
			Option = abs(height[n] - height[n - jump]) + Solve2(n - jump, height, k);
		}
		ans = min(ans, Option);

	}
	return dp2[n] = ans;
}

int Solve3(vector<int>&height, int n, int k) {
	dp3[0] = 0;

	for (int i = 1; i < n; i++) {
		dp3[i] = INT_MAX;//Min Cost from 0st stone to ith stone.

		for (int j = i - 1; j >= 0 and (i - j) <= k; j--) {
			dp3[i] = min(dp3[i], abs(height[i] - height[j]) + dp3[j]);
		}
	}
	return dp3[n - 1];//Min Cost from Oth stone to (n-1)th stone.
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int>height(n);

	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	memset(dp1, -1, sizeof(dp1));

	cout << Solve1(0, height, k) << endl;
	memset(dp2, -1, sizeof(dp2));
	cout << Solve2(n - 1, height, k) << endl;

	cout << Solve3(height, n, k) << endl;
}