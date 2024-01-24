#include<iostream>
#include<vector>
// #define int long long
using  namespace std;

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int>freq(26, 0);
		int mx = 0;
		for (auto x : s) {
			freq[x - 'a']++;
			mx = max(freq[x - 'a'], mx);
		}

		// if (mx * 2 >= n) {
		// 	ans = 2 * mx - n;
		// } else {
		// 	if (n % 2 == 0) {
		// 		ans = 0;
		// 	} else {
		// 		ans = 1;
		// 	}
		// }
		int ans = max((2 * mx) - n, n % 2);
		cout << ans << endl;
	}
}