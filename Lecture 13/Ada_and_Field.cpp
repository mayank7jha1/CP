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

		/*
			sx and sy are the multiset that contain all the lengths of the segment.
			and its last value will be the the length of the largest segment.
			as in set and multiset the values are sorted in asc. order.

			x and y are two set which will store kaha kaha aapne line
			maari hain for dividing the field.

		*/

		for (int i = 0; i < q; i++) {
			int a, b;
			cin >> a >> b;

			if (a == 0) {
				/*
					Hume Vertical Line Marni hain.
					Hum x - ki baat kar rahe hain.
				*/

				if (x.find(b) != x.end()) {

					/*
						This b is already present, hume yaha par already
						pehle line mar rakhi hain toh dubara kyu maare.
					*/

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

				/*
					Hume Horizontal Line Marni hain.
					Hum y - ki baat kar rahe hain.
				*/

				if (y.find(b) != y.end()) {

					/*
						This b is already present, hume yaha par already
						pehle line mar rakhi hain toh dubara kyu maare.
					*/
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



