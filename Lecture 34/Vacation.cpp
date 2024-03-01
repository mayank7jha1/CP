#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N], c[N];

//dp[day][activity_no]= Max happiness  if we are doing activity "activity_no" on day "day".


//Space Complexity: O(10^5*4)
//Time Complexity: O(10^5*3*1)
int vacation(int n) {
	int dp[n + 1][4] = {0};

	dp[1][1] = a[1];//Max Happiness if we are doing activity 1 on day 1.
	dp[1][2] = b[1];//Max Happiness if we are doing activity 2 on day 1.
	dp[1][3] = c[1];//Max Happiness if we are doing activity 3 on day 1.

	for (int i = 2; i <= n; i++) {

		dp[i][1] = a[i] + max(dp[i - 1][2], dp[i - 1][3]);//Max Happiness if we are doing activity 1 on day i.
		dp[i][2] = b[i] + max(dp[i - 1][1], dp[i - 1][3]);//Max Happiness if we are doing activity 2 on day i.
		dp[i][3] = c[i] + max(dp[i - 1][1], dp[i - 1][2]);//Max Happiness if we are doing activity 3 on day i.
	}

	return max({dp[n][1], dp[n][2], dp[n][3]});

	/*

		ans = max(Max Happiness if we are doing activity 1 on day n, Max Happiness if we are doing activity 2 on day n,
			          Max Happiness if we are doing activity 3 on day n);
	*/

}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	cout << vacation(n) << endl;
}