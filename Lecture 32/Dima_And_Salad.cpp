#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
int n, k;
vector<int>taste, calorie;


/*
	Solve(0,0)=max(taste[0]+Solve(1,T0-k*C0),0+Solve(1,0));



*/

int Solve(int index, int sum) {


	if (index == n) {
		/*
			If I have reached till this point that means I Have Followed a Path
			should i consider this path or not will be based on the factor
			that the sum in this of choosing " some fruits " is ZERO.
		*/

		if (sum == 0) {
			/*
				This means it is a correct path and since we already have the taste of this path stored (Because every time we are choosing a fruit we are storing its taste.)

				We will return nothing.
			*/
			return 0;
		}

		/*
			What if sum is not equal to zero?: We cannot consider this path as my answer path and its taste value should also be discarded.

			How can i Discard my taste value of this path (that has been there by choosing some fruits)?

			I will add a very small value to the up uptil taste value hence making it so small that however small  may be the other paths answer be it will become the answer.

		*/

		return -1e12;
	}

	//Choosing a Fruit
	int Option1 = taste[index] +
	              Solve(index + 1, sum + taste[index] - k * calorie[index]);

	//Not Choosing a Fruit
	int Option2 = 0 + Solve(index + 1, sum);

	int ans = max(Option2, Option1);
	return ans;
}

int32_t main() {
	cin >> n >> k;
	taste.resize(n);
	calorie.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> calorie[i];
	}

	int ans = Solve(0, 0);


	if (ans <= 0) {
		cout << "-1" << endl;
	} else {
		cout << ans << endl;
	}
}