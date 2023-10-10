#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long

int32_t main() {
	int n, m;
	cin >> n >> m;

	int a[n], b[m];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	sort(a, a + n);

	for (int i = 0; i < m; i++) {
		// int ans = upper_bound(a, a + m, b[i]) - a;

		int s = 0;
		int e = n - 1;
		int ans = n;

		while (s <= e) {
			int mid = (s + e) / 2;
			if (a[mid] > b[i]) {
				ans = mid;
				e = mid - 1;
			} else {
				s = mid + 1;
			}
		}

		cout << ans << " ";
	}
}