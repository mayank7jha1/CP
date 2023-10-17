#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long


int32_t main() {
	int n, m;
	cin >> n >> m;


	int ans;//First day when barn becomes empty.

	if (m >= n) {
		cout << n << endl;
		return 0;
	} else {
		/*
			n>m
			We want to search for k that satify the equation.
		*/

		int s = 0;
		int e = 1e10;

		int target = n - m;

		while (s <= e) {
			int mid = (s + e) / 2;
			int d = (mid * (mid + 1)) / 2;

			if (d >= target) {
				//Above statement means that the barn becomes zero.

				/*
					Hence this could be my first day when barn
					becomes empty hence i will store this day and
					look for a even lower value that staify this
					equation as i want the min value.

				*/

				ans = mid;
				e = mid - 1;
			} else {
				/*
					This day means nothing to me and i know for sure
					I don't need to store this value and hence
					look for the answer beyond this values
					as lets say mid=10 here and we say d<target
					so we can be sure that for a lower value of mid
					the equation remains unchanged i.e. d will still be
					less than target.
				*/

				s = mid + 1;
			}
		}
	}

	cout << m + ans << endl;


}