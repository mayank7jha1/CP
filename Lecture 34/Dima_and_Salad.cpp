#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
int n, k;
vector<int>taste, calorie;

int shift = 1e5 + 10;
int dp[101][N];//Store:

//Space Complexity: O(101*200001);
//Time Complexity: O(States * Transition Time)==O(101*200001)*O(1)= O(~10^7);

int Solve(int index, int sum) {

	if (index == n) {
		if (sum == 0) {
			return 0;
		}
		return -1e12;
	}

	//f(2,3): 120


	//Calculate karne se Pehle Check
	if (dp[index][sum + shift] != -1) {
		return dp[index][sum + shift];
	}

	//Choosing a Fruit
	int Option1 = taste[index] +
	              Solve(index + 1, sum + taste[index] - k * calorie[index]);

	//Not Choosing a Fruit
	int Option2 = 0 + Solve(index + 1, sum);

	int ans = max(Option2, Option1);

	//Return Karne se Pehle Store: Memorisation
	return dp[index][sum + shift] = ans;
}

int32_t main() {
	cin >> n >> k;
	taste.resize(n);
	calorie.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}

	memset(dp, -1, sizeof(dp));

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



