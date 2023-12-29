#include<bits/stdc++.h>
using namespace std;
const int N = 0;


/*
	We have (a*b) % m = 1 type of equation and;
	we need to find the value of b which is MMI;

	We have transformed the above equation into this form:
	(a*b)+(k*m) = 1;

	And We are Trying to find the solution for the above
	equation using EED.

	Results;
	1. 1 <= b <= m - 1;
	2. gcd(a, m) = 1;
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




int main() {
	int a, m;
	cin >> a >> m;
	cout << modInverse(a, m) << endl;
}