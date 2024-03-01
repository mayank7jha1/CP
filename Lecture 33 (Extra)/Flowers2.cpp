#include<iostream>
#include<cstring>
using  namespace std;


int k;
int dp[100005];


//dp[i]=Number of ways to eat the i number of flowers.

/*

	Time Complexity: O(t)*O(b-a)*O(1)

	Quatradic Time Complexity: ~~O(n^2);
*/

int Flowers(int n) {

	if (n == 0) {
		//That means you have found a way to eat n flowers.
		return 1;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int Option1 = Flowers(n - 1); //This means Red Flower
	int Option2 = 0;

	if (n >= k) {
		Option2 = Flowers(n - k); //THis means White Flowers
	}

	return dp[n] = Option1 + Option2;
}



int main() {
	int t;
	cin >> t >> k;
	while (t--) {
		int a, b;
		cin >> a >> b;
		memset(dp, -1, sizeof(dp));
		int ans = 0;
		for (int i = a; i <= b; i++) {
			ans += Flowers(i);
		}

		cout << ans << endl;
	}
}








