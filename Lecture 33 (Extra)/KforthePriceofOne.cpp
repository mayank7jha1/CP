#include<iostream>
#include<algorithm>
using  namespace std;
#define int long long
int n, p, k;
int a[200005] = {0};
int dp[200005] = {0};

//dp[i]= Max Price to buy items till the ith index:
//Why I will sort: Because I want to employ the k for one offer with the maximum priced items.

int Price() {
	sort(a, a + n);


	for (int i = 0; i < n; i++) {
		if (i < k - 1) {
			//By this time you cannot avail the offer.
			dp[i] = a[i] + ((i == 0) ? 0 : dp[i - 1]);
		} else if (i == k - 1) {
			dp[i] = a[i];
		} else {
			dp[i] = dp[i - k] + a[i];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] <= p) {
			ans = i + 1;
		}
	}
	return ans;
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> p >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		cout << Price() << endl;
	}
}

