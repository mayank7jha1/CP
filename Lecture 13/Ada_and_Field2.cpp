#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m >> q;
		multiset<int>sx, sy, x, y;

		sx.insert(n);
		sy.insert(m);

		x.insert(0);
		x.insert(n);
		y.insert(0);
		y.insert(m);

		for (int i = 0; i < q; i++) {
			int a, b;
			cin >> a >> b;

			if (a == 0) {
				if (x.find(b) != x.end()) {

					int Largest_Segment_Of_x = (*(--sx.end()));
					int Largest_Segment_Of_y = (*(--sy.end()));

					int area = Largest_Segment_Of_y * Largest_Segment_Of_x;
					cout << area << endl;
					continue;
				}

				auto small = x.lower_bound(b);
				small--;
				auto large = x.upper_bound(b);

				sx.erase(sx.find((*large) - (*small)));

				sx.insert((*large) - b);
				sx.insert(b - (*small));

				x.insert(b);

				int Largest_Segment_Of_x = (*(--sx.end()));
				int Largest_Segment_Of_y = (*(--sy.end()));

				int area = Largest_Segment_Of_y * Largest_Segment_Of_x;
				cout << area << endl;


			} else {
				if (y.find(b) != y.end()) {
					int Largest_Segment_Of_x = (*(--sx.end()));
					int Largest_Segment_Of_y = (*(--sy.end()));

					int area = Largest_Segment_Of_y * Largest_Segment_Of_x;
					cout << area << endl;
					continue;

				}


				auto small = y.lower_bound(b);
				small--;
				auto large = y.upper_bound(b);

				sy.erase(sy.find((*large) - (*small)));

				sy.insert((*large) - b);
				sy.insert(b - (*small));

				y.insert(b);

				int Largest_Segment_Of_x = (*(--sx.end()));
				int Largest_Segment_Of_y = (*(--sy.end()));

				int area = Largest_Segment_Of_y * Largest_Segment_Of_x;
				cout << area << endl;

			}
		}
	}

}



