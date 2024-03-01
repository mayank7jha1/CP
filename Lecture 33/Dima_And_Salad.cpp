#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
int n, k;
vector<int>taste, calorie;

int Solve(int index, int sum) {


	if (index == n) {
		if (sum == 0) {
			return 0;
		}
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