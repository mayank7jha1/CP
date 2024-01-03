#include<bits/stdc++.h>
using namespace std;
const int N = 0;

/*
	n is the size of the nums and remainder array.
	Print the smallest x that satisfies the system
	of Linear Congruences.

	x % nums[0] = rem[0];
	x % nums[1] = rem[1];
	. . . .  Process Goes on.


	Gcd of Every nums ke array ka pair should be 1.
*/


vector<int>EED(int a, int b) {
	if (b == 0) {
		return {1, 0, a};
	}

	vector<int>result = EED(b, a % b);

	//Recursion Call is over.
	int Current_x = result[0];
	int Current_y = result[1];
	int gcd = result[2];

	int x = Current_y;
	int y = Current_x - (a / b) * Current_y;

	return {x, y, gcd};
}

//Code For MMI:

int modInverse(int a, int m) {
	vector<int>result = EED(a, m);
	int x = result[0];
	int gcd = result[2];

	if (gcd != 1) {
		cout << "-1" << endl;
	}

	int ans = (x % m + m) % m;
	return ans;
}

// Formulae: x = Summation(PP[i] * Inv[i] * Rem[i]);


int X(int* nums, int* rem, int n) {
	//Calculate the Product

	int Product = 1;
	for (int i = 0; i < n; i++) {
		Product *= nums[i];
	}

	//cout << Product << endl;


	int ans = 0;
	for (int i = 0; i < n; i++) {
		int Current_PP = Product / nums[i];
		//cout << Current_PP << endl;
		//cout << modInverse(Current_PP, nums[i]) << endl;
		ans += (Current_PP * modInverse(Current_PP, nums[i]) * rem[i]);
	}
	return ans%Product;
}

int main() {
	int n;
	cin >> n;
	int nums[n];
	int rem[n];

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		//cout << nums[i] << " ";
	}

	//cout << endl;

	for (int i = 0; i < n; i++) {
		cin >> rem[i];

		//cout << rem[i] << " ";
	}
	//cout << endl;
	cout << X(nums, rem, n) << endl;


	// cout << 257 % 7 << endl;
}
