#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
int x, y, GCD;
//x and y are the solution for the equation ax+by=GCD(a,b);

void EED(int a, int b) {

	//Base Condition:
	if (b == 0) {
		x = 1, y = 0, GCD = a;
		return;
	}

	EED(b, a % b);

	int current_x = y;
	int current_y = x - ((a / b) * y);

	x = current_x;
	y = current_y;

	return;

}

int MMI(int a, int m) {

	if (__gcd(a, m) != 1) {
		cout << "MMI Does not Exist " << endl;
		return 0;
	}

	EED(a, m);

	return (x + m) % m;//This MMI Will always be +ve.
}


int32_t main() {
	int a = 6;
	int m = 3;
	cout << MMI(a, m) << endl;

}