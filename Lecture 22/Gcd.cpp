#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long

//Time Complexity : O(min(a,b))
int Brute_Force(int a, int b) {
	int ans = 0;
	for (int i = 1; i <= min(a, b); i++) {
		if ((a % i == 0) and (b % i == 0)) {
			ans = i;
		}
	}
	return ans;
}

//Time Complexity : O(log(n))
int Optimised_Approach(int a, int b) {
	if (b == 0) {
		return a;
	}

	return Optimised_Approach(b, a % b);
}


int32_t main() {
	int a, b;
	cin >> a >> b;

	cout << Brute_Force(a, b) << endl;
	cout << Optimised_Approach(a, b) << endl;

	//Time Complexity : O(log(n))  (Best):

	cout << __gcd(a, b) << endl;
}