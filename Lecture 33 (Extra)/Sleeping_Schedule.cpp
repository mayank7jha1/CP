#include<iostream>
#include<cstring>
using  namespace std;
#define int long long
int n, h, l, r;
int a[100005];
int dp[2001][2001];

//Time Complexity: O(4000001)
int Solve(int sleep, int waking_time) {

	if (sleep == n) {
		return 0;
	}

	if (dp[sleep][waking_time] != -1) {
		return dp[sleep][waking_time];
	}

	int option1_waking_time = (waking_time + a[sleep]) % h;
	int option2_waking_time = (waking_time + a[sleep] - 1) % h;

	int ans1 = 0, ans2 = 0;

	if (option1_waking_time >= l and option1_waking_time <= r) {
		ans1 = 1;
	}

	if (option2_waking_time >= l and option2_waking_time <= r) {
		ans2 = 1;
	}

	int Option1 = ans1 + Solve(sleep + 1, option1_waking_time);
	int Option2 = ans2 + Solve(sleep + 1, option2_waking_time);

	return dp[sleep][waking_time] = max(Option1, Option2);

}

int32_t main() {
	cin >> n >> h >> l >> r;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << Solve(0, 0) << endl;
}




