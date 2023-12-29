#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long

int32_t main() {
	// cout << "Mayank";
	int t;
	cin >> t;

	while (t--) {
		int a, b, q;
		cin >> a >> b >> q;

		//Combine[i] tells us that current i satisfy
		//the condition or not.
		int combine[4005] = {0};

		//Prefix[i] = Tells us no. of such value that satifies
		//the condition in range 0 to i.
		int prefix[4005] = {0};

		for (int i = 0; i < 4005; i++) {

			if (((i % a) % b) != ((i % b) % a)) {
				combine[i] = 1;
			}

			if (i == 0) {
				prefix[i] = combine[i];
			} else {
				prefix[i] = combine[i] + prefix[i - 1];
			}
		}

		int count1 = 0;
		int count2 = 0;

		while (q--) {

			int l, r;
			cin >> l >> r;

			//Pre[r]-Pre[l-1]=Sum(l,r)

			l--;

			//This Gives you 0-r tak ke x .
			int x = r / (a * b);
			int y = r % (a * b);
			count1 = ((x * prefix[(a * b) - 1])) + prefix[y];


			//This gives you 0-(l-1) tak ke x.
			int x1 = l / (a * b);
			int y1 = l % (a * b);
			count2 = ((x1 * prefix[(a * b) - 1])) + prefix[y1];

			cout << count1 - count2 << " ";

		}
		cout << endl;

	}
}