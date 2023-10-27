#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define TT 1e18

void Solve() {
	int n;
	cin >> n;
	set<int>st;

	for (int i = 0; i < 63; i++) {
		int c = pow(2, i) - 1;
		int s = 0, e = 1e10;

		if (n == c) {
			st.insert(c + 1);
			continue;
		}

		while (s <= e) {
			int equation = 0;
			int mid = (s + e) / 2;
			equation = mid; equation *= (mid - 1); equation /= 2;
			int extra = c;

			if (extra != 0 and mid > (TT / extra)) {
				equation = TT;
			} else {
				equation = extra * mid + equation;
			}

			if (equation == n) {
				//ek answer mil gaya put teams in set and move on.
				if (mid % 2 == 1) {
					st.insert((extra + 1)*mid);
				}
				break;
			}

			if (equation > n) {
				e = mid - 1;
			}
			if (equation < n) {
				s = mid + 1;
			}
		}
	}

	if (st.size() == 0) {
		cout << "-1" << endl;
	} else {
		for (auto x : st) {
			cout << x << endl;
		}
	}
}

int32_t main() {
	Solve();
}


