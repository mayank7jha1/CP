#include<bits/stdc++.h>
using namespace std;
const int N = 0;

//Time Complexity : O(log(n))
int Euclid(int a, int b) {
	if (b == 0) {
		return a;
	}

	return Euclid(b, a % b);
}

/*
	We have a Equation: ax + by = gcd(a, b) and
	Find the Solution for this Equation.

	vector has 3 elements {x,y,gcd};
	vector[0]=x;
	vector[1]=y;
	vector[2]=gcd;

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



int main() {
	int a, b;
	cin >> a >> b;
	vector<int>ans = EED(a, b);
	cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
	cout << Euclid(a, b) << endl;
}