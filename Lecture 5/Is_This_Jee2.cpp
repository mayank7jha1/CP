#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define PI 3.1415926535
//This is Ternary Search.

double Function(double x, double b, double c) {
	return (x * x + b * x + c) / sin(x);
}


double IsThisJEE(double b, double c) {
	double s = 0;
	double e = PI / 2;

	while (e - s > 1e-6) {

		double m1 = s + (e - s) / 3.0;
		double m2 = e - (e - s) / 3.0;

		if (Function(m1, b, c) > Function(m2, b, c)) {
			s = m1;
		} else if (Function(m1, b, c) < Function(m2, b, c)) {
			e = m2;
		} else {
			s = m1, e = m2;
		}
	}

	return s;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		double b, c;
		cin >> b >> c;
		double ans = IsThisJEE(b, c);

		cout << fixed << setprecision(10) << Function(ans, b, c) << endl;
	}
}