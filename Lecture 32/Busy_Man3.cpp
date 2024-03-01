#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long


class Activity {
public:
	int Starting_Point;
	int Ending_Point;
};

//We want to Create an Array of Activity;
Activity a[100005];
int n;

bool compare(Activity a, Activity b) {

	/*
		You can ignore this.
		When Two Activities have the same end Point, I am Sorting activities in
		decreasing order based upon the starting point.
	*/

	if (a.Ending_Point == b.Ending_Point) {
		if (a.Starting_Point > b.Starting_Point) {
			return true;
		} else {
			return false;
		}
	}
	/*
		Else I am Sorting the activities based upon the end point in \
		increasing order.
	*/
	if (a.Ending_Point < b.Ending_Point) {
		return true;
	} else {
		return false;
	}
}


void Solve() {
	//You Have to sort the activity data based upon the end point.
	sort(a, a + n, compare);

	int count = 1;
	int End = a[0].Ending_Point;

	for (int i = 1; i < n; i++) {
		if (a[i].Starting_Point >= End) {
			count++;
			End = a[i].Ending_Point;
		}
	}

	cout << count << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << a[i].Starting_Point << " " << a[i].Ending_Point << endl;
	// }
}


int32_t main() {
	int t;
	cin >> t;
	while (t--) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i].Starting_Point >> a[i].Ending_Point;
		}
		Solve();
	}
}

