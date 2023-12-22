#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
int x, y, GCD;


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

	EED(a, m);

	return (x + m) % m;//This MMI Will always be +ve.
}


int32_t main() {

	int w, d, p, n;
	cin >> n >> p >> w >> d;
	int x, y, z;
	int g = __gcd(w, d);

	if (p % g != 0) {
		cout << "-1" << endl;
		return 0;
	}

	//Lets say he wins all the matches:
	if (n * w < p) {
		cout << "-1" << endl;
		return 0;
	}


	// int p1 = p / g;
	// int d1 = d / g;
	// int w1 = w / g;

	p /= g;
	d /= g;
	w /= g;

	//Y ka Solution Nikalna hain.
	// int p2 = p1 % w;
	// int d2 = d1 % w;

	y = ((p % w) * MMI(d, w)) % w;
	x = (p - y * d) / w;

	//Third Condition for -1;
	if (x + y > n) {
		cout << "-1" << endl;
		return 0;
	}
	if (x < 0) {
		cout << "-1" << endl;
		return 0;
	}

	z = n - (x + y);

	cout << x << " " << y << " " << z << endl;
}