#include<iostream>
#include<cstring>
using  namespace std;

/*

	Given n you are trying to find out the number of
	ways to that person can eat flowers.

	Recursive Approach: Time Complexity : (2^n)
*/

int k;
int dp[100005];


//dp[i]=Number of ways to eat the i number of flowers.

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
	int n;
	// int k;
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	//cout << n << k << endl;
	cout << Flowers(n) << endl;
}