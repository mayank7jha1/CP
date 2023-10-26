#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define PI 3.1415926535

//This represents the slope.
double Derivative(double x, double b, double c) {

	//Basically We are concerned with the sign of this variable value.
	double value = sin(x) * (2 * x + b) - (x * x + b * x + c) * (cos(x));

	//Value would be greater than zero or less than zero.
	return value;
}

double IsThisJEE(double b, double c) {

	double s = 0;
	double e = PI / 2;
	double ans;

	int count = 0;

	while (s <= e) {

		double mid = (s + e) / 2;
		double val = Derivative(mid, b, c);

		if (val < 0) {

			s = mid;
			ans = mid;
		} else {

			e = mid;
			ans = mid;
		}

		/*	I am stopping not because i have matched the target but because i have
			completed 100 iterations that means i would have found the answer if it exists.
			And it is given in the question that answer exists.
		*/
		count++;

		if (count == 100) {
			break;
		}
	}

	/*
		You would have goten the x-coordinate of the min value now you have to put this x value in the function
		to get the minimum value.
	*/

	return ((ans * ans + b * ans + c) / sin(ans));

}



int main() {
	int t;
	cin >> t;
	while (t--) {
		double b, c;
		cin >> b >> c;

		double ans = IsThisJEE(b, c);

		cout << setprecision(11) << ans << endl;
	}

}

// f(x)=[b,c and x]
//10^-6


// log(n): Log(10 ^ 18) == We can do this in 90 computations.


//Error is upto : 10^6

//Binary Search  O(log(n))== 10^18
//90 computations