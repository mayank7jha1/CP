#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long


// class Activity {
// public:
// 	int Starting_Point;
// 	int Ending_Point;
// };

//We want to Create an Array of Activity;
//Activity a[100005];

pair<int, int>p[100005];
int n;


void Solve() {
	//You Have to sort the activity data based upon the end point.

	sort(p, p + n);

	for (int i = 0; i < n; i++) {
		cout << " The Starting Point of Pair " << i << " is " << p[i].second << " ";
		cout << " and the Ending Point of is " << p[i].first << endl;

		// cout << p[i].first << " " << p[i].second << endl;
	}
}


int32_t main() {
	int t;
	cin >> t;
	while (t--) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			//cin >> a[i].Starting_Point >> a[i].Ending_Point;
			cin >> p[i].second >> p[i].first;
		}
		Solve();
	}
}




// 3 9
// 2 8
// 6 9


// p1: 9 3
// p2: 8 2
// p3: 9 6



// sort(p, p + n);

// it would have sorted the pairs ka array based upon the first value.

// p2: 8 2
// p1: 9 3
// p2: 9 6