#include<bits/stdc++.h>
using namespace std;
const int N = 0;


int Solve(int x, int y) {

	if (y == 0) {
		//Kya Return Karu??
		return 1;
	}

	int ans = x * Solve(x, y - 1);

	return ans;

}

//x=2,y=5,i=1
int Solve2(int x, int y, int i) {

	if (i > y) {
		//Kya Return Karu??
		return 1;
	}

	int ans = x * Solve2(x, y, i + 1);

	return ans;

}

int main() {
	int x, y;
	cin >> x >> y;


	// Iterative Way.

	int ans = 1;
	for (int i = 1; i <= y; i++) {
		ans *= x;
	}

	cout << ans << endl;


	// Recursive Way:

	// Definition 1: Solve(x,y): value of x^y.

	cout << Solve(x, y) << endl;
	// Definition 2: Solve(x,y,1): Value of x^y : x ko 1 se y bar multiply kiya hain.

	cout << Solve2(x, y, 1) << endl;

}