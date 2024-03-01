#include<iostream>
#include<cstring>
using  namespace std;

int a, b;
int k;
int dp[100005];
int pre[100005];
#define int long long
#define mod 1000000007


int Flowers(int n) {

	if (n == 0) {
		//That means you have found a way to eat n flowers.
		return 1;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int Option1 = Flowers(n - 1); //This means Red Flower
	int Option2 = 0;

	if (n >= k) {
		Option2 = Flowers(n - k); //THis means White Flowers
	}

	return dp[n] = Option1 + Option2;
}

void precompute() {
	memset(dp, -1, sizeof(dp));
	pre[0] = 0;

	for (int i = 1; i <= 100005; i++) {
		pre[i] = pre[i - 1] + Flowers(i);
		pre[i] %= mod;
	}
}

int32_t main() {
	int t;
	cin >> t >> k;
	precompute();//O(n)


	while (t--) {
		int a, b;
		cin >> a >> b;

		// int ans = 0;
		// for (int i = a; i <= b; i++) {
		// 	ans += Flowers(i);
		// }

		// cout << ans << endl;

		cout << pre[b] - pre[a - 1] << endl;//O(1)
	}
}

/*
	dp[x]= Number of Ways to Eat x Flowers.
	pre[x]=Total Ways to eat from 1 to x Flowers.


	dp[3]=Number of Ways to eat 3 flowers.
	pre[3]=Total ways to eat from 1,2,3 flowers.

*/
















